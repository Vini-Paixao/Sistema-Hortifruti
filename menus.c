#include "menus.h"      // Incluímos o cabeçalho menus.h
#include "compra.h"     // Incluímos compra.h para adicionar ao Estoque
#include "caixa.h"      // Incluímos compra.h para vender do Estoque
#include "estoque.h"    // Incluímos estoque.h para usar Produto
#include "utilidades.h" // Incluímos utilidades.h para usar as Funções Auxiliares

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da função menuPrincipal
void menuPrincipal()
{
  char titulo[20] = "Sistema Hortifácil";
  printf("\033[0;32m"); // Aplicando cor verde
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
  for (size_t i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
    printf(" ");
  printf(" ║");

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
void menuEstoque()
{
  char titulo[20] = "Gestão de Estoque";
  printf("\033[0;34m"); // Aplicando cor azul
  int opcao = 0;
  char nome[50];

  while (opcao != 5)
  {
    limparTela(); // Limpa a tela antes de mostrar o menu
    int largura = 31;
    int paddingTitulo = (largura - strlen(titulo)) / 2;

    printf("\n\t╔");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╗");

    printf("\n\t║");
    for (int i = 0; i < paddingTitulo; i++)
      printf(" ");
    printf("%s", titulo);
    for (size_t i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
      printf(" ");
    printf(" ║");

    printf("\n\t╠");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╣");
    printf("\n\t║      1 - Listar Produtos      ║");
    printf("\n\t║      2 - Buscar Produto       ║");
    printf("\n\t║      3 - Remover Produto      ║");
    printf("\n\t║      4 - Editar Produto       ║");
    printf("\n\t║      5 - Voltar               ║");

    printf("\n\t╚");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╝");
    printf("\033[0m"); // Resetar cor
    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      listarProdutos(); // Função para listar produtos
      break;
    case 2:
      printf("\nDigite o nome do Produto: ");
      scanf("%s", nome);
      buscarProduto(nome); // Função para buscar produto
      break;
    case 3:
      printf("\nDigite o produto que deseja remover: ");
      scanf("%s", nome);
      removerProduto(nome); // Função para remover produto
      break;
    case 4:
      printf("\nDigite o produto que deseja editar: ");
      scanf("%s", nome);
      editarProduto(nome); // Função para editar produto
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

void menuCaixa()
{
  char titulo[20] = "Gestão de Vendas";
  printf("\033[0;31m"); // Aplicando cor vermelha
  int opcao = 0;
  while (opcao != 5)
  {
    limparTela();
    int largura = 31;
    int paddingTitulo = (largura - strlen(titulo)) / 2;

    printf("\n\t╔");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╗");

    printf("\n\t║");
    for (int i = 0; i < paddingTitulo; i++)
      printf(" ");
    printf("%s", titulo);
    for (size_t i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
      printf(" ");
    printf(" ║");

    printf("\n\t╠");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╣");
    printf("\n\t║      1 - Iniciar Venda        ║");
    printf("\n\t║      2 - Ver Carrinho         ║");
    printf("\n\t║      3 - Finalizar Venda      ║");
    printf("\n\t║      4 - Histórico Vendas     ║");
    printf("\n\t║      5 - Voltar               ║");

    printf("\n\t╚");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╝");
    printf("\033[0m"); // Resetar cor
    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      venderProduto(); // Inicia venda e adiciona ao carrinho
      break;
    case 2:
      verCarrinho(); // Exibe o conteúdo do carrinho
      break;
    case 3:
      finalizarCompra(); // Finaliza a compra e salva no arquivo
      break;
    case 4:
      mostrarHistoricoVendas(); // Exibe o histórico de vendas do arquivo
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

void menuCompras()
{
  char titulo[20] = "Gestão de Compras";
  printf("\033[0;36m"); // Aplicando cor Ciano
  int opcao = 0;
  while (opcao != 5)
  {
    limparTela();
    int largura = 31;
    int paddingTitulo = (largura - strlen(titulo)) / 2;

    printf("\n\t╔");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╗");

    printf("\n\t║");
    for (int i = 0; i < paddingTitulo; i++)
      printf(" ");
    printf("%s", titulo);
    for (size_t i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
      printf(" ");
    printf(" ║");

    printf("\n\t╠");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╣");
    printf("\n\t║     1 - Comprar Produto       ║");
    printf("\n\t║     2 - Gerar Relatório       ║");
    printf("\n\t║     3 - Consultar Pedidos     ║");
    printf("\n\t║     4 - Histórico Compras     ║");
    printf("\n\t║     5 - Voltar                ║");

    printf("\n\t╚");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╝");
    printf("\033[0m"); // Resetar cor
    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      comprar_produto();
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