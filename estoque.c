#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "estoque.h"

Produto produtos[100]; // Array global de produtos
int totalProdutos = 0; // Contador global de produtos no estoque

long gerar_codigo_barras()
{
    int prefixo = 2970; // Define os 4 primeiros dígitos
    int sufixo = rand() % 10000; // Gera os 4 últimos dígitos aleatórios (0 a 9999)
    long codigo_barras = prefixo * 10000L + sufixo; // Combina prefixo e sufixo
    return codigo_barras;
}

// Função para adicionar produtos de teste ao estoque
void inicializarProdutos()
{
  strcpy(produtos[0].nome, "Maçã");
  strcpy(produtos[0].categoria, "Frutas");
  produtos[0].preco = 3.99;
  produtos[0].codigoBarras = gerar_codigo_barras();
  strcpy(produtos[0].fornecedor, "Hortifácil");
  strcpy(produtos[0].validade, "10/10/2024");
  produtos[0].qtdMinima = 10;
  produtos[0].quantidade = 20;

  strcpy(produtos[1].nome, "Banana");
  strcpy(produtos[1].categoria, "Frutas");
  produtos[1].preco = 2.50;
  produtos[1].codigoBarras = gerar_codigo_barras();
  strcpy(produtos[1].fornecedor, "FrutasBR");
  strcpy(produtos[1].validade, "15/11/2024");
  produtos[1].qtdMinima = 20;
  produtos[1].quantidade = 20;

  strcpy(produtos[2].nome, "Tomate");
  strcpy(produtos[2].categoria, "Legumes");
  produtos[2].preco = 4.20;
  produtos[2].codigoBarras = gerar_codigo_barras();
  strcpy(produtos[2].fornecedor, "LegumesVerde");
  strcpy(produtos[2].validade, "20/12/2024");
  produtos[2].qtdMinima = 15;
  produtos[2].quantidade = 20;

  totalProdutos = 3; // Atualizando o total de produtos
}

void listarProdutos()
{
  printf("\n\033[1;34mListagem de Produtos no Estoque -\033[0m\n\n");

  if (totalProdutos == 0)
  {
    printf("Nenhum produto cadastrado!\n");
    return;
  }

  for (int i = 0; i < totalProdutos; i++)
  {
    printf("Produto %d:\n", i + 1);
    printf("Nome: %s\n", produtos[i].nome);
    printf("Categoria: %s\n", produtos[i].categoria);
    printf("Preço: R$ %.2f\n", produtos[i].preco);
    printf("Código de Barras: %ld\n", produtos[i].codigoBarras);
    printf("Fornecedor: %s\n", produtos[i].fornecedor[0]
                                   ? produtos[i].fornecedor
                                   : "Não informado");
    printf("Data de Validade: %s\n", produtos[i].validade);
    printf("Quantidade em Estoque: %d\n", produtos[i].quantidade);
    printf("Quantidade Mínima em Estoque: %d\n", produtos[i].qtdMinima);

    // Verificar se a quantidade está abaixo do mínimo
    if (produtos[i].quantidade < produtos[i].qtdMinima)
    {
      printf("\n⚠️ Atenção: Produto abaixo da quantidade mínima!\n");
    }
    else if (produtos[i].quantidade == produtos[i].qtdMinima)
    {
      printf("\n⚠️ Atenção: Produto no limite de estoque!\n");
    }
    printf("\n");
  }

  printf("\033[1;34m"); // Aplicando cor azul
  printf("\nPressione ENTER para continuar...\n");
  getchar(); // Pausa até que o usuário pressione enter
  getchar(); // Captura o Enter, para evitar pular
}

void buscarProduto(char nome[])
{
  printf("\n\033[1;34mBusca de Produtos no Estoque -\033[0m\n\n");
  int encontrado = 0;

  for (int i = 0; i < totalProdutos; i++)
  {
    if (strcasecmp(produtos[i].nome, nome) == 0)
    {
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
      printf("Quantidade em Estoque: %d\n", produtos[i].quantidade);
      printf("Quantidade Mínima em Estoque: %d\n", produtos[i].qtdMinima);
      break;
    }
  }

  if (!encontrado)
  {
    printf("\nProduto %s o encontrado!\n", nome);
  }

  printf("\033[1;34m"); // Aplicando cor azul
  printf("\nPressione ENTER para continuar...\n");
  getchar(); // Pausa até que o usuário pressione enter
  getchar(); // Captura o Enter, para evitar pular
}

void removerProduto(char nome[])
{
  printf("\n\033[1;34mRemovendo Produtos do Estoque -\033[0m\n\n");
  int encontrado = 0;

  for (int i = 0; i < totalProdutos; i++)
  {
    if (strcasecmp(produtos[i].nome, nome) == 0)
    {
      encontrado = 1;
      printf("\033[0m");
      printf("Produto %s removido do estoque.\n", produtos[i].nome);

      // Deslocar todos os produtos seguintes para a posição anterior
      for (int j = i; j < totalProdutos - 1; j++)
      {
        produtos[j] = produtos[j + 1];
      }

      (totalProdutos)--; // Reduzir o número total de produtos
      break;
    }
  }

  if (!encontrado)
  {
    printf("Produto %s não encontrado!\n", nome);
  }

  printf("\033[1;34m"); // Aplicando cor azul
  printf("\nPressione ENTER para continuar...\n");
  getchar(); // Pausa até que o usuário pressione enter
  getchar(); // Captura o Enter, para evitar pular
}

void editarProduto(char nome[])
{
  printf("\n\033[1;34mEditando Produtos do Estoque -\033[0m\n\n");
  int encontrado = 0;

  for (int i = 0; i < totalProdutos; i++)
  {
    if (strcasecmp(produtos[i].nome, nome) == 0)
    {
      encontrado = 1;
      printf("\033[0m"); // Reset da Cor
      printf("Nome anterior: %s\n", produtos[i].nome);
      printf("Digite o novo nome: ");
      scanf(" %[^\n]%*c", produtos[i].nome);
      printf("\nCategoria anterior: %s\n", produtos[i].categoria);
      printf("Digite a nova categoria: ");
      scanf(" %[^\n]%*c", produtos[i].categoria);
      printf("\nPreço anterior: %.2f\n", produtos[i].preco);
      printf("Digite o novo preço: ");
      scanf("%f", &produtos[i].preco);
      printf("\nFornecedor anterior: %s\n", produtos[i].fornecedor);
      printf("Digite o novo fornecedor: ");
      scanf(" %[^\n]%*c", produtos[i].fornecedor);
      printf("\nValidade anterior: %s\n", produtos[i].validade);
      printf("Digite a nova data de validade (dd/mm/yyyy): ");
      scanf(" %[^\n]%*c", produtos[i].validade);
      printf("\nQuantidade mínima anterior: %d\n", produtos[i].qtdMinima);
      printf("Digite a nova quantidade mínima em estoque: ");
      scanf("%d", &produtos[i].qtdMinima);
      printf("\nQuantidade anterior: %d\n", produtos[i].quantidade);
      printf("Digite a nova quantidade em estoque: ");
      scanf("%d", &produtos[i].quantidade);
      printf("Produto atualizado com sucesso!\n");
      break;
    }
  }

  if (!encontrado)
  {
    printf("Produto %s não encontrado!\n", nome);
  }

  printf("\033[1;34m"); // Aplicando cor azul
  printf("\nPressione ENTER para continuar...\n");
  getchar(); // Pausa até que o usuário pressione enter
  getchar(); // Captura o Enter, para evitar pular
}
