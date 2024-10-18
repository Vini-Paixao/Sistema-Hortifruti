#include "compra.h"

#include <stdio.h>
#include <string.h>

extern Produto produtos[100];
extern int *totalProdutos; // Contador do total de produtos no estoque

// Simula o login do administrador
int login_admin(char login[], char senha[]) {
  const char admin_login[] = "admin";
  const char admin_senha[] = "1234";

  if (strcmp(login, admin_login) == 0 && strcmp(senha, admin_senha) == 0) {
    return 1; // Login válido
  }
  return 0; // Login inválido
}

void adicionar_ao_estoque(Produto produtos[], int *totalProdutos, char nome[],
                          char categoria[], float preco, long codigoBarras,
                          char fornecedor[], char validade[], int qtdMinima,
                          int quantidade) {
  if (*totalProdutos >=
      100) { // Supondo que o limite de produtos no estoque seja 100
    printf("Estoque cheio. Não é possível adicionar mais produtos.\n");
    return;
  }

  Produto novoProduto;

  // Copia as informações fornecidas para o novo produto
  strcpy(novoProduto.nome, nome);
  strcpy(novoProduto.categoria, categoria);
  novoProduto.preco = preco;
  novoProduto.codigoBarras = codigoBarras;
  strcpy(novoProduto.fornecedor, fornecedor);
  strcpy(novoProduto.validade, validade);
  novoProduto.qtdMinima = qtdMinima;

  // Adiciona o novo produto ao array de produtos
  produtos[*totalProdutos] = novoProduto;

  // Atualiza o total de produtos
  *totalProdutos += 1;

  printf("Produto '%s' adicionado ao estoque com sucesso!\n", nome);
}

// Função que realiza a compra de produto
void comprar_produto() {
  Produto produtos[100];
  int totalProdutos;
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
  printf("===== Comprar Produto =====\n");
  printf("Digite o nome do produto: ");
  scanf(" %[^\n]s", nome); // Aceita espaços no nome
  printf("Digite a categoria do produto: ");
  scanf(" %[^\n]s", categoria); // Aceita espaços na categoria
  printf("Digite o preço do produto: ");
  scanf("%f", &preco);
  printf("Digite o código de barras: ");
  scanf("%ld", &codigoBarras);
  printf("Digite o nome do fornecedor: ");
  scanf(" %[^\n]s", fornecedor); // Aceita espaços no nome do fornecedor
  printf("Digite a data de validade (DD/MM/AAAA): ");
  scanf(" %[^\n]s", validade);
  printf("Digite a quantidade mínima necessária em estoque: ");
  scanf("%d", &qtdMinima);
  printf("Digite a quantidade do produto a ser comprada: ");
  scanf("%d", &quantidade);

  // Solicitar a autenticação do administrador
  printf("Digite o login do administrador: ");
  scanf("%s", admin_login);
  printf("Digite a senha do administrador: ");
  scanf("%s", admin_senha);

  // Verifica a autenticação do administrador
  if (login_admin(admin_login, admin_senha)) {
    printf("Compra autorizada!\n");
    // Adiciona o produto ao estoque passando todas as informações
    adicionar_ao_estoque(produtos, &totalProdutos, nome, categoria, preco,
                         codigoBarras, fornecedor, validade, qtdMinima,
                         quantidade);
  } else {
    printf("Autenticação falhou. Compra não autorizada.\n");
  }
}