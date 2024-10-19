#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <time.h>

// Funções de gerenciamento de estoque
void inicializarProdutos();
long gerar_codigo_barras();
int diferenca_em_dias(struct tm data1, struct tm data2);
struct tm string_para_data(char *data_str);

// Funções Main
void configurarConsoleUTF8();

#endif