#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

#include "estoque.h"
#include "compra.h"

extern Produto produtos[100]; // Array global de produtos
extern int totalProdutos;     // Contador global de produtos no estoque

void salvarEstoqueEmArquivo()
{
  FILE *arquivo = fopen("estoque.txt", "w");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo de estoque!\n");
    return;
  }

  for (int i = 0; i < totalProdutos; i++)
  {
    fprintf(arquivo, "%s,%s,%.2f,%ld,%s,%s,%d,%d,%d\n",
            produtos[i].nome, produtos[i].categoria, produtos[i].preco, produtos[i].codigoBarras,
            produtos[i].fornecedor, produtos[i].validade, produtos[i].quantidade, produtos[i].qtdMinima, produtos[i].vendidoPorQuilo);
  }

  fclose(arquivo);
  printf("Estoque salvo com sucesso!\n");
}

void carregarEstoqueDeArquivo()
{
  FILE *arquivo = fopen("estoque.txt", "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo de estoque!\n");
    return;
  }

  totalProdutos = 0;
  while (fscanf(arquivo, "%[^,],%[^,],%f,%ld,%[^,],%[^,],%d,%d,%d\n", produtos[totalProdutos].nome, produtos[totalProdutos].categoria,
                &produtos[totalProdutos].preco, &produtos[totalProdutos].codigoBarras, produtos[totalProdutos].fornecedor,
                produtos[totalProdutos].validade, &produtos[totalProdutos].quantidade, &produtos[totalProdutos].qtdMinima,
                &produtos[totalProdutos].vendidoPorQuilo) != EOF)
  {
    totalProdutos++;
  }

  fclose(arquivo);
  printf("Estoque carregado com sucesso!\n");
}

void limparTela()
{
#ifdef _WIN32
  system("cls"); // Comando para Windows
#else
  system("clear"); // Comando para Linux/MacOS
#endif
}

// login do administrador
int login_admin(char login[], char senha[])
{
  const char admin_login[] = "admin";
  const char admin_senha[] = "1234";

  if (strcmp(login, admin_login) == 0 && strcmp(senha, admin_senha) == 0)
  {
    return 1; // Login válido
  }
  return 0; // Login inválido
}

// Função que limpa o buffer
void limpar_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void configurarConsoleUTF8()
{
  // Configura o terminal para UTF-8
  SetConsoleOutputCP(CP_UTF8);                  // Saída em UTF-8
  SetConsoleCP(CP_UTF8);                        // Entrada em UTF-8
  setlocale(LC_ALL, "Portuguese_Brazil.UTF-8"); // Configura o locale para português do Brasil com UTF-8
}

long gerar_codigo_barras()
{
  int prefixo = 15735;                            // Define os 5 primeiros dígitos
  int sufixo = rand() % 10000;                    // Gera os 4 últimos dígitos aleatórios (0 a 9999)
  long codigo_barras = prefixo * 10000L + sufixo; // Combina prefixo e sufixo
  return codigo_barras;
}

// Função para calcular a diferença em dias entre duas datas
int diferenca_em_dias(struct tm data1, struct tm data2)
{
  // Zerar horas, minutos e segundos para ambas as datas
  data1.tm_hour = 0;
  data1.tm_min = 0;
  data1.tm_sec = 0;

  data2.tm_hour = 0;
  data2.tm_min = 0;
  data2.tm_sec = 0;

  // Converter as datas em segundos desde uma data de referência
  time_t tempo1 = mktime(&data1);
  time_t tempo2 = mktime(&data2);

  // Calcular a diferença em segundos e converter para dias
  double diferenca = difftime(tempo1, tempo2) / (60 * 60 * 24);
  return (int)diferenca;
}

// Função para converter string de validade para struct tm
struct tm string_para_data(char *data_str)
{
  struct tm data = {0};
  sscanf(data_str, "%d/%d/%d", &data.tm_mday, &data.tm_mon, &data.tm_year);
  data.tm_year -= 1900; // Ajusta o ano (tm_year é contado a partir de 1900)
  data.tm_mon -= 1;     // Ajusta o mês (tm_mon varia de 0 a 11)
  return data;
}

// Função para adicionar produtos de teste ao estoque
void inicializarProdutos()
{
  strcpy(produtos[0].nome, "Maçã");
  strcpy(produtos[0].categoria, "Frutas");
  produtos[0].preco = 3.99;
  produtos[0].codigoBarras = gerar_codigo_barras();
  strcpy(produtos[0].fornecedor, "Hortifácil");
  strcpy(produtos[0].validade, "10/10/2024");
  produtos[0].qtdMinima = 10;
  produtos[0].quantidade = 20;
  produtos[0].vendidoPorQuilo = 1;

  strcpy(produtos[1].nome, "Banana");
  strcpy(produtos[1].categoria, "Frutas");
  produtos[1].preco = 2.50;
  produtos[1].codigoBarras = gerar_codigo_barras();
  strcpy(produtos[1].fornecedor, "Frutas BR");
  strcpy(produtos[1].validade, "15/11/2024");
  produtos[1].qtdMinima = 20;
  produtos[1].quantidade = 20;
  produtos[1].vendidoPorQuilo = 0;

  strcpy(produtos[2].nome, "Tomate");
  strcpy(produtos[2].categoria, "Legumes");
  produtos[2].preco = 4.20;
  produtos[2].codigoBarras = gerar_codigo_barras();
  strcpy(produtos[2].fornecedor, "Legumes Verde");
  strcpy(produtos[2].validade, "20/12/2024");
  produtos[2].qtdMinima = 15;
  produtos[2].quantidade = 20;
  produtos[2].vendidoPorQuilo = 1;

  totalProdutos = 3; // Atualizando o total de produtos
  salvarEstoqueEmArquivo();
}