#ifndef LIVRO_H
#define LIVRO_H

/* ========================================
   Constantes simbólicas do sistema
   ======================================== */
#define MAX_LIVROS     100
#define MAX_TITULO     100
#define MAX_AUTOR       80
#define MAX_CODIGO      10

/* ========================================
   Estrutura que representa um livro
   ======================================== */
typedef struct {
    char codigo[MAX_CODIGO];      /* Código único do livro        */
    char titulo[MAX_TITULO];      /* Título do livro              */
    char autor[MAX_AUTOR];        /* Nome do autor                */
    int  anoPublicacao;           /* Ano de publicação            */
    int  quantidade;              /* Quantidade de exemplares     */
} Livro;

#endif /* LIVRO_H */