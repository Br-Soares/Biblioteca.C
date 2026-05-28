#include <stdio.h>
#include "menu.h"

/* ========================================
   Limpa o buffer do teclado
   ======================================== */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ========================================
   Pausa até o utilizador pressionar Enter
   ======================================== */
void pausar(void) {
    printf("\nPressione Enter para continuar...");
    limparBuffer();
}

/* ========================================
   Exibe o menu principal e lê a opção
   ======================================== */
int exibirMenu(void) {
    int opcao;

    printf("\n╔══════════════════════════════════════╗\n");
    printf("║     BIBLIOTECA - UNI MINDELO         ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  1. Adicionar novo livro             ║\n");
    printf("║  2. Listar todos os livros           ║\n");
    printf("║  3. Procurar livro por código        ║\n");
    printf("║  4. Mostrar livros disponíveis       ║\n");
    printf("║  5. Atualizar quantidade             ║\n");
    printf("║  6. Remover livro                    ║\n");
    printf("║  7. Total de livros registados       ║\n");
    printf("║  8. Sair                             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");

    if (scanf("%d", &opcao) != 1) {
        limparBuffer();
        return -1;
    }
    limparBuffer();
    return opcao;
}