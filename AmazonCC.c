#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct _Produto {
    int id;
    char nome[255];
    double preco;
    int quantidade;
    struct _Produto *proximo;
    struct _Produto *anterior;

};
typedef struct _Produto Produto;

typedef struct {
    Produto *primeiro;
    Produto *ultimo;

} ElementProduto;

struct _Carrinho {
    int idCarrinho;
    int quantidadeCarrinho;
    struct _Carrinho *proximo;
    struct _Carrinho *anterior;

};
typedef struct _Carrinho Carrinho;

typedef struct {
    Carrinho *primeiro;
    Carrinho *ultimo;

} ElementCarrinho;




int main() {

    // quem copiar não vai ganhar ovo na pascoa !!!!!!!!!

    return 0;
}