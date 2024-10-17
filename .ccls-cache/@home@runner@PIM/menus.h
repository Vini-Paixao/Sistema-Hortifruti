#ifndef MENUS_H
#define MENUS_H

#include "estoque.h"

// Declaração da função menuEstoque
void menuEstoque(char titulo[], Produto produtos[], int *totalProdutos);

// Declaração das outras funções de menu
void menuPrincipal(char titulo[]);
void menuCaixa(char titulo[]);
void menuCompras(char titulo[]);
void limparTela(); // Declaração da função limparTela

#endif