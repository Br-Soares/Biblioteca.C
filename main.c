#include <stdio.h>
#include "livro.h"
#include "livros.h"
#include "menu.h"

int main(void) {
    Livro biblioteca[MAX_LIVROS];
    int   total = 0;
    int   opcao;

    printf("=== Sistema de Gestão da Biblioteca - Uni Mindelo ===\n");

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1: adicionarLivro(biblioteca, &total);       break;
            case 2: listarLivros(biblioteca, total);           break;
            case 3: procurarLivroPorCodigo(biblioteca, total); break;
            case 4: listarLivrosDisponiveis(biblioteca, total);break;
            case 5: atualizarQuantidade(biblioteca, total);    break;
            case 6: removerLivro(biblioteca, &total);          break;
            case 7: mostrarTotal(total);                       break;
            case 8: printf("\nAté logo!\n");                   break;
            default: printf("\nOpção inválida. Escolha entre 1 e 8.\n"); break;
        }

        if (opcao != 8) {
            pausar();
        }

    } while (opcao != 8);

    return 0;
}