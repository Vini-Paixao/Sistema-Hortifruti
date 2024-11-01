// Incluindo dependências
#include "estoque.h"
#include "compra.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <setjmp.h>

extern Produto produtos[100];       // Array global de produtos
extern int totalProdutos;           // Contador global de produtos no estoque
extern jmp_buf menuPrincipalReturn; // Declaração externa para acessar o ponto de retorno ao menu principal

// Função para salvar o Estoque em arquivo
void salvarEstoqueEmArquivo()
{
  FILE *arquivo = fopen("estoque.txt", "w");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo de estoque!\n");
    return;
  }

  // Cabeçalho inicial do estoque
  fprintf(arquivo, "===== Estoque Hortifruti =====\n\n");

  // Loop para salvar cada produto no formato desejado
  for (int i = 0; i < totalProdutos; i++)
  {
    fprintf(arquivo, "===== Produto %d =====\n", i + 1);
    fprintf(arquivo, "Nome: %s\n", produtos[i].nome);
    fprintf(arquivo, "Categoria: %s\n", produtos[i].categoria);
    fprintf(arquivo, "Preço: R$ %.2f\n", produtos[i].preco);
    fprintf(arquivo, "Código de Barras: %ld\n", produtos[i].codigoBarras);
    fprintf(arquivo, "Fornecedor: %s\n", produtos[i].fornecedor);
    fprintf(arquivo, "Validade: %s\n", produtos[i].validade);
    fprintf(arquivo, "Quantidade em Estoque: %d\n", produtos[i].quantidade);
    fprintf(arquivo, "Quantidade Mínima Necessária: %d\n", produtos[i].qtdMinima);
    fprintf(arquivo, "Vendido por Quilo ou Unidade: %s\n\n",
            produtos[i].vendidoPorQuilo ? "Quilo" : "Unidade");
  }

  fclose(arquivo);
  printf("\n\033[1;32m===== Estoque Salvo! =====\033[0m\n\n");
}

// Função para carregar as informações do arquivo
void carregarEstoqueDeArquivo()
{
  FILE *arquivo = fopen("estoque.txt", "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo de estoque!\n");
    return;
  }

  totalProdutos = 0;
  char buffer[256];

  // Ignora o cabeçalho do estoque
  fgets(buffer, sizeof(buffer), arquivo);

  // Ler cada linha do arquivo até o final
  while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
  {
    // Ignora as linhas de divisão de produtos
    if (strncmp(buffer, "===== Produto", 13) == 0)
    {
      // Lê cada campo para o produto atual
      fgets(buffer, sizeof(buffer), arquivo); // Nome
      sscanf(buffer, "Nome: %[^\n]", produtos[totalProdutos].nome);

      fgets(buffer, sizeof(buffer), arquivo); // Categoria
      sscanf(buffer, "Categoria: %[^\n]", produtos[totalProdutos].categoria);

      fgets(buffer, sizeof(buffer), arquivo); // Preço
      sscanf(buffer, "Preço: R$ %f", &produtos[totalProdutos].preco);

      fgets(buffer, sizeof(buffer), arquivo); // Código de Barras
      sscanf(buffer, "Código de Barras: %ld", &produtos[totalProdutos].codigoBarras);

      fgets(buffer, sizeof(buffer), arquivo); // Fornecedor
      sscanf(buffer, "Fornecedor: %[^\n]", produtos[totalProdutos].fornecedor);

      fgets(buffer, sizeof(buffer), arquivo); // Validade
      sscanf(buffer, "Validade: %[^\n]", produtos[totalProdutos].validade);

      fgets(buffer, sizeof(buffer), arquivo); // Quantidade em Estoque
      sscanf(buffer, "Quantidade em Estoque: %d", &produtos[totalProdutos].quantidade);

      fgets(buffer, sizeof(buffer), arquivo); // Quantidade Mínima Necessária
      sscanf(buffer, "Quantidade Mínima Necessária: %d", &produtos[totalProdutos].qtdMinima);

      fgets(buffer, sizeof(buffer), arquivo); // Vendido por Quilo ou Unidade
      char vendidoPorQuilo[10];
      sscanf(buffer, "Vendido por Quilo ou Unidade: %[^\n]", vendidoPorQuilo);
      produtos[totalProdutos].vendidoPorQuilo = (strcmp(vendidoPorQuilo, "Quilo") == 0) ? 1 : 0;

      // Incrementa o total de produtos
      totalProdutos++;
    }
  }

  fclose(arquivo);
  printf("Estoque carregado com sucesso!\n");
}

// FUnção para limpar o Console
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

// Função para configurar o console em UTF8
void configurarConsoleUTF8()
{
  // Configura o terminal para UTF-8
  SetConsoleOutputCP(CP_UTF8);                  // Saída em UTF-8
  SetConsoleCP(CP_UTF8);                        // Entrada em UTF-8
  setlocale(LC_ALL, "Portuguese_Brazil.UTF-8"); // Configura o locale para português do Brasil com UTF-8
}

// FUnção para gerar os códigos de barras dos produtos
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

// Função para inciar o estoque com 3 produtos
void inicializarProdutos()
{
  strcpy(produtos[0].nome, "Maçã");
  strcpy(produtos[0].categoria, "Frutas");
  produtos[0].preco = 3.99;
  produtos[0].codigoBarras = gerar_codigo_barras();
  strcpy(produtos[0].fornecedor, "Fazenda da Mônica");
  strcpy(produtos[0].validade, "10/12/2024");
  produtos[0].qtdMinima = 15;
  produtos[0].quantidade = 30;
  produtos[0].vendidoPorQuilo = 1;

  strcpy(produtos[1].nome, "Banana");
  strcpy(produtos[1].categoria, "Frutas");
  produtos[1].preco = 2.50;
  produtos[1].codigoBarras = gerar_codigo_barras();
  strcpy(produtos[1].fornecedor, "Frutas BR");
  strcpy(produtos[1].validade, "15/11/2024");
  produtos[1].qtdMinima = 20;
  produtos[1].quantidade = 60;
  produtos[1].vendidoPorQuilo = 0;

  strcpy(produtos[2].nome, "Tomate");
  strcpy(produtos[2].categoria, "Frutas");
  produtos[2].preco = 4.20;
  produtos[2].codigoBarras = gerar_codigo_barras();
  strcpy(produtos[2].fornecedor, "Frutas BR");
  strcpy(produtos[2].validade, "20/12/2024");
  produtos[2].qtdMinima = 20;
  produtos[2].quantidade = 45;
  produtos[2].vendidoPorQuilo = 1;

  totalProdutos = 3; // Atualizando o total de produtos
  salvarEstoqueEmArquivo();
}

// Função para buscar se existe produto com o mesmo nome
int existeProdutoComNome(const char *nome)
{
  for (int i = 0; i < totalProdutos; i++)
  {
    if (strcmp(produtos[i].nome, nome) == 0)
    {
      return 1; // Nome já existe
    }
  }
  return 0; // Nome não existe, é único
}

// Função para gerar 27 produtos aleatórios
void gerarProdutosAleatorios()
{
  const char *frutas[] = {"Mamão", "Melão", "Abacaxi", "Uva", "Laranja", "Manga", "Melancia", "Pera", "Caju", "Kiwi", "Amora", "Carambola", "Pêssego", "Framboesa", "Goiaba", "Guaraná", "Jabuticaba", "Lichia", "Abacate"};
  const char *verduras[] = {"Alface", "Couve", "Espinafre", "Rúcula", "Salsa", "Coentro", "Cenoura", "Brócolis", "Pepino", "Abóbora", "Escarola", "Couve Flor", "Pimentão", "Alcachofra", "Aspargo", "Palmito", "Milho", "Jiló"};
  const char *fornecedores[] = {"Hortifruti BR", "Verdura Natural", "Frutas BR", "Hortifácil", "Legumes Verde"};

  srand(time(NULL)); // Inicializa o gerador de números aleatórios

  for (int i = 0; i < 27; i++)
  {
    Produto novoProduto;
    int tipo, indiceNome;
    char nomeProduto[50];

    // Gera um nome único
    do
    {
      tipo = rand() % 2;
      if (tipo == 0)
      { // Fruta
        indiceNome = rand() % (sizeof(frutas) / sizeof(frutas[0]));
        strcpy(nomeProduto, frutas[indiceNome]);
      }
      else
      { // Verdura
        indiceNome = rand() % (sizeof(verduras) / sizeof(verduras[0]));
        strcpy(nomeProduto, verduras[indiceNome]);
      }
    } while (existeProdutoComNome(nomeProduto)); // Verifica se o nome é único

    strcpy(novoProduto.nome, nomeProduto);
    strcpy(novoProduto.categoria, tipo == 0 ? "Frutas" : "Verduras");
    novoProduto.vendidoPorQuilo = rand() % 2; // 1 = por quilo, 0 = por unidade

    // Define um preço aleatório entre R$1,00 e R$15,00
    novoProduto.preco = (float)(rand() % 1401 + 100) / 100;

    // Gera automaticamente o código de barras
    novoProduto.codigoBarras = gerar_codigo_barras();

    // Define um fornecedor aleatório
    strcpy(novoProduto.fornecedor, fornecedores[rand() % 5]);

    // Define uma validade aleatória (entre hoje e um ano a partir de hoje)
    int diasValidade = rand() % 365;
    time_t t = time(NULL) + diasValidade * 24 * 3600;
    struct tm validade = *localtime(&t);
    snprintf(novoProduto.validade, 11, "%02d/%02d/%04d", validade.tm_mday, validade.tm_mon + 1, validade.tm_year + 1900);

    // Define a quantidade mínima entre 5 e 20 e a quantidade em estoque entre 10 e 100
    novoProduto.qtdMinima = rand() % 6 + 19;
    novoProduto.quantidade = rand() % 6 + 29;

    // Adiciona o produto ao array global
    produtos[totalProdutos] = novoProduto;
    totalProdutos++;
  }

  printf("30 produtos únicos foram gerados e adicionados ao estoque.\n");

  printf("\n\033[1;32mPressione ENTER para continuar...\n");
  getchar();

  // Salvar o estoque no arquivo após a geração
  salvarEstoqueEmArquivo();
}