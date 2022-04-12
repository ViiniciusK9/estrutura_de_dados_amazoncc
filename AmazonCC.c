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
    double preco;
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


void menuBuscar() {
    printf("-------------------------------------\n");
    printf("\t      Amazon CC\n");
    printf("-------------------------------------\n");

    printf("\t0 - Voltar ao Menu Principal\n");
    printf("-------------------------------------\n");

    printf("\t1 - Buscar por Id\n");
    printf("-------------------------------------\n");

    printf("\t2 - Buscar por Nome\n");
    printf("-------------------------------------\n");

    printf("\t3 - Buscar Buscar por Preço\n");
    printf("-------------------------------------\n");

    printf("\t4 - Buscar Buscar por Quantidade\n");
    printf("-------------------------------------\n");
}


void menuCarrinho() {
    printf("-------------------------------------\n");
    printf("\t      Amazon CC\n");
    printf("-------------------------------------\n");

    printf("\t0 - Voltar ao Menu Principal\n");
    printf("-------------------------------------\n");

    printf("\t1 - Colocar Produto no Carrinho\n");
    printf("-------------------------------------\n");

    printf("\t2 - Remover Produto do Carrinho\n");
    printf("-------------------------------------\n");

    printf("\t3 - Consultar Carrinho\n");
    printf("-------------------------------------\n");

    printf("\t4 - Finalizar Compra\n");
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


void excluirProdutos(ListProduto * produtos){
    int id;
    printf("Digite o ID a ser excluido: ");
    scanf("%d", &id);
    Produto *auxFor;
    for(auxFor = produtos->primeiro; auxFor != NULL; auxFor = auxFor->proximo){
        if(auxFor->id == id){
            if(auxFor == produtos->primeiro && auxFor == produtos->ultimo){
                produtos->primeiro = NULL;
                produtos->ultimo = NULL;
                free(auxFor);
                return;
            }else if(auxFor == produtos->primeiro){
                auxFor->proximo->anterior = NULL;
                produtos->primeiro = auxFor->proximo;
                free(auxFor);
                return;
            }else if(auxFor == produtos->ultimo){
                auxFor->anterior->proximo = NULL;
                produtos->ultimo = auxFor->anterior;
                free(auxFor);
                return;
            }else{
                auxFor->anterior->proximo = auxFor->proximo;
                auxFor->proximo->anterior = auxFor->anterior;
                free(auxFor);
                return;
            }
        }
    }
    printf("Produto não cadastrado!\n");
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
    int achou;
    char nome[255];
    Produto *auxBusca;

    while(opt!=0) {
        menuBuscar();
        scanf("%d", &opt);
        switch(opt) {
            case 0:
                printf("Voltar ao menu Principal\n");            
                break;
            
            case 1:
                printf("Buscar por Id\n");
                printf("Digite o Id: ");
                int pk;
                achou = 1;
                scanf("%d", &pk);
                if(produtosNulo(produtos)) {
                    printf("-------------------------------------\n");
                    printf("Lista Vazia! \n");
                }else {
                    for(auxBusca = produtos->primeiro; auxBusca!=NULL; auxBusca = auxBusca->proximo) {
                        if(auxBusca->id == pk) {
                            achou = 0;
                            printf("%d %s %.2lf %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                        }
                    }
                    if(achou){
                        printf("Produto não encontrado!\n");
                    }
                }
                break;

            case 2:
                printf("Buscar por Nome\n");
                printf("Digite o nome: ");
                scanf("%s", nome);
                achou = 1;
                if(produtosNulo(produtos)) {
                    printf("-------------------------------------\n");
                    printf("Lista Vazia! \n");
                }else {
                    for(auxBusca = produtos->primeiro; auxBusca!=NULL; auxBusca = auxBusca->proximo) {
                        if(strcmp(auxBusca->nome, nome) == 0) {
                            achou = 0;
                            printf("%d %s %.2lf %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                        }
                    }
                    if(achou){
                        printf("Produto não encontrado!\n");
                    }
                }
                break; 

            case 3:
                printf("Buscar Buscar por Preço\n");
                printf("Digite o preço: ");
                double preco;
                achou = 1;
                scanf("%lf", &preco);
                if(produtosNulo(produtos)) {
                    printf("-------------------------------------\n");
                    printf("Lista Vazia! \n");
                }else {
                    for(auxBusca = produtos->primeiro; auxBusca!=NULL; auxBusca = auxBusca->proximo) {
                        if(auxBusca->preco == preco) {
                            achou = 0;
                            printf("%d %s %.2lf %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                            return;
                        }
                    }
                    if(achou){
                        printf("Produto não encontrado!\n");
                    }
                } 
                break;

            case 4:
                printf("Buscar por Quantidade\n");
                printf("Digite a quantidade: ");
                int qnt;
                achou = 1;
                scanf("%d", &qnt);
                if(produtosNulo(produtos)) {
                    printf("-------------------------------------\n");
                    printf("Lista Vazia! \n");
                }else {
                    for(auxBusca = produtos->primeiro; auxBusca!=NULL; auxBusca = auxBusca->proximo) {
                        if(auxBusca->quantidade == qnt) {
                            achou = 0;
                            printf("%d %s %.2lf %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                        }
                    }
                    if(achou){
                        printf("Produto não encontrado!\n");
                    }
                }
                break;

            default:
                printf("Opção invalida!\n");
                break;
        }
    }
}


void listarCarrinho(ListCarrinho *carrinho){
    Carrinho *aux; 
    for (aux = carrinho->primeiro; aux != NULL; aux = aux->proximo){
        printf("%d %d %.2lf\n", aux->idCarrinho, aux->quantidadeCarrinho, aux->preco);
    }
}


int verificarEstoque(ListProduto *produtos, int id, int qnt){
    Produto *auxFor;
    for (auxFor = produtos->primeiro; auxFor != NULL; auxFor = auxFor->proximo){
        if(id == auxFor->id && qnt <= auxFor->quantidade && (auxFor->quantidade - qnt) >= 0){
            auxFor->quantidade -= qnt;
            return 1;
        }
    }
    return 0;
}


int verificarCarrinho(ListCarrinho *carrinho, int id, int qnt){
    Carrinho *auxFor;
    for (auxFor = carrinho->primeiro; auxFor != NULL; auxFor = auxFor->proximo){
        if(id == auxFor->idCarrinho && (auxFor->quantidadeCarrinho + qnt) >= 0){
            auxFor->quantidadeCarrinho += qnt;
            return 1;
        }
    }
    return 0;
}


int verificarCarrinhoRemover(ListCarrinho *carrinho, int id, int qnt){
    Carrinho *auxFor;
    for (auxFor = carrinho->primeiro; auxFor != NULL; auxFor = auxFor->proximo){
        if(id == auxFor->idCarrinho && (auxFor->quantidadeCarrinho - qnt) > 0){
            auxFor->quantidadeCarrinho -= qnt;
            return 1;
        }else if (id == auxFor->idCarrinho && (auxFor->quantidadeCarrinho - qnt) == 0){
            auxFor->quantidadeCarrinho -= qnt;
            return 2;
        }
    }
    return 0;
}


double verificarPrecoProduto(ListProduto *produtos, int id){
    Produto *auxFor;
    for (auxFor = produtos->primeiro; auxFor != NULL; auxFor = auxFor->proximo){
        if(id == auxFor->id){
            return auxFor->preco;
        }
    }
    return 0;
}


Carrinho *infoCarrinho(int id, int qnt, double preco){
    Carrinho *novoElemento = (Carrinho*)malloc(sizeof(Carrinho));
    novoElemento->idCarrinho = id;
    novoElemento->quantidadeCarrinho = qnt;
    novoElemento->preco = preco;
    novoElemento->proximo = NULL;
    novoElemento->anterior = NULL;
    return novoElemento;
}


void inserirProdutoCarrinho(ListProduto *produtos, ListCarrinho *carrinho){
    int id, qnt;
    printf("-------------------------------------\n");
    printf("Digite o ID: ");
    scanf("%d", &id);
    printf("\n");
 
    printf("-------------------------------------\n");
    printf("Digite a Quantidade do Produto: ");
    scanf("%d", &qnt);
    printf("\n");
    if(verificarEstoque(produtos, id, qnt)) {
        if(verificarCarrinho(carrinho, id, qnt)){
            return;
        }else {
            double preco = verificarPrecoProduto(produtos, id);
            Carrinho *aux = infoCarrinho(id, qnt, preco);
            if(carrinho->primeiro == NULL && carrinho->ultimo == NULL) {
                carrinho->primeiro = aux;
                carrinho->ultimo = aux;
            }else {
                carrinho->ultimo->proximo = aux;
                aux->anterior = carrinho->ultimo;
                carrinho->ultimo = aux;
            }
        }
    }else {
        printf("Id não encontrado\n");
    }
}


void removerCarrinho(ListCarrinho *carrinho, int id){
    Carrinho *auxFor;
    for(auxFor = carrinho->primeiro; auxFor != NULL; auxFor = auxFor->proximo){
        if(auxFor->idCarrinho == id){
            if(auxFor == carrinho->primeiro && auxFor == carrinho->ultimo){
                carrinho->primeiro = NULL;
                carrinho->ultimo = NULL;
                free(auxFor);
                return;
            }else if(auxFor == carrinho->primeiro){
                auxFor->proximo->anterior = NULL;
                carrinho->primeiro = auxFor->proximo;
                free(auxFor);
                return;
            }else if(auxFor == carrinho->ultimo){
                auxFor->anterior->proximo = NULL;
                carrinho->ultimo = auxFor->anterior;
                free(auxFor);
                return;
            }else{
                auxFor->anterior->proximo = auxFor->proximo;
                auxFor->proximo->anterior = auxFor->anterior;
                free(auxFor);
                return;
            }
        }
    }
}


void removerProdutoCarrinho(ListProduto *produtos, ListCarrinho *carrinho){
    int id, qnt;
    printf("-------------------------------------\n");
    printf("Digite o ID: ");
    scanf("%d", &id);
    printf("\n");
 
    printf("-------------------------------------\n");
    printf("Digite a Quantidade do Produto: ");
    scanf("%d", &qnt);
    printf("\n");
    int flag = verificarCarrinhoRemover(carrinho, id, qnt);
    if(flag == 1){
        verificarEstoque(produtos, id, (-qnt));
        return;
    }else if (flag == 2){
        verificarEstoque(produtos, id, (-qnt));
        removerCarrinho(carrinho, id);
    }else{
        printf("Id não encontrado\n");
    }
}


void mainCarrinho(ListProduto *produtos, ListCarrinho *carrinho){
    int opt = 9;

    while(opt != 0) {
        menuCarrinho();
        scanf("%d", &opt);
        printf("-------------------------------------\n");
        switch(opt) {
        
        case 0:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t  Voltar ao Menu Principal\n");
            printf("-------------------------------------\n");
            break;

        case 1:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t  Inserir Produto no Carrinho\n");
            inserirProdutoCarrinho(produtos, carrinho);
            break;
        
        case 2:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t   Remover Produto do Carrinho\n");
            removerProdutoCarrinho(produtos, carrinho);
            break;
        
        case 3:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t   Consultar Carrinho\n");
            listarCarrinho(carrinho);
            break;

        case 4:        
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t   Finalizar Compra\n");
            break;

        default:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t  Opção Invalida!!!\n");
            break;
        }
    }

}


int main() {
    int opt = 9;
    ListCarrinho *carrinho = malloc(sizeof(ListCarrinho));
    ListProduto *produtos = malloc(sizeof(ListProduto));
    
    carrinho->ultimo = NULL;
    carrinho->primeiro = NULL;

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
            excluirProdutos(produtos);
            break;

        case 5:
            printf("\n\n\n");
            printf("-------------------------------------\n");
            printf("\t   Comprar Produtos\n");
            mainCarrinho(produtos, carrinho);
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
