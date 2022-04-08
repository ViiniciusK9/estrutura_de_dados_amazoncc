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

} ListProduto;

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

} ListCarrinho;


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


int produtosNulo(ListProduto *produtos) {
    if(produtos->primeiro == NULL) {
        return TRUE;
    }else {
        return FALSE;
    }
}


int carrinhoNulo(ListCarrinho *carrinho) {
    if(carrinho->primeiro == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}


Produto *infoProdutos(){
    Produto *novoProduto = (Produto*)malloc(sizeof(Produto));

    printf("-------------------------------------\n");
    printf("Digite o ID: ");
    scanf("%d", &novoProduto->id);
    printf("\n");

    printf("-------------------------------------\n");
    printf("Digite a Descrição do Produto: ");
    scanf("%s", novoProduto->nome);   
    printf("\n");
    
    printf("-------------------------------------\n");
    printf("Digite o Preço do Produto: ");
    scanf("%lf", &novoProduto->preco);
    printf("\n");
 
    printf("-------------------------------------\n");
    printf("Digite a Quantidade do Produto: ");
    scanf("%d", &novoProduto->quantidade);
    printf("\n");

    novoProduto->proximo = NULL;
    novoProduto->anterior = NULL;
    return novoProduto;
}


void cadastroProdutos(ListProduto *produtos) {  
    Produto *aux = infoProdutos();
    Produto *auxFor;
    int inseriu = 0;

    if(produtos->primeiro == NULL && produtos->ultimo == NULL) {
        produtos->primeiro = aux;
        produtos->ultimo = aux;
    
    }else {
        
        for(auxFor = produtos->primeiro; auxFor != NULL; auxFor = auxFor->proximo) {
            if(auxFor->id == aux->id) {
                printf("ID invalido\n");
                break;
            }else {
                if(auxFor->id > aux->id){ // 1 2 3 4 5 
                    inseriu = 1;
                    if(produtos->primeiro == auxFor) {
                        auxFor->anterior = aux;
                        aux->proximo = auxFor;
                        produtos->primeiro = aux;
                        break;
                    }else {
                        auxFor->anterior->proximo = aux;
                        aux->proximo = auxFor;
                        aux->anterior = auxFor->anterior;
                        auxFor->anterior = aux;
                        break;
                    }
                }
            }
        }
        if(!inseriu) {
            produtos->ultimo->proximo = aux;
            aux->anterior = produtos->ultimo;
            produtos->ultimo = aux;
        }
    }
}

void listarProdutos(ListProduto *produtos) {
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


void buscarProdutos(ListProduto *produtos) {
    int opt = 9;
    int pk;
    double price;
    int qnt;
    Produto *auxBusca = produtos->primeiro;

    while(opt!=0) {
        scanf("%d", &opt);
        switch(opt) {
            case 0:
                printf("Voltar ao menu Principal\n");            
                break;
            
            case 1:
                printf("Buscar por Id\n");
                scanf("%d", &pk);
                if(produtosNulo(produtos)) {
                    printf("-------------------------------------\n");
                    printf("Lista Vazia! \n");
                }else {
                    for(auxBusca; auxBusca!=NULL; auxBusca=auxBusca->proximo) {
                        if(auxBusca->id == pk) {
                            printf("%d %s %.2lf %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                        }else {
                            printf("Produto não encontrado!\n");
                        }
                    }
                }
                break;

            case 2:
                // char name[255];
                printf("Buscar por Nome\n");
                // scanf("%s", &name);
                // Produto *aux1 = produtos->primeiro;
                // if(produtosNulo(produtos)) {
                //     printf("-------------------------------------\n");
                //     printf("Lista Vazia! \n");
                // }else {
                //     for(aux1; aux1!=NULL; aux1=aux1->proximo) {

                //         if(aux1->nome == name) {
                //             printf("%d %s %.2lf %d\n", aux1->id, aux1->nome, aux1->preco, aux1->quantidade);
                //         }else {
                //             printf("Produto não encontrado!\n");
                //         }
                //     }
                // }
                break; 

            case 3:
                printf("Buscar Buscar por preço\n");
                /* scanf("%lf", &price);
                if(produtosNulo(produtos)) {
                    printf("-------------------------------------\n");
                    printf("Lista Vazia! \n");
                }else {
                    for(auxBusca; auxBusca!=NULL; auxBusca=auxBusca->proximo) {
                        if(auxBusca->preco == price) {
                            printf("%d %s %.2lf %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                        }else {
                            printf("Produto não encontrado!\n");
                        }
                    }
                } */
                break;

            case 4:
                printf("Buscar por quantidade\n");
                scanf("%d", &qnt);
                if(produtosNulo(produtos)) {
                    printf("-------------------------------------\n");
                    printf("Lista Vazia! \n");
                }else {
                    for(auxBusca; auxBusca!=NULL; auxBusca=auxBusca->proximo) {
                        if(auxBusca->quantidade == qnt) {
                            printf("%d %s %.2lf %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                        }else {
                            printf("Produto não encontrado!\n");
                        }
                    }
                }
                break;

            default:
                printf("Opção invalida!\n");
                break;
        }
    }
}


int main() {
    int opt = 9;
    ListProduto *produtos = malloc(sizeof(ListProduto));
    
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
            buscarProdutos(produtos);
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
// teste de acesso 
// gcc AmazonCC.c -o prog
