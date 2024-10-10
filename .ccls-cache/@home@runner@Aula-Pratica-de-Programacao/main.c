// Desafio 07.10
#include <stdio.h>
#include <string.h>

int cont = 0; // Variável global para controlar o número de contatos
void adicionarContato(char nome[], char telefone[]);
void removerContato(int id);
void buscarContato(int id);
void listarContatos();

struct Contato{
    int id;
    char nome[50];
    char telefone[15];
};
struct Contato contatos[10]; // Array de contatos

void desenhaBorda(char titulo[]) {
    int largura = 31;
    int paddingTitulo = (largura - strlen(titulo)) / 2;

    printf("\n\t╔");
    for (int i = 0; i < largura; i++) printf("═");
    printf("╗");

    printf("\n\t║");
    for (int i = 0; i < paddingTitulo; i++) printf(" ");
    printf("%s", titulo);
    for (int i = 0; i < largura - paddingTitulo - strlen(titulo); i++) printf(" ");
    printf("║");

    printf("\n\t╠");
    for (int i = 0; i < largura; i++) printf("═");
    printf("╣");
    printf("\n\t║      1 - Adicionar Contato    ║");
    printf("\n\t║      2 - Listar Contatos      ║");
    printf("\n\t║      3 - Buscar Contato       ║");
    printf("\n\t║      4 - Apagar Contato       ║");
    printf("\n\t║      5 - Encerrar Programa    ║");

    printf("\n\t╚");
    for (int i = 0; i < largura; i++) printf("═");
    printf("╝");
}

int main() {
    int opcao = 0, id;
    char nome[50], telefone[15];

    while(opcao != 5) {
        printf("\n");
        desenhaBorda("Gerenciador de Contatos");

        printf("\n\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        if(opcao < 1 || opcao > 5) {
            printf("\nOpção inválida! Tente novamente.\n");
            continue;
        }

        if(opcao == 5) {
            printf("\nPrograma encerrado.\n");
            break;
        }

        switch(opcao) {
            case 1:
                printf("Digite o nome do contato: ");
                scanf("%s", nome);
                printf("Digite o telefone do contato: ");
                scanf("%s", telefone);
                adicionarContato(nome, telefone);
                break;
            case 2:
                listarContatos();
                break;
            case 3:
                printf("Digite o ID do contato a buscar: ");
                scanf("%d", &id);
                buscarContato(id);
                break;
            case 4:
                printf("Digite o ID do contato a remover: ");
                scanf("%d", &id);
                removerContato(id);
                break;
        }
    }
    return 0;
}

void adicionarContato(char nome[], char telefone[]){
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
}