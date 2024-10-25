# Sistema de Gestão Hortifruti - <img align="center" alt="Vini-Python" height="40" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg">

Este é um sistema de **Gestão de Hortifruti** chamado **Sistema Hortifácil**, desenvolvido em C para o Projeto Integrador Multidisciplinar (PIM) da Unip Cidade Universitária. Ele permite gerenciar 3 áreas dentro do Hortifruti visando melhorar o desempenho da equipe com um sistema que ajuda nas tarefas diárias os módulos funcionais são:

- Gestão de Estoque
- Sistema de Caixa
- Sistema de Compras

Confira as funcionalidades com detalhes.

## Funcionalidades

- **Gestão de Estoque:**
  - **Listar Produtos**: Exibe todos os produtos cadastrados no estoque.
  - **Buscar Produto**: Permite procurar um produto pelo seu nome.
  - **Remover Produto**: Remove um produto específico do estoque com base no seu nome
  - **Editar Produto**: Permite editar as informações de um produto no estoque.

- **Sistema de Caixa:**
  - **Iniciar Venda**: Inicia um "carrinho" para armazenar os produtos dos clientes.
  - **Ver Carrinho**: Visualiza o carrinho atual do cliente.
  - **Finalizar Venda**: Fecha o carrinho do cliente e pode aplicar descontos ou não.
  - **Histórico de Vendas**: Consulta o histórico completo das vendas.

- **Sistema de Compras:**
  - **Comprar Produto**: Faz a compra de um produto para adicionar no estoque.
  - **Gerar Relatório**: Gerar relatório das últimas comprar.
  - **Consultar Pedidos**: Consultar os últimos pedidos efetuados.
  - **Histórico de Compras**: Histórico completo de compras.

- **Funcionalidades Extras:**
  - **Estoque em Arquivo**: O estoque é estático armazenado em um arquivo, mantendo os valores.
  - **Aviso de Data de Validade**: Cálculo de validade, para manter todos os produtos na validade.
  - **Aviso de Estoque**: Controle de quantidade de produtos disponíveis em estoque, com o mínimo necessário.
  - **Vendas em Arquivo**: As vendas são armazenadas em arquivos estático, mantendo o histórico.

## Demonstração

Tem 2 métodos para executar este programa:

- Certifiquesse de ter um compilador em C nesse exemplo estou usando o `MinGW`:

  Clone o projeto:

  ```bash
  git clone https://github.com/Vini-Paixao/Sistema-Hortifruti.git
  ```

  Entre no projeto:

  ```bash
  cd Sistema-Hortifruti
  ```

  Execute o comando:

  ```bash
  gcc -Wall -Wextra -g3 "main.c" "estoque.c" "menus.c" "utilidades.c" "compra.c" "caixa.c" -o "output\sistema-hortifruti.exe"
  ```

  Execute o arquivo `sistema-hortifruti.exe`

- Ou você pode baixer e executar o arquivo `sistema-hortifruti.exe` direto disponível na área de Release deste projeto - [Clique Aqui](https://github.com/Vini-Paixao/Sistema-Hortifruti/releases)

## Feedback

Se você tiver algum feedback, por favor entre em contato no e-mail: <contato@marcuspaixao.com.br>

## Licença

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/Vini-Paixao/Sistema-Hortifruti/blob/main/LICENSE)
