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

void menu() {
    printf("-------------------------------------\n");
    printf("\t      Amazon CC\n");
    printf("-------------------------------------\n");

    printf("\t0 - Sair do Sistema\n");
    printf("-------------------------------------\n");

    printf("\t1 - Cadastrar Produtos \n");
    printf("-------------------------------------\n");

    printf("\t2 - Listar Produtos\n");
    printf("-------------------------------------\n");

    printf("\t3 - Buscar Produtos\n");
    printf("-------------------------------------\n");

    printf("\t4 - Deletar Produtos\n");
    printf("-------------------------------------\n");

    printf("\t5 - Comprar Produtos\n");
    printf("-------------------------------------\n");


}


void menuListar() {
    printf("-------------------------------------\n");
    printf("\t      Amazon CC\n");
    printf("-------------------------------------\n");

    printf("\t0 - Voltar ao Menu Principal\n");
    printf("-------------------------------------\n");

    printf("\t1 - Listar Produtos em Ordem Crescente\n");
    printf("-------------------------------------\n");

    printf("\t2 - Listar Produtos em Ordem Decrescente\n");
    printf("-------------------------------------\n");
}


int produtosNulo(ElementProduto *produtos) {
    if(produtos->primeiro == NULL) {
        return TRUE;
    }else {
        return FALSE;
    }
}

int carrinhoNulo(ElementCarrinho *carrinho) {
    if(carrinho->primeiro == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }



}

void cadastroProdutos(ElementProduto *produtos) {
    Produto *aux;
    Produto *auxFor;
    int flag = TRUE;

    aux = malloc(sizeof(Produto));
    auxFor = malloc(sizeof(Produto));
    
    printf("-------------------------------------\n");
    printf("Digite o ID: ");
    scanf("%d", &aux->id);
    printf("\n");

    printf("-------------------------------------\n");
    printf("Digite a Descrição do Produto: ");
    scanf("%s", &aux->nome);   
    printf("\n");
    
    printf("-------------------------------------\n");
    printf("Digite o Preço do Produto: ");
    scanf("%lf", &aux->preco);
    printf("\n");
 
    printf("-------------------------------------\n");
    printf("Digite a Quantidade do Produto: ");
    scanf("%d", &aux->quantidade);
    printf("\n");

    aux->proximo = NULL;
    aux->anterior = NULL;

    if(produtos->primeiro == NULL) {
        produtos->primeiro = aux;
        produtos->ultimo = aux;
    
    }else {
        auxFor = produtos->primeiro;
        for(auxFor; auxFor!=NULL; auxFor=auxFor->proximo) {
            if(auxFor->id == aux->id) {
                printf("-------------------------------------\n");
                printf("ID Utilizado !\n");
            }else {
                if(aux->id > auxFor->id) {
                    if(strcmp(auxFor->id, produtos->ultimo) == 0) {
                        // Encadear na ultimo posição
                    }
                }



            }
            
        }
    }

}

void listarProdutos(ElementProduto *produtos) {
    int opt = 9;

    while(opt != 0) {
        menuListar();
        scanf("%d", &opt);

        switch(opt) {
            case 0:
                printf("-------------------------------------\n");
                printf("Voltar ao Menu Principal\n");
                break;

            case 1:
                printf("-------------------------------------\n");
                printf("Listar em Ordem Crescente\n");
                Produto *aux1 = produtos->primeiro;
                if(produtosNulo(produtos)) {
                    printf("-------------------------------------\n");
                    printf("Lista Vazia! \n");
                }else {
                    for(aux1; aux1!=NULL; aux1=aux1->proximo) {
                        printf("%d %s %.2lf %d\n", aux1->id, aux1->nome, aux1->preco, aux1->quantidade);
                    }
                }
                break;
            
            case 2:
                printf("-------------------------------------\n");
                printf("Listar em Ordem Decrescente\n");
                Produto *aux2 = produtos->ultimo;
                if(produtosNulo(produtos)) {
                    printf("-------------------------------------\n");
                    printf("Lista Vazia! \n");
                }else {
                    for(aux2; aux2!=NULL; aux2=aux2->anterior) {
                        printf("%d %s %.2lf %d\n", aux2->id, aux2->nome, aux2->preco, aux2->quantidade);
                    }
                }
                break;


            default:
                printf("-------------------------------------\n");
                printf("Opção Invalida !\n");
                break;
        }
    }
}


int main() {
    int opt = 9;
    ElementProduto *produtos = malloc(sizeof(ElementProduto));
    
    produtos->ultimo = NULL;
    produtos->primeiro = NULL;


    while(opt != 0) {
        menu();
        scanf("%d", &opt);
        printf("-------------------------------------\n");

        
        switch(opt) {
        
        case 0:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t  Sair do Sistema!\n");
            printf("-------------------------------------\n");
            break;

        case 1:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t  Cadastrar Produtos\n");
            cadastroProdutos(produtos);
            break;
        
        case 2:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t   Listar Produtos\n");
            listarProdutos(produtos);
            break;
        
        case 3:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t   Buscar Produtos\n");
            break;

        case 4:        
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t   Deletar Produtos\n");
            break;

        case 5:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t   Comprar Produtos\n");
            break;

        default:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t  Opção Invalida!!!\n");
            break;
        }
    }

    return 0;
}