# Sistema de Gestão Hortifruti - <img align="center" alt="Vini-Python" height="40" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg">

Este é um sistema de **Gestão de Hortifruti**, desenvolvido em C para o Projeto Integrador Multidisciplinar (PIM) da Unip Cidade Universitária. Ele permite gerenciar 3 áreas dentro do Hortifruti visando melhorar o desempenho da equipe com um sistema que ajude nas tarefas diárias, os principais sistemas a ser gerenciados são:

- Gestão de Estoque
- Sistema de Caixa
- Sistema de Compras

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

## Demonstração

Tem 2 métodos para executar este programa:

- Pode abrir a sua IDE de preferência, certificarsse de ter o compilador em C como o ``MinGW gcc`` e executar o seguinte comando no Terminal:

  ```gcc -Wall -Wextra -g3 "main.c" "estoque.c" "menus.c" "utilidades.c" "compra.c" "caixa.c" -o "output\sistema-hortifruti.exe"```

- Ou pode executar o arquivo .exe disponível na área de Release deste projeto - [Clique Aqui](https://github.com/Vini-Paixao/Sistema-Hortifruti/releases)

## Licença

[MIT](https://choosealicense.com/licenses/mit/)
