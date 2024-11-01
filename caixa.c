// Incluindo dependências
#include "estoque.h"
#include "utilidades.h"
#include "caixa.h"
#include <stdio.h>
#include <string.h>

extern Produto produtos[100]; // Array global de produtos
extern int totalProdutos;     // Contador global do total de produtos no estoque

CarrinhoItem carrinho[100]; // Array para armazenar os itens do carrinho
int totalItensCarrinho = 0; // Contador de itens no carrinho

// Função para iniciar uma venda
void venderProduto()
{
    configurarConsoleUTF8();
    char nomeProduto[50];
    float peso = 0.0;
    int quantidade = 0;
    int encontrado = 0;

    printf("\n\033[1;31m===== Vender Produto =====\033[0m\n\n");

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

            // Cria um novo item para adicionar ao carrinho
            CarrinhoItem item;
            strcpy(item.nome, produtos[i].nome); // Copia o nome do produto para o item do carrinho
            item.preco = produtos[i].preco;      // Define o preço do item

            // Venda por quilo
            if (produtos[i].vendidoPorQuilo)
            {
                printf("Digite o peso (em quilos) a ser vendido: ");
                scanf("%f", &peso);

                int unidadesVendidas = (int)(10 * peso); // Converte o peso para unidades (10 por kg)

                if (unidadesVendidas > produtos[i].quantidade)
                {
                    printf("Erro: Quantidade em estoque insuficiente.\n");
                    return;
                }

                // Atualiza o estoque
                produtos[i].quantidade -= unidadesVendidas;

                // Preenche os dados do item para venda por peso
                item.peso = peso;
                item.quantidade = 0;                        // Venda por quilo, quantidade é 0
                item.valorTotal = produtos[i].preco * peso; // Preço baseado no peso
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

                // Atualiza o estoque
                produtos[i].quantidade -= quantidade;

                // Preenche os dados do item para venda por unidade
                item.quantidade = quantidade;
                item.peso = 0;                                    // Venda por unidade, peso é 0
                item.valorTotal = produtos[i].preco * quantidade; // Preço baseado na quantidade
            }

            // Adiciona o item ao carrinho
            carrinho[totalItensCarrinho] = item;
            totalItensCarrinho++; // Incrementa o contador de itens no carrinho

            // Exibe os detalhes da venda
            printf("\n\n\033[1;31m===== Item Adicionado ao Carrinho =====\033[0m\n\n");
            printf("Nome: %s\n", item.nome);
            if (produtos[i].vendidoPorQuilo)
            {
                printf("Peso: %.2f kg\n", item.peso);
            }
            else
            {
                printf("Quantidade: %d\n", item.quantidade);
            }
            printf("Valor Total: R$ %.2f\n", item.valorTotal);

            // Pausa para o usuário pressionar ENTER
            printf("\n\033[1;31mPressione ENTER para continuar...\n");
            printf("\033[0;31m"); // Aplicando cor vermelha
            getchar();
            getchar(); // Captura ENTER para pausar
            return;
        }
    }

    if (!encontrado)
    {
        printf("\n\033[0;31m===== Produto não Encontrado =====\033[0m\n\n");
    }

    printf("\033[1;31mPressione ENTER para continuar...\n\033[0m");
    printf("\033[0;31m"); // Aplicando cor vermelha
    getchar();            // Pausa até que o usuário pressione enter
}

// Função para visualizar o carrinho atual
void verCarrinho()
{
    if (totalItensCarrinho == 0)
    {
        printf("\n\033[0;31m===== Carrinho Vazio =====\033[0m\n\n");
    }
    else
    {
        printf("\n\n\033[1;31m===== Carrinho de Compras =====\033[0m\n\n");
        for (int i = 0; i < totalItensCarrinho; i++)
        {
            printf("Produto: %s\n", carrinho[i].nome);
            printf("Quantidade/Peso: %.2f\n", carrinho[i].peso > 0 ? carrinho[i].peso : (int)carrinho[i].quantidade);
            printf("Valor: R$ %.2f\n\n", carrinho[i].valorTotal);
        }
    }
    printf("\033[1;31mPressione ENTER para continuar...\n\033[0m");
    printf("\033[0;31m"); // Aplicando cor vermelha
    getchar();
    getchar(); // Pausa até que o usuário pressione enter
}

// Função para finalizar uma compra
void finalizarCompra()
{
    if (totalItensCarrinho == 0)
    {
        printf("\n\033[0;31m===== Carrinho Vazio =====\033[0m\n\n");
        printf("\033[1;31mPressione ENTER para continuar...\n\033[0m");
        printf("\033[0;31m"); // Aplicando cor vermelha
        getchar();
        getchar();
        return;
    }

    float total = 0.0;
    float desconto = 0.0;

    // Exibe o resumo do carrinho
    printf("\n\n\033[1;31m===== Resumo da Compra =====\033[0m\n\n");
    for (int i = 0; i < totalItensCarrinho; i++)
    {
        printf("Produto: %s\n", carrinho[i].nome);
        printf("Quantidade/Peso: %.2f\n", carrinho[i].peso > 0 ? carrinho[i].peso : (float)carrinho[i].quantidade);
        printf("Valor: R$ %.2f\n\n", carrinho[i].valorTotal);
        total += carrinho[i].valorTotal;
    }

    printf("Total sem desconto: R$ %.2f\n", total);

    // Aplicar desconto, se necessário
    printf("Deseja aplicar um desconto? (1 = Sim, 0 = Não): ");
    int aplicarDesconto;
    scanf("%d", &aplicarDesconto);
    if (aplicarDesconto)
    {
        printf("Digite o percentual de desconto (0 a 100): ");
        scanf("%f", &desconto);
        desconto = (desconto / 100) * total;
    }

    float totalFinal = total - desconto;
    printf("Total com desconto: R$ %.2f\n", totalFinal);

    // Salvar a venda no arquivo
    FILE *arquivo = fopen("vendas.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo de vendas.\n");
        return;
    }

    fprintf(arquivo, "===== Nova Venda =====\n");
    for (int i = 0; i < totalItensCarrinho; i++)
    {
        fprintf(arquivo, "Produto: %s\n", carrinho[i].nome);
        fprintf(arquivo, "Quantidade/Peso: %.2f\n", carrinho[i].peso > 0 ? carrinho[i].peso : (float)carrinho[i].quantidade);
        fprintf(arquivo, "Valor: R$ %.2f\n\n", carrinho[i].valorTotal);
    }
    fprintf(arquivo, "Total sem desconto: R$ %.2f\n", total);
    fprintf(arquivo, "Desconto: R$ %.2f\n", desconto);
    fprintf(arquivo, "Total final: R$ %.2f\n", totalFinal);
    fprintf(arquivo, "======================\n\n");

    fclose(arquivo);

    salvarEstoqueEmArquivo();

    // Limpar o carrinho
    totalItensCarrinho = 0;
    printf("\n\033[1;32mVenda finalizada com sucesso!\033[0m\n\n");

    printf("\033[1;31mPressione ENTER para continuar...\n\033[0m");
    printf("\033[0;31m"); // Aplicando cor vermelha
    getchar();
    getchar(); // Pausa até que o usuário pressione enter
}

// Função para mostrar as vendas
void mostrarHistoricoVendas()
{
    FILE *arquivo = fopen("vendas.txt", "r");
    if (arquivo == NULL)
    {
        printf("\n\033[0;31m===== Nenhuma Venda Encontrada =====\033[0m\n\n");
        printf("\033[1;31mPressione ENTER para continuar...\n\033[0m");
        printf("\033[0;31m"); // Aplicando cor vermelha
        getchar();
        getchar();
        return;
    }

    char linha[256];
    printf("\n\n\033[1;31m===== Histórico de Vendas =====\033[0m\n\n");
    while (fgets(linha, sizeof(linha), arquivo))
    {
        printf("%s", linha);
    }
    fclose(arquivo);

    printf("\n\033[1;31mPressione ENTER para continuar...\n\033[0m");
    printf("\033[0;31m"); // Aplicando cor vermelha
    getchar();
    getchar(); // Pausa até que o usuário pressione enter
}

// Função para cancelar toda a compra (esvaziar o carrinho)
void cancelarCarrinho()
{
    if (totalItensCarrinho == 0)
    {
        printf("\n\033[0;31m===== Carrinho já está vazio =====\033[0m\n\n");
        printf("\n\033[1;31mPressione ENTER para continuar...\n\033[0m");
        printf("\033[0;31m"); // Aplicando cor vermelha
        getchar();
        getchar(); // Pausa até que o usuário pressione enter
        return;
    }

    // Reverter as quantidades dos itens no carrinho ao estoque
    for (int i = 0; i < totalItensCarrinho; i++)
    {
        for (int j = 0; j < totalProdutos; j++)
        {
            if (strcmp(produtos[j].nome, carrinho[i].nome) == 0)
            {
                // Devolve a quantidade ou peso do produto para o estoque
                if (carrinho[i].peso > 0)
                {
                    produtos[j].quantidade += (int)(10 * carrinho[i].peso); // Conversão para unidades se vendido por peso
                }
                else
                {
                    produtos[j].quantidade += carrinho[i].quantidade;
                }
                break;
            }
        }
    }

    // Esvaziar o carrinho
    totalItensCarrinho = 0;
    printf("\n\033[1;32m===== Carrinho Cancelado =====\033[0m\n\n");
    printf("Todos os itens foram devolvidos ao estoque");

    printf("\n\033[1;31mPressione ENTER para continuar...\n\033[0m");
    printf("\033[0;31m"); // Aplicando cor vermelha
    getchar();
    getchar(); // Pausa até que o usuário pressione enter
}