# Sistema de Gestão Hortifruti - <img align="center" alt="Vini-Python" height="40" width="40" src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg">

Este é um sistema de **Gestão de Hortifruti** chamado **Hortifácil**, desenvolvido em C para o Projeto Integrador Multidisciplinar (PIM) da Unip Cidade Universitária. Ele permite gerenciar 3 áreas dentro do Hortifruti visando melhorar o desempenho da equipe com um sistema que ajuda nas tarefas diárias os módulos funcionais são:

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
  - **Iniciar Compra**: Inicia a compra e adiciona os produtos no carrinho de compras.
  - **Ver Carrinho**: Ver carrinho de compras atual.
  - **Finalizar Compra**: Finalizar compra com os itens do carrinho.
  - **Cancelar Compra**: Cancelar carrinho atual.
  - **Histórico Compras**: Histórico completo de compras.

- **Funcionalidades Extras:**
  - **Estoque em Arquivo**: O estoque é estático armazenado em um arquivo, mantendo os valores.
  - **Vendas em Arquivo**: As vendas são armazenadas em arquivos estático, mantendo o histórico.
  - **Aviso de Data de Validade**: Cálculo de validade, para manter todos os produtos na validade.
  - **Aviso de Estoque**: Controle de quantidade de produtos disponíveis em estoque, com o mínimo necessário.

## Demonstração

Tem 2 métodos para executar este programa, pode usar uma IDE como o Visual Studio Code e compilar manualmente o projeto para executar no seu computador, ou se estiver no Windows apenas baixar o arquivo `Hortifácil.exe` disponível na Release do projeto, confira!

## Método Automático

Você pode baixar e executar o arquivo `Hortifácil.exe` disponível na área de Release deste projeto - [Clique Aqui](https://github.com/Vini-Paixao/Sistema-Hortifruti/releases/tag/1.0.0)

Ao tentar baixar pela opção acima o Windows vai exibir uma imagem de erro, esse alerta aparece porque o Windows não reconhece o fornecedor, e o SmartScreen classifica aplicativos não assinados como potencialmente inseguros.
É normal que o Windows exiba esse alerta, e quem for rodar o aplicativo apenas precisa clicar em "Mais informações" e depois em "Executar assim mesmo" para ignorar a mensagem.

## Método Manual

Certifiquesse de ter um compilador em C nesse exemplo estou usando o `MinGW` com o `Visual Studio Code`:

1. Clone o projeto

```bash
git clone https://github.com/Vini-Paixao/Sistema-Hortifruti.git
```

2. Entre no projeto:

```bash
cd Sistema-Hortifruti
```

3. Execute o comando:

```bash
gcc -Wall -Wextra -g3 main.c estoque.c menus.c utilidades.c compra.c caixa.c recurso.o -o output\Hortifácil.exe
```

Por fim execute o arquivo `Hortifácil.exe` dentro da pasta `/output`

## Feedback

Se você tiver algum feedback, por favor entre em contato no e-mail: <contato@marcuspaixao.com.br>

## Licença

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/Vini-Paixao/Sistema-Hortifruti/blob/main/LICENSE)
