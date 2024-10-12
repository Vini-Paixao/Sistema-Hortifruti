// estoque.c

#include <stdio.h>
#include <string.h>

#include "estoque.h"

// Função para adicionar produtos de teste ao estoque
void inicializarProdutos(Produto produtos[], int *totalProdutos) {
  strcpy(produtos[0].nome, "Maçã");
  strcpy(produtos[0].categoria, "Frutas");
  produtos[0].preco = 3.99;
  produtos[0].codigoBarras = 7891234567895;
  strcpy(produtos[0].fornecedor, "Hortifácil");
  strcpy(produtos[0].validade, "10/10/2024");
  produtos[0].qtdMinima = 10;

  strcpy(produtos[1].nome, "Banana");
  strcpy(produtos[1].categoria, "Frutas");
  produtos[1].preco = 2.50;
  produtos[1].codigoBarras = 7891234567896;
  strcpy(produtos[1].fornecedor, "FrutasBR");
  strcpy(produtos[1].validade, "15/11/2024");
  produtos[1].qtdMinima = 20;

  strcpy(produtos[2].nome, "Tomate");
  strcpy(produtos[2].categoria, "Legumes");
  produtos[2].preco = 4.20;
  produtos[2].codigoBarras = 7891234567897;
  strcpy(produtos[2].fornecedor, "LegumesVerde");
  strcpy(produtos[2].validade, "20/12/2024");
  produtos[2].qtdMinima = 15;

  *totalProdutos = 3; // Atualizando o total de produtos
}

void listarProdutos(Produto produtos[], int total) {
  printf("\n\033[1;34mListagem de Produtos no Estoque:\033[0m\n\n");

  if (total == 0) {
    printf("Nenhum produto cadastrado!\n");
    return;
  }

  for (int i = 0; i < total; i++) {
    printf("Produto %d:\n", i + 1);
    printf("Nome: %s\n", produtos[i].nome);
    printf("Categoria: %s\n", produtos[i].categoria);
    printf("Preço: R$ %.2f\n", produtos[i].preco);
    printf("Código de Barras: %ld\n", produtos[i].codigoBarras);
    printf("Fornecedor: %s\n", produtos[i].fornecedor[0]
                                   ? produtos[i].fornecedor
                                   : "Não informado");
    printf("Data de Validade: %s\n", produtos[i].validade);
    printf("Quantidade Mínima em Estoque: %d\n", produtos[i].qtdMinima);
    printf("\n");
  }

  printf("\033[1;34m"); // Aplicando cor azul
  printf("\nPressione ENTER para continuar...\n");
  getchar(); // Pausa até que o usuário pressione enter
  getchar(); // Captura o Enter, para evitar pular
}

void buscarProduto(Produto produtos[], int total, long codigoBarras) {
  printf("\033[1;34m"); // Cor azul
  int encontrado = 0;

  for (int i = 0; i < total; i++) {
    if (produtos[i].codigoBarras == codigoBarras) {
      encontrado = 1;
      printf("Produto encontrado:\n");
      printf("Nome: %s\n", produtos[i].nome);
      printf("Categoria: %s\n", produtos[i].categoria);
      printf("Preço: R$ %.2f\n", produtos[i].preco);
      printf("Código de Barras: %ld\n", produtos[i].codigoBarras);
      printf("Fornecedor: %s\n", produtos[i].fornecedor[0]
                                     ? produtos[i].fornecedor
                                     : "Não informado");
      printf("Data de Validade: %s\n", produtos[i].validade);
      printf("Quantidade Mínima em Estoque: %d\n", produtos[i].qtdMinima);
      break;
    }
  }

  if (!encontrado) {
    printf("Produto com código de barras %ld não encontrado!\n", codigoBarras);
  }

  printf("\033[0m"); // Resetar cor
}

void removerProduto(Produto produtos[], int *total, long codigoBarras) {
  printf("\033[1;34m"); // Cor azul
  int encontrado = 0;

  for (int i = 0; i < *total; i++) {
    if (produtos[i].codigoBarras == codigoBarras) {
      encontrado = 1;
      printf("Produto %s removido do estoque.\n", produtos[i].nome);

      // Deslocar todos os produtos seguintes para a posição anterior
      for (int j = i; j < *total - 1; j++) {
        produtos[j] = produtos[j + 1];
      }

      (*total)--; // Reduzir o número total de produtos
      break;
    }
  }

  if (!encontrado) {
    printf("Produto com código de barras %ld não encontrado!\n", codigoBarras);
  }

  printf("\033[0m"); // Resetar cor
}

void editarProduto(Produto produtos[], int total, long codigoBarras) {
  printf("\033[1;34m"); // Cor azul
  int encontrado = 0;

  for (int i = 0; i < total; i++) {
    if (produtos[i].codigoBarras == codigoBarras) {
      encontrado = 1;
      printf("Editando Produto: %s\n", produtos[i].nome);
      printf("Digite o novo nome: ");
      scanf(" %[^\n]%*c", produtos[i].nome); // Ler string com espaços
      printf("Digite a nova categoria: ");
      scanf(" %[^\n]%*c", produtos[i].categoria);
      printf("Digite o novo preço: ");
      scanf("%f", &produtos[i].preco);
      printf("Digite o novo fornecedor: ");
      scanf(" %[^\n]%*c", produtos[i].fornecedor);
      printf("Digite a nova data de validade (dd/mm/yyyy): ");
      scanf(" %[^\n]%*c", produtos[i].validade);
      printf("Digite a nova quantidade mínima em estoque: ");
      scanf("%d", &produtos[i].qtdMinima);
      printf("Produto atualizado com sucesso!\n");
      break;
    }
  }

  if (!encontrado) {
    printf("Produto com código de barras %ld não encontrado!\n", codigoBarras);
  }

  printf("\033[0m"); // Resetar cor
}
