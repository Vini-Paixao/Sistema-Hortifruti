#ifndef COMPRA_H
#define COMPRA_H

#include "estoque.h"

// Função para realizar a compra de um produto
void comprar_produto();

void adicionar_ao_estoque(char nome[], char categoria[], float preco, long codigoBarras, 
                          char fornecedor[], char validade[], int qtdMinima, int quantidade);

// Função para validar o login do administrador
int login_admin(char login[], char senha[]);

// Função para gerar relatório de compras realizadas
// void gerar_relatorio_compras();

// Função para consultar pedidos realizados
// void consultar_pedidos();

// Função para exibir o histórico completo de compras
// void historico_compras();

#endif