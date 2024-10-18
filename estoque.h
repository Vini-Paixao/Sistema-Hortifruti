#ifndef ESTOQUE_H
#define ESTOQUE_H

#define MAX_PRODUTOS 100

typedef struct
{
  char nome[50];
  char categoria[20];
  float preco;
  long codigoBarras;
  char fornecedor[30];
  char validade[11];
  int quantidade;
  int qtdMinima;
} Produto;

// Funções de gerenciamento de estoque
void listarProdutos();
void buscarProduto(char nome[]);
void removerProduto(char nome[]);
void editarProduto(char nome[]);
void inicializarProdutos();
long gerar_codigo_barras();

#endif
