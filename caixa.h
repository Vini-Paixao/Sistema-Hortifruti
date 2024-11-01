#ifndef CAIXA_H
#define CAIXA_H

// Estrutura para um item do carrinho de compras
typedef struct
{
    char nome[50];
    float preco;
    float peso;     // Para vendas por quilo
    int quantidade; // Para vendas por unidade
    float valorTotal;
} CarrinhoItem;

// Declaração das funções de Caixa
void venderProduto();
void verCarrinho();
void finalizarCompra();
void mostrarHistoricoVendas();
void cancelarCarrinho();

#endif