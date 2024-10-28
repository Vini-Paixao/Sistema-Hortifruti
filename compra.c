#include "compra.h"
#include "estoque.h"
#include "utilidades.h"

#include <stdio.h>
#include <string.h>

extern Produto produtos[100];
extern int totalProdutos; // Contador do total de produtos no estoque
int totalItensCompra = 0;

void adicionar_ao_estoque(char nome[], char categoria[], float preco,
                          long codigoBarras, char fornecedor[], char validade[],
                          int qtdMinima, int quantidade, int vendidoPorQuilo)
{
  configurarConsoleUTF8();
  if (totalProdutos >= 100) // Limite de produtos
  {
    printf("Estoque cheio. Não é possível adicionar mais produtos.\n");
    return;
  }

  Produto novoProduto;

  strcpy(novoProduto.nome, nome);
  strcpy(novoProduto.categoria, categoria);
  novoProduto.preco = preco;
  novoProduto.codigoBarras = codigoBarras;
  strcpy(novoProduto.fornecedor, fornecedor);
  strcpy(novoProduto.validade, validade);
  novoProduto.qtdMinima = qtdMinima;
  novoProduto.quantidade = quantidade;
  novoProduto.vendidoPorQuilo = vendidoPorQuilo; // Definir se é por quilo ou unidade

  produtos[totalProdutos] = novoProduto; // Adiciona no array global

  totalProdutos++; // Atualiza o total de produtos

  printf("Produto '%s' adicionado ao estoque com sucesso!\n", nome);

  salvarEstoqueEmArquivo();
}

void verCarrinhoCompra()
{
  if (totalItensCompra == 0)
  {
    printf("\n\033[1;31m===== Carrinho Vazio =====\033[0m\n\n");
    printf("\033[0;36mPressione ENTER para continuar...\n");
    getchar();
    getchar();
    return;
  }

  printf("\n\n\033[1;36m===== Carrinho de Compras =====\033[0m\n\n");
  for (int i = 0; i < totalItensCompra; i++)
  {
    printf("Produto: %s\n", carrinho[i].nome);
    printf("Quantidade/Peso: %.2f\n", carrinho[i].peso > 0 ? carrinho[i].peso : (float)carrinho[i].quantidade);
    printf("Valor: R$ %.2f\n\n", carrinho[i].valorTotal);
  }
  printf("\033[0;36mPressione ENTER para continuar...\n");
  getchar();
  getchar();
}

void adicionar_ao_carrinho(char nome[], char categoria[], float preco, int quantidade, float peso,
                           char validade[], char fornecedor[], int qtdMinima)
{
  ItemCompra item;
  strcpy(item.nome, nome);
  strcpy(item.categoria, categoria);
  item.preco = preco;
  item.quantidade = quantidade;
  item.peso = peso;
  strcpy(item.validade, validade);
  strcpy(item.fornecedor, fornecedor);
  item.qtdMinima = qtdMinima;
  item.valorTotal = peso > 0 ? preco * peso : preco * quantidade;

  // Adiciona o item ao carrinho
  carrinho[totalItensCompra] = item;
  totalItensCompra++;

  printf("\nItem '%s' adicionado ao carrinho!\n", nome);
}

void finalizarCompraCompra()
{
  if (totalItensCompra == 0)
  {
    printf("\n\033[1;31m===== Carrinho Vazio =====\033[0m\n\n");
    printf("\033[0;36mPressione ENTER para continuar...\n");
    getchar();
    getchar();
    return;
  }

  char admin_login[20], admin_senha[20];

  // Solicitar a autenticação do administrador
  printf("\n\033[1;36m===== Autorização do Responsável =====\033[0m\n\n");

  printf("Digite o login: ");
  getchar(); // Limpa o buffer antes de capturar o nome
  fgets(admin_login, sizeof(admin_login), stdin);
  admin_login[strcspn(admin_login, "\n")] = 0; // Remove o '\n'

  printf("Digite a senha: ");
  getchar(); // Limpa o buffer antes de capturar o nome
  fgets(admin_senha, sizeof(admin_senha), stdin);
  admin_senha[strcspn(admin_senha, "\n")] = 0; // Remove o '\n'

  if (login_admin(admin_login, admin_senha))
  {
    printf("\n\033[1;31m===== Compra Não Autorizada! =====\033[0m\n\n");
    printf("\033[0;36mPressione ENTER para continuar...\n");
    getchar();
    return;
  }

  printf("\n\033[1;92m===== Compra Autorizada! =====\033[0m\n");

  float total = 0.0;

  printf("\n\n\033[0;36m===== Resumo da Compra =====\033[0m\n\n");
  for (int i = 0; i < totalItensCompra; i++)
  {
    printf("Produto: %s\n", carrinho[i].nome);
    printf("Categoria: %s\n", carrinho[i].categoria);
    printf("Fornecedor: %s\n", carrinho[i].fornecedor);
    printf("Quantidade/Peso: %.2f\n", carrinho[i].peso > 0 ? carrinho[i].peso : (float)carrinho[i].quantidade);
    printf("Validade: %s\n", carrinho[i].validade);
    printf("Quantidade Mínima: %d\n", carrinho[i].qtdMinima);
    printf("Valor: R$ %.2f\n\n", carrinho[i].valorTotal);
    total += carrinho[i].valorTotal;

    // Adiciona cada item ao estoque
    adicionar_ao_estoque(carrinho[i].nome, carrinho[i].categoria, carrinho[i].preco, gerar_codigo_barras(),
                         carrinho[i].fornecedor, carrinho[i].validade, carrinho[i].qtdMinima,
                         carrinho[i].quantidade, carrinho[i].peso > 0);
  }

  printf("Total da compra: R$ %.2f\n", total);

  // Salvar a compra em um arquivo
  FILE *arquivo = fopen("compras.txt", "a");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo de compras.\n");
    return;
  }

  fprintf(arquivo, "===== Novo Pedido =====\n");
  for (int i = 0; i < totalItensCompra; i++)
  {
    fprintf(arquivo, "Produto: %s\n", carrinho[i].nome);
    fprintf(arquivo, "Categoria: %s\n", carrinho[i].categoria);
    fprintf(arquivo, "Fornecedor: %s\n", carrinho[i].fornecedor);
    fprintf(arquivo, "Quantidade/Peso: %.2f\n", carrinho[i].peso > 0 ? carrinho[i].peso : (float)carrinho[i].quantidade);
    fprintf(arquivo, "Validade: %s\n", carrinho[i].validade);
    fprintf(arquivo, "Quantidade Mínima: %d\n", carrinho[i].qtdMinima);
    fprintf(arquivo, "Valor: R$ %.2f\n\n", carrinho[i].valorTotal);
  }
  fprintf(arquivo, "Total do pedido: R$ %.2f\n", total);
  fprintf(arquivo, "=====================\n\n");
  fclose(arquivo);

  totalItensCompra = 0;
  printf("\033[0;36mPressione ENTER para continuar...\n");
  getchar();
  getchar();
}

void mostrarHistoricoCompras()
{
  FILE *arquivo = fopen("compras.txt", "r");
  if (arquivo == NULL)
  {
    printf("\n\033[1;31m===== Nenhuma Compra =====\033[0m\n\n");
    printf("\033[0;36mPressione ENTER para continuar...\n");
    getchar();
    getchar();
    return;
  }

  char linha[256];
  printf("\n\n\033[1;36m===== Histórico de Compras =====\n\n");
  while (fgets(linha, sizeof(linha), arquivo))
  {
    printf("%s", linha);
  }
  fclose(arquivo);
  printf("\033[0;36mPressione ENTER para continuar...\n");
  getchar();
  getchar();
}

// Função que realiza a compra de produto
void comprar_produto()
{
  char nome[50];
  char categoria[20];
  float preco;
  int quantidade = 0; // Será usado se o produto for vendido por unidade
  float peso = 0.0;   // Será usado se o produto for vendido por quilo
  char validade[11];
  char fornecedor[30];
  int qtdMinima;
  int vendidoPorQuilo;

  configurarConsoleUTF8();

  printf("\n\033[1;36m===== Comprar Produto =====\033[0m\n\n");

  // Captura o nome do produto
  printf("Digite o nome do produto: ");
  getchar(); // Limpa o buffer antes de capturar o nome
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = 0; // Remove o '\n' capturado pelo fgets

  // Captura a categoria do produto
  printf("Digite a categoria do produto: ");
  fgets(categoria, sizeof(categoria), stdin);
  categoria[strcspn(categoria, "\n")] = 0; // Remove o '\n'

  // Captura o preço do produto
  printf("Digite o preço do produto: ");
  scanf("%f", &preco);
  limpar_buffer(); // Limpa o buffer de entrada

  // Captura o nome do fornecedor
  printf("Digite o nome do fornecedor: ");
  fgets(fornecedor, sizeof(fornecedor), stdin);
  fornecedor[strcspn(fornecedor, "\n")] = 0; // Remove o '\n'

  // Captura a data de validade
  printf("Digite a data de validade (DD/MM/AAAA): ");
  fgets(validade, sizeof(validade), stdin);
  validade[strcspn(validade, "\n")] = 0; // Remove o '\n'

  // Captura a quantidade mínima
  printf("Digite a quantidade mínima necessária em estoque: ");
  scanf("%d", &qtdMinima);
  limpar_buffer(); // Limpa o buffer de entrada

  // Perguntar se o produto será vendido por quilo ou unidade
  printf("O produto será vendido por quilo? (1 = Sim, 0 = Não): ");
  scanf("%d", &vendidoPorQuilo);
  limpar_buffer();

  // Captura o peso ou quantidade conforme o tipo de venda
  if (vendidoPorQuilo == 1)
  {
    // Venda por quilo: capturar peso
    printf("Digite o peso (em quilos) do produto a ser comprado: ");
    scanf("%f", &peso);
    limpar_buffer(); // Limpa o buffer de entrada
  }
  else
  {
    // Venda por unidade: capturar quantidade
    printf("Digite a quantidade do produto a ser comprada: ");
    scanf("%d", &quantidade);
    limpar_buffer(); // Limpa o buffer de entrada
  }

  // Adiciona o produto ao carrinho com o valor de peso ou quantidade conforme o tipo de venda
  adicionar_ao_carrinho(nome, categoria, preco, quantidade, peso, validade, fornecedor, qtdMinima);

  printf("\nItem '%s' adicionado ao carrinho!\n", nome);
  printf("\n\033[0;36mPressione ENTER para continuar...\n");
  getchar();
}