# 📚 Sistema de Gestão de Biblioteca — UniMindelo

Este é um sistema de linha de comandos (CLI) desenvolvido em **C** para a gestão modular de livros de uma biblioteca. O projeto foi estruturado seguindo as melhores práticas de programação, separando a lógica de apresentação, controlo de fluxo de dados e definições de estruturas de dados.

O sistema foi otimizado para garantir a segurança no fluxo de leitura de dados, utilizando `fgets` de forma consistente para prevenir overflow de buffers e corrupção de dados ao ler strings com espaços.

---

## 🚀 Funcionalidades

O sistema dispõe de um menu interativo completo com as seguintes opções:

1. **Adicionar novo livro**: Regista um livro validando se o código introduzido já existe na base de dados.
2. **Listar todos os livros**: Exibe a lista detalhada de todos os livros guardados em memória.
3. **Procurar livro por código**: Pesquisa rápida de informações através do código identificador único.
4. **Mostrar livros disponíveis**: Lista exclusivamente os livros que possuem exemplares superiores a 0 em stock.
5. **Atualizar quantidade**: Permite alterar o número de exemplares de um livro já existente de forma dinâmica.
6. **Remover livro**: Remove um livro deslocando os elementos da memória de forma eficiente, sob confirmação do utilizador.
7. **Total de livros registados**: Exibe um contador dinâmico da capacidade ocupada do sistema.

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C (Padrão C99)
* **Compilador:** GCC
* **Automação:** Makefile para compilação automatizada
* **Ambiente Principal:** Linux

---

## 📦 Estrutura do Projeto

O código está dividido de forma modular para facilitar a manutenção e legibilidade:

```text
├── main.c          # Ponto de entrada do programa e fluxo do menu principal
├── menu.c          # Implementação das funções visuais da interface de utilizador
├── menu.h          # Protótipos e assinaturas das funções do menu
├── livros.c        # Lógica de negócio (CRUD dos livros e manipulação do array)
├── livros.h        # Protótipos das funções de manipulação de livros
├── livro.h         # Definição das constantes e da estrutura (struct) Livro
└── Makefile        # Script de automação de compilação
