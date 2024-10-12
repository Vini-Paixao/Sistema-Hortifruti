// menus.h

#ifndef MENUS_H
#define MENUS_H

#include "estoque.h" // Certifique-se de incluir estoque.h para usar Produto

// Declaração da função menuEstoque
void menuEstoque(char titulo[], Produto produtos[], int *totalProdutos);

// Declaração das outras funções de menu
void menuPrincipal(char titulo[]);
void menuCaixa(char titulo[]);
void menuCompras(char titulo[]);
void limparTela();  // Declaração da função limparTela

#endif