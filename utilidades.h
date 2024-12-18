#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <time.h>

// Funções Estoque
void inicializarProdutos();
long gerar_codigo_barras();
int diferenca_em_dias(struct tm data1, struct tm data2);
struct tm string_para_data(char *data_str);
void salvarEstoqueEmArquivo();
void carregarEstoqueDeArquivo();

// Funções Main
void configurarConsoleUTF8();
void limparTela();
void limpar_buffer();
void gerarProdutosAleatorios();
int existeProdutoComNome(const char *nome);
int login_admin(char login[], char senha[]);

#endif