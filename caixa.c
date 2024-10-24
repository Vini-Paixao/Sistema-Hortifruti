#include <stdio.h>
#include <string.h>
#include "estoque.h"
#include "utilidades.h"

extern Produto produtos[100];
extern int totalProdutos;

void venderProduto()
{
    char nomeProduto[50];
    float peso;
    int quantidade;
    int encontrado = 0;

    printf("Digite o nome do produto que deseja vender: ");
    getchar(); // Limpar o buffer
    fgets(nomeProduto, sizeof(nomeProduto), stdin);
    nomeProduto[strcspn(nomeProduto, "\n")] = '\0';

    // Busca pelo produto
    for (int i = 0; i < totalProdutos; i++)
    {
        if (strcmp(produtos[i].nome, nomeProduto) == 0)
        {
            encontrado = 1;
            printf("Produto encontrado: %s\n", produtos[i].nome);
            printf("Preço por %s: R$ %.2f\n", produtos[i].vendidoPorQuilo ? "quilo" : "unidade", produtos[i].preco);

            // Venda por quilo
            if (produtos[i].vendidoPorQuilo)
            {
                printf("Digite o peso (em quilos) a ser vendido: ");
                scanf("%f", &peso);
                if (peso > produtos[i].quantidade)
                {
                    printf("Erro: Quantidade em estoque insuficiente.\n");
                    return;
                }
                float valorTotal = produtos[i].preco * peso;
                produtos[i].quantidade -= peso; // Atualiza o estoque
                printf("Valor total: R$ %.2f\n", valorTotal);
            }
            // Venda por unidade
            else
            {
                printf("Digite a quantidade a ser vendida: ");
                scanf("%d", &quantidade);
                if (quantidade > produtos[i].quantidade)
                {
                    printf("Erro: Quantidade em estoque insuficiente.\n");
                    return;
                }
                float valorTotal = produtos[i].preco * quantidade;
                produtos[i].quantidade -= quantidade; // Atualiza o estoque
                printf("Valor total: R$ %.2f\n", valorTotal);
            }

            printf("Venda realizada com sucesso!\n");
            printf("Nova quantidade em estoque: %.2f\n", (float)produtos[i].quantidade);
            break;
        }
    }

    if (!encontrado)
    {
        printf("Produto não encontrado.\n");
    }
}