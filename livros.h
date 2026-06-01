#ifndef LIVROS_H
#define LIVROS_H

#include "livro.h"

int  adicionarLivro(Livro biblioteca[], int *total);
void listarLivros(const Livro biblioteca[], int total);
void procurarLivroPorCodigo(const Livro biblioteca[], int total);
void listarLivrosDisponiveis(const Livro biblioteca[], int total);
void atualizarQuantidade(Livro biblioteca[], int total);
void removerLivro(Livro biblioteca[], int *total);
void mostrarTotal(int total);

#endif /* LIVROS_H */