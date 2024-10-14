#include "menus.h"   // Incluímos o cabeçalho menus.h
#include "estoque.h" // Incluímos estoque.h para usar Produto
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparTela() {
#ifdef _WIN32
  system("cls"); // Comando para Windows
#else
  system("clear"); // Comando para Linux/MacOS
#endif
}

// Definição da função menuPrincipal
void menuPrincipal(char titulo[]) {
  printf("\033[1;32m"); // Aplicando cor verde
  int largura = 32;
  int paddingTitulo = (largura - strlen(titulo)) / 2;

  printf("\n\t╔");
  for (int i = 0; i < largura; i++)
    printf("═");
  printf("╗");

  printf("\n\t║");
  for (int i = 0; i < paddingTitulo; i++)
    printf(" ");
  printf("%s", titulo);
  for (int i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
    printf(" ");
  printf("║");

  printf("\n\t╠");
  for (int i = 0; i < largura; i++)
    printf("═");
  printf("╣");
  printf("\n\t║     1 - Gestão de Estoque      ║");
  printf("\n\t║     2 - Sistema do Caixa       ║");
  printf("\n\t║     3 - Sistema de Compras     ║");
  printf("\n\t║     4 - Encerrar               ║");

  printf("\n\t╚");
  for (int i = 0; i < largura; i++)
    printf("═");
  printf("╝");
  printf("\033[0m"); // Resetar cor
}

// Definição da função menuEstoque
void menuEstoque(char titulo[], Produto produtos[], int *totalProdutos) {
  printf("\033[1;34m"); // Aplicando cor azul
  int opcao = 0;
  char nome[50];

  while (opcao != 5) {
    limparTela(); // Limpa a tela antes de mostrar o menu
    int largura = 32;
    int paddingTitulo = (largura - strlen(titulo)) / 2;

    printf("\n\t╔");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╗");

    printf("\n\t║");
    for (int i = 0; i < paddingTitulo; i++)
      printf(" ");
    printf("%s", titulo);
    for (int i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
      printf(" ");
    printf(" ║");

    printf("\n\t╠");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╣");
    printf("\n\t║      1 - Listar Produtos       ║");
    printf("\n\t║      2 - Buscar Produto        ║");
    printf("\n\t║      3 - Remover Produto       ║");
    printf("\n\t║      4 - Editar Produto        ║");
    printf("\n\t║      5 - Voltar                ║");

    printf("\n\t╚");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╝");
    printf("\033[0m"); // Resetar cor
    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      listarProdutos(produtos, *totalProdutos); // Função para listar produtos
      break;
    case 2:
      printf("\nDigite o nome do Produto: ");
      scanf("%s", nome);
      buscarProduto(produtos, *totalProdutos,
                    nome); // Função para buscar produto
      break;
    case 3:
      printf("\nDigite o produto que deseja remover: ");
      scanf("%s", nome);
      removerProduto(produtos, totalProdutos,
                     nome); // Função para remover produto
      break;
    case 4:
      printf("\nDigite o produto que deseja editar: ");
      scanf("%s", nome);
      editarProduto(produtos, *totalProdutos,
                    nome); // Função para editar produto
      break;
    case 5:
      printf("Voltando ao menu principal...\n");
      break;
    default:
      printf("Opção inválida, tente novamente.\n");
      break;
    }
  }
}

void menuCaixa(char titulo[]) {
  printf("\033[1;31m"); // Aplicando cor vermelha
  int opcao = 0;
  while (opcao != 5) {
    limparTela();
    int largura = 32;
    int paddingTitulo = (largura - strlen(titulo)) / 2;

    printf("\n\t╔");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╗");

    printf("\n\t║");
    for (int i = 0; i < paddingTitulo; i++)
      printf(" ");
    printf("%s", titulo);
    for (int i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
      printf(" ");
    printf("║");

    printf("\n\t╠");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╣");
    printf("\n\t║      1 - Vender Produto        ║");
    printf("\n\t║      2 - Aplicar Desconto      ║");
    printf("\n\t║      3 - Consultar Preço       ║");
    printf("\n\t║      4 - Cancelar Produto      ║");
    printf("\n\t║      5 - Voltar                ║");

    printf("\n\t╚");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╝");
    printf("\033[0m"); // Resetar cor
    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      // Função para vender produto
      break;
    case 2:
      // Função para aplicar desconto
      break;
    case 3:
      // Função para consultar preço
      break;
    case 4:
      // Função para cancelar produto
      break;
    case 5:
      printf("Voltando ao menu principal...\n");
      break;
    default:
      printf("Opção inválida, tente novamente.\n");
      break;
    }
  }
}

void menuCompras(char titulo[]) {
  printf("\033[1;35m"); // Aplicando cor magenta
  int opcao = 0;
  while (opcao != 5) {
    limparTela();
    int largura = 32;
    int paddingTitulo = (largura - strlen(titulo)) / 2;

    printf("\n\t╔");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╗");

    printf("\n\t║");
    for (int i = 0; i < paddingTitulo; i++)
      printf(" ");
    printf("%s", titulo);
    for (int i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
      printf(" ");
    printf("║");

    printf("\n\t╠");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╣");
    printf("\n\t║     1 - Comprar Produto        ║");
    printf("\n\t║     2 - Gerar Relatório        ║");
    printf("\n\t║     3 - Consultar Pedidos      ║");
    printf("\n\t║     4 - Histórico de Compras   ║");
    printf("\n\t║     5 - Voltar                 ║");

    printf("\n\t╚");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╝");
    printf("\033[0m"); // Resetar cor
    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      // Função para comprar produto
      break;
    case 2:
      // Função para devolver produto
      break;
    case 3:
      // Função para consultar fornecedor
      break;
    case 4:
      // Função para histórico de compras
      break;
    case 5:
      printf("Voltando ao menu principal...\n");
      break;
    default:
      printf("Opção inválida, tente novamente.\n");
      break;
    }
  }
}