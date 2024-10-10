// PIM ADS Unip 1 e 2º semestre/2024
// Desenvolvedor: Marcus Paixão
// Alunos do Grupo: LUIGI PERKOSKI, VITOR RATOLLA, ALEXANDRE PEREIRA, ITALO
// NUNES & JONATHAN PIRES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int cont = 0; // Variável global para controlar o número de contatos
void adicionarContato(char nome[], char telefone[]);
void removerContato(int id);
void buscarContato(int id);
void listarContatos();

struct Contato{
    int id;
    char nome[50];
    char telefone[15];
};
struct Contato contatos[10]; // Array de contatos*/

void limparTela() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void menuPrincipal(char titulo[]) {
  printf("\033[1;32m"); // Aplicando cor verde
  int largura = 32;
  int paddingTitulo = (largura - strlen(titulo)) / 2;

  printf("\n\t╔");
  for (int i = 0; i < largura; i++)
    printf("═");
  printf("╗");

  printf("\n\t║");
  for (int i = 0; i < paddingTitulo; i++)
    printf(" ");
  printf("%s", titulo);
  for (int i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
    printf(" ");
  printf("║");

  printf("\n\t╠");
  for (int i = 0; i < largura; i++)
    printf("═");
  printf("╣");
  printf("\n\t║     1 - Adicionar Produtos     ║");
  printf("\n\t║     2 - Sistema de Estoque     ║");
  printf("\n\t║     3 - Sistema do Caixa       ║");
  printf("\n\t║     4 - Sistema de Compras     ║");
  printf("\n\t║     5 - Encerrar Programa      ║");

  printf("\n\t╚");
  for (int i = 0; i < largura; i++)
    printf("═");
  printf("╝");
  printf("\033[0m");
}

void menuEstoque(char titulo[]) {
  printf("\033[1;34m"); // Aplicando cor azul
  int opcao = 0;
  while (opcao != 5) {
    limparTela(); // Limpa a tela antes de mostrar o menu
    int largura = 32;
    int paddingTitulo = (largura - strlen(titulo)) / 2;

    printf("\n\t╔");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╗");

    printf("\n\t║");
    for (int i = 0; i < paddingTitulo; i++)
      printf(" ");
    printf("%s", titulo);
    for (int i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
      printf(" ");
    printf(" ║");

    printf("\n\t╠");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╣");
    printf("\n\t║      1 - Listar Produtos       ║");
    printf("\n\t║      2 - Buscar Produto        ║");
    printf("\n\t║      3 - Remover Produto       ║");
    printf("\n\t║      4 - Editar Produto        ║");
    printf("\n\t║      5 - Voltar                ║");

    printf("\n\t╚");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╝");
    printf("\033[0m"); // Resetar cor
    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      // Função para listar produtos
      break;
    case 2:
      // Função para buscar produto
      break;
    case 3:
      // Função para remover produto
      break;
    case 4:
      // Função para editar produto
      break;
    case 5:
      printf("Voltando ao menu principal...\n");
      break;
    default:
      printf("Opção inválida, tente novamente.\n");
      break;
    }
  }
}

void menuCaixa(char titulo[]) {
  printf("\033[1;31m"); // Aplicando cor vermelha
  int opcao = 0;
  while (opcao != 5) {
    limparTela();
    int largura = 32;
    int paddingTitulo = (largura - strlen(titulo)) / 2;

    printf("\n\t╔");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╗");

    printf("\n\t║");
    for (int i = 0; i < paddingTitulo; i++)
      printf(" ");
    printf("%s", titulo);
    for (int i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
      printf(" ");
    printf("║");

    printf("\n\t╠");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╣");
    printf("\n\t║      1 - Vender Produto        ║");
    printf("\n\t║      2 - Aplicar Desconto      ║");
    printf("\n\t║      3 - Consultar Preço       ║");
    printf("\n\t║      4 - Cancelar Produto      ║");
    printf("\n\t║      5 - Voltar                ║");

    printf("\n\t╚");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╝");
    printf("\033[0m"); // Resetar cor
    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      // Função para vender produto
      break;
    case 2:
      // Função para aplicar desconto
      break;
    case 3:
      // Função para consultar preço
      break;
    case 4:
      // Função para cancelar produto
      break;
    case 5:
      printf("Voltando ao menu principal...\n");
      break;
    default:
      printf("Opção inválida, tente novamente.\n");
      break;
    }
  }
}

void menuCompras(char titulo[]) {
  printf("\033[1;35m"); // Aplicando cor magenta
  int opcao = 0;
  while (opcao != 5) {
    limparTela();
    int largura = 32;
    int paddingTitulo = (largura - strlen(titulo)) / 2;

    printf("\n\t╔");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╗");

    printf("\n\t║");
    for (int i = 0; i < paddingTitulo; i++)
      printf(" ");
    printf("%s", titulo);
    for (int i = 0; i < largura - paddingTitulo - strlen(titulo); i++)
      printf(" ");
    printf("║");

    printf("\n\t╠");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╣");
    printf("\n\t║    1 - Comprar Produto         ║");
    printf("\n\t║    2 - Gerar Relatório         ║");
    printf("\n\t║    3 - Consultar Pedidos       ║");
    printf("\n\t║    4 - Histórico de Compras    ║");
    printf("\n\t║    5 - Voltar                  ║");

    printf("\n\t╚");
    for (int i = 0; i < largura; i++)
      printf("═");
    printf("╝");
    printf("\033[0m"); // Resetar cor
    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      // Função para comprar produto
      break;
    case 2:
      // Função para devolver produto
      break;
    case 3:
      // Função para consultar fornecedor
      break;
    case 4:
      // Função para histórico de compras
      break;
    case 5:
      printf("Voltando ao menu principal...\n");
      break;
    default:
      printf("Opção inválida, tente novamente.\n");
      break;
    }
  }
}

int main() {
  int opcao = 0;

  while (opcao != 5) {
    limparTela();
    menuPrincipal("Sistema Hortifruti");

    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 5) {
      printf("\nOpção inválida! Tente novamente.\n");
      continue;
    }

    if (opcao == 5) {
      printf("\nSistema encerrado.\n");
      break;
    }

    switch (opcao) {
    case 1:
      // Função para adicionar produtos
      break;
    case 2:
      menuEstoque("Gestão de Estoque");
      break;
    case 3:
      menuCaixa("Sistema do Caixa");
      break;
    case 4:
      menuCompras("Sistema de Compras");
      break;
    }
  }
  return 0;
}

/*void adicionarContato(char nome[], char telefone[]){
    contatos[cont].id = cont + 1; // Definindo o ID único
    strcpy(contatos[cont].nome, nome);
    strcpy(contatos[cont].telefone, telefone);
    cont++;
    printf("Contato adicionado com sucesso!\n");
}

void listarContatos() {
    if (cont == 0) {
        printf("Nenhum contato adicionado.\n");
    } else {
        for (int i = 0; i < cont; i++) {
            printf("\nID: %d\n", contatos[i].id);
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
        }
    }
}

void buscarContato(int id) {
    int encontrado = 0;
    for (int i = 0; i < cont; i++) {
        if (contatos[i].id == id) {
            printf("\nContato encontrado:\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato com ID %d não encontrado.\n", id);
    }
}

void removerContato(int id) {
    int encontrado = 0;
    for (int i = 0; i < cont; i++) {
        if (contatos[i].id == id) {
            encontrado = 1;
            for (int j = i; j < cont - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            cont--; // Reduz o número de contatos
            printf("Contato com ID %d removido com sucesso.\n", id);
            break;
        }
    }
    if (!encontrado) {
      printf("Contato com ID %d não encontrado.\n", id);
    }
}*/