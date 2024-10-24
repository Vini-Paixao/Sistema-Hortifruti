#include "compra.h"
#include "estoque.h"
#include "utilidades.h"

#include <stdio.h>
#include <string.h>

extern Produto produtos[100];
extern int totalProdutos; // Contador do total de produtos no estoque

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

  salvarEstoqueEmArquivo();

  printf("Produto '%s' adicionado ao estoque com sucesso!\n", nome);
}

// Função que realiza a compra de produto
void comprar_produto()
{
  char nome[50];
  char categoria[20];
  float preco;
  long codigoBarras;
  char fornecedor[30];
  char validade[11];
  int qtdMinima;
  int quantidade;
  int vendidoPorQuilo;
  char admin_login[20], admin_senha[20];

  configurarConsoleUTF8();

  // Captura as informações do produto
  printf("\n\033[1;35m===== Comprar Produto =====\033[0m\n\n");

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

  // Gera o código de barras de forma automática
  codigoBarras = gerar_codigo_barras();
  printf("Código de barras gerado automaticamente: %ld\n", codigoBarras);

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

  // Captura a quantidade a ser comprada
  printf("Digite a quantidade do produto a ser comprada: ");
  scanf("%d", &quantidade);
  limpar_buffer(); // Limpa o buffer de entrada

  // Perguntar se é vendido por quilo ou unidade
  printf("O produto será vendido por quilo? (1 = Sim, 0 = Não): ");
  scanf("%d", &vendidoPorQuilo);
  limpar_buffer();

  // Solicitar a autenticação do administrador
  printf("\n\033[1;35m===== Autorização do Responsável =====\033[0m\n\n");

  printf("Digite o login: ");
  fgets(admin_login, sizeof(admin_login), stdin);
  admin_login[strcspn(admin_login, "\n")] = 0; // Remove o '\n'

  printf("Digite a senha: ");
  fgets(admin_senha, sizeof(admin_senha), stdin);
  admin_senha[strcspn(admin_senha, "\n")] = 0; // Remove o '\n'

  // Verifica a autenticação do administrador
  if (login_admin(admin_login, admin_senha))
  {
    printf("\n\033[1;92m===== Compra Autorizada! =====\033[0m\n\n");

    // Chamada para adicionar ao estoque
    adicionar_ao_estoque(nome, categoria, preco, codigoBarras, fornecedor, validade, qtdMinima, quantidade, vendidoPorQuilo);

    printf("\n\033[1;35mPressione ENTER para continuar...\n");
    getchar(); // Pausa até que o usuário pressione enter
  }
  else
  {
    printf("\n\033[1;31m===== Compra Não Autorizada! =====\033[0m\n\n");

    printf("\n\033[1;35mPressione ENTER para continuar...\n");
    getchar(); // Pausa até que o usuário pressione enter
  }
}