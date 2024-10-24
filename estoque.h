#ifndef ESTOQUE_H
#define ESTOQUE_H

#define MAX_PRODUTOS 100

typedef struct
{
  char nome[50];
  char categoria[20];
  float preco; // Preço por quilo ou unidade
  long codigoBarras;
  char fornecedor[30];
  char validade[11];
  int quantidade;      // Quantidade em estoque (em unidades ou quilos)
  int qtdMinima;       // Quantidade mínima em estoque
  int vendidoPorQuilo; // 1 = vendido por quilo, 0 = vendido por unidade
} Produto;

// Funções de gerenciamento de estoque
void listarProdutos();
void buscarProduto(char nome[]);
void removerProduto(char nome[]);
void editarProduto(char nome[]);

#endif
