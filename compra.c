// Incluindo dependências
#include "compra.h"
#include "estoque.h"
#include "utilidades.h"
#include <stdio.h>
#include <string.h>

extern Produto produtos[100]; // Array global de produtos
extern int totalProdutos;     // Contador global do total de produtos no estoque
int totalItensCompra = 0;     // Total de itens a comprar

// Função para adicionar ao estoque
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

// Função para visualizar o carrinho
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

    if (carrinho[i].peso > 0)
    {
      printf("Peso: %.2f kg\n", carrinho[i].peso);
    }
    else
    {
      printf("Quantidade: %d\n", carrinho[i].quantidade);
    }
    printf("Valor: R$ %.2f\n\n", carrinho[i].valorTotal);
  }

  printf("\033[0;36mPressione ENTER para continuar...\n");
  getchar();
  getchar();
}

// Função para adicionar ao carrinho
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

  printf("\n\033[1;32mItem '%s' adicionado ao carrinho!\n\033[0m", nome);
}

// Função para finalizar a compra
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
    if (carrinho[i].peso > 0)
    {
      printf("Peso: %.2f kg\n", carrinho[i].peso);
    }
    else
    {
      printf("Quantidade: %d\n", carrinho[i].quantidade);
    }
    printf("Validade: %s\n", carrinho[i].validade);
    printf("Quantidade Mínima: %d\n", carrinho[i].qtdMinima);
    printf("Valor: R$ %.2f\n\n", carrinho[i].valorTotal);
    total += carrinho[i].valorTotal;

    // Verifica se o produto já existe no estoque
    int indice_produto = encontrar_produto_no_estoque(carrinho[i].nome);

    if (indice_produto != -1)
    {
      // Se o produto existe, apenas atualiza a quantidade
      produtos[indice_produto].quantidade += carrinho[i].quantidade;
    }
    else
    {
      // Adiciona cada item ao estoque
      adicionar_ao_estoque(carrinho[i].nome, carrinho[i].categoria, carrinho[i].preco, gerar_codigo_barras(),
                           carrinho[i].fornecedor, carrinho[i].validade, carrinho[i].qtdMinima,
                           carrinho[i].quantidade, carrinho[i].peso > 0);
    }
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
    if (carrinho[i].peso > 0)
    {
      fprintf(arquivo, "Peso: %.2f kg\n", carrinho[i].peso);
    }
    else
    {
      fprintf(arquivo, "Quantidade: %d\n", carrinho[i].quantidade);
    }
    fprintf(arquivo, "Validade: %s\n", carrinho[i].validade);
    fprintf(arquivo, "Quantidade Mínima: %d\n", carrinho[i].qtdMinima);
    fprintf(arquivo, "Valor: R$ %.2f\n\n", carrinho[i].valorTotal);
  }
  fprintf(arquivo, "Total do pedido: R$ %.2f\n", total);
  fprintf(arquivo, "=====================\n\n");
  fclose(arquivo);

  salvarEstoqueEmArquivo();

  totalItensCompra = 0;
  printf("\033[0;36mPressione ENTER para continuar...\n");
  getchar();
  getchar();
}

// Visualizar as compras já realizadas
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
  printf("\n\n\033[1;36m===== Histórico de Compras =====\033[0m\n\n");
  while (fgets(linha, sizeof(linha), arquivo))
  {
    printf("%s", linha);
  }
  fclose(arquivo);
  printf("\033[0;36mPressione ENTER para continuar...\n");
  getchar();
  getchar();
}

// Função para começar a compra de um produto
void comprar_produto()
{
  configurarConsoleUTF8();
  char nome[50];
  char categoria[20];
  float preco;
  int quantidade = 0; // Será usado se o produto for vendido por unidade
  float peso = 0.0;   // Será usado se o produto for vendido por quilo
  char validade[11];
  char fornecedor[30];
  int qtdMinima;
  int vendidoPorQuilo;

  printf("\n\033[1;36m===== Comprar Produto =====\033[0m\n\n");

  // Captura o nome do produto
  printf("Digite o nome do produto: ");
  getchar(); // Limpa o buffer antes de capturar o nome
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = 0; // Remove o '\n' capturado pelo fgets

  // Verifica se o produto já existe no estoque
  int indice_produto = encontrar_produto_no_estoque(nome);

  if (indice_produto != -1)
  {
    int opcao;
    printf("\n\033[1;31m===== Produto já existe! =====\033[0m\n\n");
    printf("Deseja apenas adicionar quantidade (1) ou comprar de outro fornecedor (2)?: ");
    scanf("%d", &opcao);
    limpar_buffer();

    if (opcao == 1)
    {
      // Adicionar quantidade ao estoque existente
      int quantidade_adicional;
      if (produtos[indice_produto].vendidoPorQuilo)
      {
        printf("Digite o peso (em quilos) a adicionar ao estoque: ");
        scanf("%f", &peso);
        limpar_buffer();
        quantidade_adicional = (int)(peso * 40);
      }
      else
      {
        printf("Digite a quantidade do produto a adicionar ao estoque: ");
        scanf("%d", &quantidade_adicional);
        limpar_buffer();
      }
      // Adiciona o item ao carrinho com a quantidade extra
      adicionar_ao_carrinho(produtos[indice_produto].nome, produtos[indice_produto].categoria,
                            produtos[indice_produto].preco, quantidade_adicional, peso,
                            produtos[indice_produto].validade, produtos[indice_produto].fornecedor,
                            produtos[indice_produto].qtdMinima);

      printf("\033[0;36mPressione ENTER para continuar...\n");
      getchar();
      return; // Termina a função após adicionar a quantidade
    }
  }
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

    // Calcula a quantidade proporcional de unidades para estoque (1kg = 40 unidades)
    quantidade = (int)(peso * 10); // Calcula o valor proporcional
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

  printf("\n\033[0;36mPressione ENTER para continuar...\n");
  getchar();
}

// Função para verificar se já existe o produto no estoque
int encontrar_produto_no_estoque(const char *nome_produto)
{
  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    if (strcmp(produtos[i].nome, nome_produto) == 0)
    {
      return i; // Retorna o índice do produto no array
    }
  }
  return -1; // Produto não encontrado
}

// Função para cancelar todos os itens do carrinho de compras
void cancelarCarrinhoCompra()
{
  if (totalItensCompra == 0)
  {
    printf("\n\033[1;31m===== Carrinho já está vazio =====\033[0m\n\n");
    printf("\033[0;36mPressione ENTER para continuar...\n");
    getchar();
    getchar();
    return;
  }

  // Limpar o carrinho de compras
  totalItensCompra = 0; // Zera o contador de itens no carrinho
  printf("\n\033[1;32mCarrinho de compras cancelado com sucesso! Todos os itens foram removidos.\033[0m\n\n");

  printf("\033[0;36mPressione ENTER para continuar...\n");
  getchar();
  getchar();
}
