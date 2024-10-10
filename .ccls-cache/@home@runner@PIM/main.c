// PIM ADS Unip 1 e 2º semestre/2024
// Desenvolvedor: MARCUS PAIXÃO
// Alunos do Grupo: LUIGI PERKOSKI, VITOR RATOLLA, ALEXANDRE PEREIRA, ITALO NUNES & JONATHAN PIRES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"  // Inclui o cabeçalho com as declarações

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

int main() {
  int opcao = 0;

  while (opcao != 4) {
    limparTela();
    menuPrincipal("Sistema Hortifruti");

    printf("\n\nDigite a opção desejada: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 4) {
      printf("\nOpção inválida! Tente novamente.\n");
      continue;
    }

    if (opcao == 4) {
      printf("\nSistema encerrado.\n");
      break;
    }

    switch (opcao) {
    case 1:
      menuEstoque("Gestão de Estoque");
      break;
    case 2:
      menuCaixa("Sistema do Caixa");
      break;
    case 3:
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