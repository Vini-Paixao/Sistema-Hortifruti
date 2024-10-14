#include "estoque.h"
#include "menus.h"
#include <stdio.h>

int main() {
  int opcao = 0;
  Produto produtos[100]; // Array para armazenar até 100 produtos
  int totalProdutos = 0; // Contador de produtos no estoque

  // Inicializando produtos de teste
  inicializarProdutos(produtos, &totalProdutos);

  while (opcao != 4) {
    limparTela();
    menuPrincipal("Sistema Hortifruti");

    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 4) {
      printf("\nOpção inválida! Tente novamente.\n");
      continue;
    }

    switch (opcao) {
    case 1:
      menuEstoque("Gestão de Estoque", produtos, &totalProdutos);
      break;
    case 2:
      menuCaixa("Sistema do Caixa");
      break;
    case 3:
      menuCompras("Sistema de Compras");
      break;
    case 4:
      printf("\nSistema encerrado.\n");
      break;
    }
  }
  return 0;
}