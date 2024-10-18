#include "compra.h"
#include "estoque.h"

#include <stdio.h>
#include <string.h>

extern Produto produtos[100];
extern int totalProdutos; // Contador do total de produtos no estoque

// Simula o login do administrador
int login_admin(char login[], char senha[])
{
  const char admin_login[] = "admin";
  const char admin_senha[] = "1234";

  if (strcmp(login, admin_login) == 0 && strcmp(senha, admin_senha) == 0)
  {
    return 1; // Login válido
  }
  return 0; // Login inválido
}

void adicionar_ao_estoque(char nome[], char categoria[], float preco,
                          long codigoBarras, char fornecedor[], char validade[],
                          int qtdMinima, int quantidade)
{
  if (totalProdutos >= 100)
  { // Limite de produtos
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

  produtos[totalProdutos] = novoProduto; // Adiciona no array global
  totalProdutos++;                       // Atualiza o total de produtos

  printf("Produto '%s' adicionado ao estoque com sucesso!\n", nome);
}

// Função que realiza a compra de produto
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
  char admin_login[20], admin_senha[20];

  // Captura as informações do produto
  printf("\033[1;35m"); // Aplicando cor magenta
  printf("\n===== Comprar Produto =====\n\n");
  printf("\033[0m"); // Resetar cor
  printf("Digite o nome do produto: ");
  scanf(" %[^\n]s", nome); // Aceita espaços no nome
  printf("Digite a categoria do produto: ");
  scanf(" %[^\n]s", categoria); // Aceita espaços na categoria
  printf("Digite o preço do produto: ");
  scanf("%f", &preco);
  // Gera o código de barras de forma automática
  codigoBarras = gerar_codigo_barras();
  printf("Código de barras gerado automaticamente: %ld\n", codigoBarras);

  printf("Digite o nome do fornecedor: ");
  scanf(" %[^\n]s", fornecedor); // Aceita espaços no nome do fornecedor
  printf("Digite a data de validade (DD/MM/AAAA): ");
  scanf(" %[^\n]s", validade);
  printf("Digite a quantidade mínima necessária em estoque: ");
  scanf("%d", &qtdMinima);
  printf("Digite a quantidade do produto a ser comprada: ");
  scanf("%d", &quantidade);

  printf("\033[1;35m"); // Aplicando cor magenta
  printf("\n===== Autorização do Responsável =====\n\n");
  printf("\033[0m"); // Resetar cor
  // Solicitar a autenticação do administrador
  printf("Digite o login: ");
  scanf("%s", admin_login);
  printf("Digite a senha: ");
  scanf("%s", admin_senha);
  getchar(); // Limpa o buffer de entrada

  // Verifica a autenticação do administrador
  if (login_admin(admin_login, admin_senha))
  {
    printf("\nCompra autorizada!\n");
    printf("Adicionando produto: %s\n", nome);
    printf("Total de produtos antes da compra: %d\n", totalProdutos);

    // Chamada correta da função adicionar_ao_estoque
    adicionar_ao_estoque(nome, categoria, preco, codigoBarras, fornecedor, validade, qtdMinima, quantidade);

    printf("Total de produtos após adicionar: %d\n", totalProdutos);
    printf("\033[1;35m"); // Aplicando cor magenta
    printf("\nPressione ENTER para continuar...\n");
    getchar(); // Pausa até que o usuário pressione enter
  }
  else
  {
    printf("\nAutenticação falhou. Compra não autorizada.\n");
    printf("\033[1;35m"); // Aplicando cor magenta
    printf("\nPressione ENTER para continuar...\n");
    getchar(); // Pausa até que o usuário pressione enter
  }
}