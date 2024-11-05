// Incluindo dependências
#include "menus.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

// Função Principal do projeto
int main()
{
    srand(time(NULL));          // Inicializa o gerador de números aleatórios com base no tempo
    configurarConsoleUTF8();    // Configura o console para UTF-8
    inicializarProdutos();      // Inicializando produtos base do Estoque
    carregarEstoqueDeArquivo(); // Carrega o arquivo de Estoque

    int opcao = 0; // Opção que o usuário vai selecionar e começa em 0

    while (opcao != 4)
    {
        limparTela();
        menuPrincipal();
        printf("\n\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        while (getchar() != '\n')
            ; // Limpa o buffer do scanf

        // Verifica o código Admin antes das demais opções
        if (opcao == 14042004)
        {
            printf("\n\033[1;32m===== Código Admin Secreto =====\033[0m\n\n");
            gerarProdutosAleatorios();
        }

        // Verifica se a opção é válida (entre 1 e 4)
        if (opcao < 1 || opcao > 4)
        {
            printf("\nOpção inválida! Tente novamente.\n");
            printf("\033[0;32m"); // Aplicando cor verde
            getchar();
            continue;
        }

        // Processa as opções do menu principal
        switch (opcao)
        {
        case 1:
            menuEstoque();
            break;
        case 2:
            menuCaixa();
            break;
        case 3:
            menuCompras();
            break;
        case 4:
            printf("\n\033[1;34mObrigado por Prestigiar o nosso Projeto!!\n");
            printf("\nDesenvolvido por Marcus Paixão\033[1;0m\n");
            printf("\nIntegrantes do Grupo -\nAlexandre\nLuigi\nItalo\nJonathan\nJoão\nVitor");
            printf("\n\nProjeto Integrador Multidisciplinar (PIM) - 2024");
            printf("\n\nDigite ENTER para encerrar...");
            getchar();
            printf("\nSistema encerrado.\n");
            break;
        default:
            printf("Opção inválida, pressione ENTER para tente novamente.\n");
            getchar();
            getchar();
            printf("\033[0;32m"); // Aplicando cor verde
            break;
        }
    }
    return 0;
}
