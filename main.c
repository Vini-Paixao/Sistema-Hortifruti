#include "estoque.h"
#include "menus.h"
#include "compra.h"
#include "utilidades.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

int main()
{
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com base no tempo
    configurarConsoleUTF8(); // Configura o console para UTF-8
    inicializarProdutos(); // Inicializando produtos base do Estoque

    int opcao = 0; // Opção que o usuário vai selecionar e começa em 0
    while (opcao != 4)
    {
        limparTela();
        menuPrincipal("Sistema Hortifruti");

        printf("\n\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        if (opcao < 1 || opcao > 4)
        {
            printf("\nOpção inválida! Tente novamente.\n");
            continue;
        }

        switch (opcao)
        {
        case 1:
            menuEstoque("Gestão de Estoque");
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