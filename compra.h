#ifndef COMPRA_H
#define COMPRA_H

#include "estoque.h"

// Estrutura para representar cada item no carrinho de compras
typedef struct {
    char nome[50];
    char categoria[20];
    float preco;
    int quantidade;
    float peso;
    char validade[11];
    char fornecedor[30];
    int qtdMinima;
    float valorTotal;
} ItemCompra;

// Variáveis globais para gerenciar o carrinho
ItemCompra carrinho[100];
extern int totalItensCompra;

// Função para realizar a compra de um produto
void comprar_produto();

void adicionar_ao_estoque(char nome[], char categoria[], float preco, long codigoBarras,
                          char fornecedor[], char validade[], int qtdMinima, int quantidade, int vendidoPorQuilo);

void mostrarHistoricoCompras();
void finalizarCompraCompra();
void adicionar_ao_carrinho(char nome[], char categoria[], float preco, int quantidade, float peso,
                           char validade[], char fornecedor[], int qtdMinima);
void verCarrinhoCompra();

int encontrar_produto_no_estoque(const char *nome_produto);

#endif