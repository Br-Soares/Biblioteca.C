#include <stdio.h>
#include <string.h>
#include "livros.h"
#include "menu.h"

/* ========================================
   Auxiliar: encontra índice pelo código
   Retorna o índice ou -1 se não encontrado
   ======================================== */
static int encontrarIndice(const Livro biblioteca[], int total, const char *codigo) {
    int i;
    for (i = 0; i < total; i++) {
        if (strcmp(biblioteca[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

/* ========================================
   Auxiliar: imprime linha separadora
   ======================================== */
static void imprimirSeparador(void) {
    printf("----------------------------------------\n");
}

/* ========================================
   Auxiliar: imprime os dados de um livro
   ======================================== */
static void imprimirLivro(const Livro *l) {
    imprimirSeparador();
    printf("Código      : %s\n", l->codigo);
    printf("Título      : %s\n", l->titulo);
    printf("Autor       : %s\n", l->autor);
    printf("Ano         : %d\n", l->anoPublicacao);
    printf("Quantidade  : %d exemplar(es)\n", l->quantidade);
}

/* ========================================
   Adicionar novo livro
   ======================================== */
int adicionarLivro(Livro biblioteca[], int *total) {
    Livro novo;

    if (*total >= MAX_LIVROS) {
        printf("\nErro: capacidade máxima de %d livros atingida.\n", MAX_LIVROS);
        return 0;
    }

    printf("\nCódigo do livro (máx. %d caracteres): ", MAX_CODIGO - 1);
    // ALTERADO: Usando fgets para ler o código de forma segura
    fgets(novo.codigo, MAX_CODIGO, stdin);
    novo.codigo[strcspn(novo.codigo, "\n")] = '\0';

    if (strlen(novo.codigo) == 0) {
        printf("\nErro: o código não pode estar vazio.\n");
        return 0;
    }

    if (encontrarIndice(biblioteca, *total, novo.codigo) != -1) {
        printf("\nErro: já existe um livro com o código '%s'.\n", novo.codigo);
        return 0;
    }

    printf("Título: ");
    fgets(novo.titulo, MAX_TITULO, stdin);
    novo.titulo[strcspn(novo.titulo, "\n")] = '\0';
    if (strlen(novo.titulo) == 0) {
        printf("\nErro: o título não pode estar vazio.\n");
        return 0;
    }

    printf("Autor: ");
    fgets(novo.autor, MAX_AUTOR, stdin);
    novo.autor[strcspn(novo.autor, "\n")] = '\0';
    if (strlen(novo.autor) == 0) {
        printf("\nErro: o nome do autor não pode estar vazio.\n");
        return 0;
    }

    printf("Ano de publicação: ");
    if (scanf("%d", &novo.anoPublicacao) != 1 || novo.anoPublicacao < 1 || novo.anoPublicacao > 2100) {
        printf("\nErro: ano inválido.\n");
        limparBuffer();
        return 0;
    }
    limparBuffer();

    printf("Quantidade de exemplares: ");
    if (scanf("%d", &novo.quantidade) != 1 || novo.quantidade < 0) {
        printf("\nErro: quantidade inválida.\n");
        limparBuffer();
        return 0;
    }
    limparBuffer();

    biblioteca[*total] = novo;
    (*total)++;

    printf("\nLivro '%s' adicionado com sucesso!\n", novo.titulo);
    return 1;
}

/* ========================================
   Listar todos os livros
   ======================================== */
void listarLivros(const Livro biblioteca[], int total) {
    int i;
    if (total == 0) {
        printf("\nNenhum livro cadastrado no sistema.\n");
        return;
    }
    printf("\n===== LISTA DE TODOS OS LIVROS (%d) =====\n", total);
    for (i = 0; i < total; i++) {
        imprimirLivro(&biblioteca[i]);
    }
    imprimirSeparador();
}

/* ========================================
   Procurar livro por código
   ======================================== */
void procurarLivroPorCodigo(const Livro biblioteca[], int total) {
    char codigo[MAX_CODIGO];
    int  indice;

    if (total == 0) {
        printf("\nNenhum livro cadastrado no sistema.\n");
        return;
    }

    printf("\nDigite o código do livro: ");
    // ALTERADO: Usando fgets em vez de scanf
    fgets(codigo, MAX_CODIGO, stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    indice = encontrarIndice(biblioteca, total, codigo);

    if (indice == -1) {
        printf("\nNenhum livro encontrado com o código '%s'.\n", codigo);
    } else {
        printf("\n===== LIVRO ENCONTRADO =====\n");
        imprimirLivro(&biblioteca[indice]);
        imprimirSeparador();
    }
}

/* ========================================
   Listar apenas livros disponíveis
   ======================================== */
void listarLivrosDisponiveis(const Livro biblioteca[], int total) {
    int i;
    int encontrados = 0;

    if (total == 0) {
        printf("\nNenhum livro cadastrado no sistema.\n");
        return;
    }

    printf("\n===== LIVROS DISPONÍVEIS =====\n");
    for (i = 0; i < total; i++) {
        if (biblioteca[i].quantidade > 0) {
            imprimirLivro(&biblioteca[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro disponível no momento.\n");
    } else {
        imprimirSeparador();
        printf("Total disponíveis: %d\n", encontrados);
    }
}

/* ========================================
   Atualizar quantidade de exemplares
   ======================================== */
void atualizarQuantidade(Livro biblioteca[], int total) {
    char codigo[MAX_CODIGO];
    int  indice, novaQtd;

    if (total == 0) {
        printf("\nNenhum livro cadastrado no sistema.\n");
        return;
    }

    printf("\nDigite o código do livro: ");
    // ALTERADO: Usando fgets para evitar corromper o buffer de novos livros
    fgets(codigo, MAX_CODIGO, stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    indice = encontrarIndice(biblioteca, total, codigo);
    if (indice == -1) {
        printf("\nNenhum livro encontrado com o código '%s'.\n", codigo);
        return;
    }

    printf("Livro: %s\n", biblioteca[indice].titulo);
    printf("Quantidade atual: %d\n", biblioteca[indice].quantidade);
    printf("Nova quantidade : ");

    if (scanf("%d", &novaQtd) != 1 || novaQtd < 0) {
        printf("\nErro: quantidade inválida.\n");
        limparBuffer();
        return;
    }
    limparBuffer();

    biblioteca[indice].quantidade = novaQtd;
    printf("\nQuantidade atualizada para %d exemplar(es).\n", novaQtd);
}

/* ========================================
   Remover livro pelo código
   ======================================== */
void removerLivro(Livro biblioteca[], int *total) {
    char codigo[MAX_CODIGO];
    int  indice, i;
    char confirmacao;

    if (*total == 0) {
        printf("\nNenhum livro cadastrado no sistema.\n");
        return;
    }

    printf("\nDigite o código do livro a remover: ");
    // ALTERADO: Usando fgets
    fgets(codigo, MAX_CODIGO, stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    indice = encontrarIndice(biblioteca, *total, codigo);
    if (indice == -1) {
        printf("\nNenhum livro encontrado com o código '%s'.\n", codigo);
        return;
    }

    printf("\nLivro a remover:\n");
    imprimirLivro(&biblioteca[indice]);
    imprimirSeparador();
    printf("Confirmar remoção? (s/n): ");
    scanf(" %c", &confirmacao);
    limparBuffer();

    if (confirmacao != 's' && confirmacao != 'S') {
        printf("\nOperação cancelada.\n");
        return;
    }

    /* Desloca elementos para preencher o espaço */
    for (i = indice; i < (*total) - 1; i++) {
        biblioteca[i] = biblioteca[i + 1];
    }
    (*total)--;

    printf("\nLivro removido com sucesso.\n");
}

/* ========================================
   Mostrar total de livros registados
   ======================================== */
void mostrarTotal(int total) {
    printf("\n===== TOTAL DE LIVROS =====\n");
    printf("Registados: %d / %d\n", total, MAX_LIVROS);
}