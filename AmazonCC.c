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
    char nome[255];
    struct _Carrinho *proximo;
    struct _Carrinho *anterior;

};
typedef struct _Carrinho Carrinho;

typedef struct {
    Carrinho *primeiro;
    Carrinho *ultimo;

} ListCarrinho;


void center_print(const char *s, int width){
    int length = strlen(s);
    int i;
    for (i=0; i<=(width-length)/2; i++) {
            fputs(" ", stdout);
    }
    fputs(s, stdout);
    i += length;
    for (; i<=width; i++) {
            fputs(" ", stdout);
    }
    printf("\n");
}


void linha(){
    printf("--------------------------------------------------\n");
}



// void table() {}


void menu() {
    linha();
    center_print("Amazon CC",50);
    linha();

    printf("\t0 - Sair do Sistema\n");
    linha();

    printf("\t1 - Cadastrar Produtos \n");
    linha();

    printf("\t2 - Listar Produtos\n");
    linha();

    printf("\t3 - Buscar Produtos\n");
    linha();

    printf("\t4 - Deletar Produtos\n");
    linha();

    printf("\t5 - Comprar Produtos\n");
    linha();
}


void menuListar() {
    linha();
    center_print("Amazon CC",50);
    linha();

    printf("\t0 - Voltar ao Menu Principal\n");
    linha();

    printf("\t1 - Listar Produtos em Ordem Crescente\n");
    linha();

    printf("\t2 - Listar Produtos em Ordem Decrescente\n");
    linha();
}


void menuBuscar() {
    linha();
    center_print("Amazon CC",50);
    linha();

    printf("\t0 - Voltar ao Menu Principal\n");
    linha();

    printf("\t1 - Buscar por Id\n");
    linha();

    printf("\t2 - Buscar por Nome\n");
    linha();

    printf("\t3 - Buscar Buscar por Preço\n");
    linha();

    printf("\t4 - Buscar Buscar por Quantidade\n");
    linha();
}


void menuCarrinho() {
    linha();
    center_print("Amazon CC",50);
    linha();

    printf("\t0 - Voltar ao Menu Principal\n");
    linha();

    printf("\t1 - Colocar Produto no Carrinho\n");
    linha();

    printf("\t2 - Remover Produto do Carrinho\n");
    linha();

    printf("\t3 - Consultar Carrinho\n");
    linha();

    printf("\t4 - Finalizar Compra\n");
    linha();
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
        return 1;
    } else {
        return 0;
    }
}


Produto *infoProdutos(){
    Produto *novoProduto = (Produto*)malloc(sizeof(Produto));

    linha();
    printf("Digite o ID: ");
    scanf("%d", &novoProduto->id);
    printf("\n");

    linha();
    printf("Digite a Descrição do Produto: ");
    scanf("%s", novoProduto->nome);   
    printf("\n");
    
    linha();
    printf("Digite o Preço do Produto: ");
    scanf("%lf", &novoProduto->preco);
    printf("\n");
 
    linha();
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
                linha();
                center_print("ID invalido",50);
                return;
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
    linha();
    center_print("Produto cadastrado com sucesso!",50);
    linha();    
}


void excluirProdutos(ListProduto * produtos){
    int id;
    printf("Digite o ID a ser excluido: ");
    scanf("%d", &id);
    Produto *auxFor;
    for(auxFor = produtos->primeiro; auxFor != NULL; auxFor = auxFor->proximo){
        if(auxFor->id == id){
            linha();
            center_print("Produto deletado com sucesso!",50);
            linha();
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
    linha();
    center_print("Produto não cadastrado!",50);
    linha();
    
}


void listarProdutos(ListProduto *produtos) {
    int opt = 9;

    while(opt != 0) {
        menuListar();
        scanf("%d", &opt);

        switch(opt) {
            case 0:
                linha();
                center_print("Voltar ao Menu Principal",50);
                break;

            case 1:
                linha();
                center_print("Listar em Ordem Crescente",50);
                Produto *aux1 = produtos->primeiro;
                if(produtosNulo(produtos)) {
                    linha();
                    center_print("Lista Vazia!",50);
                }else {
                    linha();
                    for(aux1; aux1!=NULL; aux1=aux1->proximo) {
                        printf(" Id: %d\n Descrição: %s\n Preço: %.2lf\n Quantidade: %d\n", aux1->id, aux1->nome, aux1->preco, aux1->quantidade);
                        linha();
                    }
                }
                break;
            
            case 2:
                linha();
                center_print("Listar em Ordem Decrescente",50);
                Produto *aux2 = produtos->ultimo;
                if(produtosNulo(produtos)) {
                    linha();
                    center_print("Lista Vazia!",50);
                }else {
                    linha();
                    for(aux2; aux2!=NULL; aux2=aux2->anterior) {
                        printf(" Id: %d\n Descrição: %s\n Preço: %.2lf\n Quantidade: %d\n", aux2->id, aux2->nome, aux2->preco, aux2->quantidade);
                        linha();
                    }
                }
                break;


            default:
                linha();
                center_print("Opção Invalida !",50);
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
        printf("Opção: ");
        scanf("%d", &opt);
        switch(opt) {
            case 0:
                center_print("Voltar ao menu Principal",50);           
                break;
            
            case 1:
                printf("Buscar por Id\n");
                printf("Digite o Id: ");
                int pk;
                achou = 1;
                scanf("%d", &pk);
                if(produtosNulo(produtos)) {
                    linha();
                    center_print("Lista Vazia!",50);
                }else {
                    for(auxBusca = produtos->primeiro; auxBusca!=NULL; auxBusca = auxBusca->proximo) {
                        if(auxBusca->id == pk) {
                            achou = 0;
                            printf(" Id: %d\n Descrição: %s\n Preço: %.2lf\n Quantidade: %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                        }
                    }
                    if(achou){
                        linha();
                        center_print("Produto não encontrado!",50);
                    }
                }
                break;

            case 2:
                printf("Buscar por Nome\n");
                printf("Digite o nome: ");
                scanf("%s", nome);
                achou = 1;
                if(produtosNulo(produtos)) {
                    linha();
                    center_print("Lista Vazia!",50);
                }else {
                    for(auxBusca = produtos->primeiro; auxBusca!=NULL; auxBusca = auxBusca->proximo) {
                        if(strcmp(auxBusca->nome, nome) == 0) {
                            achou = 0;
                            printf(" Id: %d\n Descrição: %s\n Preço: %.2lf\n Quantidade: %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                        }
                    }
                    if(achou){
                        linha();
                        center_print("Produto não encontrado!",50);
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
                    linha();
                    center_print("Lista Vazia!",50);
                }else {
                    for(auxBusca = produtos->primeiro; auxBusca!=NULL; auxBusca = auxBusca->proximo) {
                        if(auxBusca->preco == preco) {
                            achou = 0;
                            printf(" Id: %d\n Descrição: %s\n Preço: %.2lf\n Quantidade: %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                            return;
                        }
                    }
                    if(achou){
                        linha();
                        center_print("Produto não encontrado!",50);
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
                    linha();
                    center_print("Lista Vazia!",50);
                }else {
                    for(auxBusca = produtos->primeiro; auxBusca!=NULL; auxBusca = auxBusca->proximo) {
                        if(auxBusca->quantidade == qnt) {
                            achou = 0;
                            printf(" Id: %d\n Descrição: %s\n Preço: %.2lf\n Quantidade: %d\n", auxBusca->id, auxBusca->nome, auxBusca->preco, auxBusca->quantidade);
                        }
                    }
                    if(achou){
                        linha();
                        center_print("Produto não encontrado!",50);
                    }
                }
                break;

            default:
                linha();
                center_print("Opção Invalida !",50);
                break;
        }
    }
}


void listarCarrinho(ListCarrinho *carrinho){
    Carrinho *aux;
    double total = 0;
    if(carrinhoNulo(carrinho)){
        linha();
        center_print("Carrinho está vazio!",50);
    }else {
        for (aux = carrinho->primeiro; aux != NULL; aux = aux->proximo){
            total += (aux->preco * aux->quantidadeCarrinho);
            printf(" Id: %d\n Descrição: %s\n Preço: %.2lf\n Quantidade: %d\n", aux->idCarrinho, aux->nome, aux->preco, aux->quantidadeCarrinho);
            linha();
        }
        printf("\tTotal a pagar: R$ %.2lf\n", total);
        linha();

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


Produto *verificarPrecoProduto(ListProduto *produtos, int id){
    Produto *auxFor;
    for (auxFor = produtos->primeiro; auxFor != NULL; auxFor = auxFor->proximo){
        if(id == auxFor->id){
            return auxFor;
        }
    }
    return 0;
}


Carrinho *infoCarrinho(int id, char nome[255], int qnt, double preco){
    Carrinho *novoElemento = (Carrinho*)malloc(sizeof(Carrinho));
    novoElemento->idCarrinho = id;
    strcpy(novoElemento->nome, nome);
    novoElemento->quantidadeCarrinho = qnt;
    novoElemento->preco = preco;
    novoElemento->proximo = NULL;
    novoElemento->anterior = NULL;
    return novoElemento;
}


void inserirProdutoCarrinho(ListProduto *produtos, ListCarrinho *carrinho){
    int id, qnt;
    linha();
    printf("Digite o ID: ");
    scanf("%d", &id);
    printf("\n");
 
    linha();
    printf("Digite a Quantidade do Produto: ");
    scanf("%d", &qnt);
    printf("\n");
    if(verificarEstoque(produtos, id, qnt)) {
        if(verificarCarrinho(carrinho, id, qnt)){
            return;
        }else {
            Produto *aux2 = verificarPrecoProduto(produtos, id);
            Carrinho *aux = infoCarrinho(id, aux2->nome, qnt, aux2->preco);
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
        linha();
        center_print("Produto não cadastrado",50);
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


void finalizarCompra(ListProduto *produtos, ListCarrinho *carrinho){
    limparCarrinho(carrinho);
    Produto *auxFor;
    for(auxFor = produtos->primeiro; auxFor != NULL; auxFor = auxFor->proximo){
        if(auxFor->quantidade == 0){
            if(auxFor == produtos->primeiro && auxFor == produtos->ultimo){
                produtos->primeiro = NULL;
                produtos->ultimo = NULL;
                free(auxFor);
            }else if(auxFor == produtos->primeiro){
                auxFor->proximo->anterior = NULL;
                produtos->primeiro = auxFor->proximo;
                free(auxFor);
            }else if(auxFor == produtos->ultimo){
                auxFor->anterior->proximo = NULL;
                produtos->ultimo = auxFor->anterior;
                free(auxFor);
            }else{
                auxFor->anterior->proximo = auxFor->proximo;
                auxFor->proximo->anterior = auxFor->anterior;
                free(auxFor);
            }
        }
    }

    linha();
    center_print("Compra finalizada com sucesso!",50);

}


void removerProdutoCarrinho(ListProduto *produtos, ListCarrinho *carrinho){
    int id, qnt;
    linha();
    printf("Digite o ID: ");
    scanf("%d", &id);
    printf("\n");
 
    linha();
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
        linha();
        center_print("Id não encontrado",50);
    }
}


void mainCarrinho(ListProduto *produtos, ListCarrinho *carrinho){
    int opt = 9;

    while(opt != 0) {
        menuCarrinho();
        printf("Opção: ");
        scanf("%d", &opt);
        linha();
        switch(opt) {
        
        case 0:
            printf("\n\n\n");
            linha();
            center_print("Voltar ao Menu Principal",50);
            linha();
            break;

        case 1:
            printf("\n\n\n");
            linha();
            center_print("Inserir Produto no Carrinho",50); 
            inserirProdutoCarrinho(produtos, carrinho);
            break;
        
        case 2:
            printf("\n\n\n");
            linha();
            center_print("Remover Produto do Carrinho",50);
            linha();
            removerProdutoCarrinho(produtos, carrinho);
            break;
        
        case 3:
            printf("\n\n\n");
            linha();
            center_print("Consultar Carrinho",50);
            linha();
            listarCarrinho(carrinho);
            break;

        case 4:        
            printf("\n\n\n");

            linha();
            center_print("Finalizar Compra",50);
            linha();

            finalizarCompra(produtos, carrinho);
            break;

        default:
            printf("\n\n\n");
            linha();
            center_print("Opção Invalida!!!",50);
            linha();
            break;
        }
    }

}


void limparCarrinho(ListCarrinho *carrinho){
    Carrinho *auxForc = carrinho->primeiro;
    Carrinho *anteriorc;
    while(auxForc != NULL){
        anteriorc = auxForc;
        auxForc = auxForc->proximo;
        free(anteriorc);
    }
    carrinho->primeiro = NULL;
    carrinho->ultimo = NULL;
}


void limparMemoria(ListProduto *produtos, ListCarrinho *carrinho){
    limparCarrinho(carrinho);

    Produto *auxFor = produtos->primeiro;
    Produto *anterior;
    while(auxFor != NULL){
        anterior = auxFor;
        auxFor = auxFor->proximo;
        free(anterior);
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
        printf("Opção: ");
        scanf("%d", &opt);
        linha();

        
        switch(opt) {
        
        case 0:
            printf("\n\n\n");
            linha();
            center_print("Sair do Sistema!",50);
            linha();
            limparMemoria(produtos, carrinho);
            break;

        case 1:
            printf("\n\n\n");
            linha();
            center_print("Cadastrar Produtos",50);
            cadastroProdutos(produtos);
            break;
        
        case 2:
            printf("\n\n\n");
            linha();
            center_print("Listar Produtos",50);
            listarProdutos(produtos);
            break;
        
        case 3:
            printf("\n\n\n");
            linha();
            center_print("Buscar Produtos",50);
            buscarProdutos(produtos);
            break;

        case 4:        
            printf("\n\n\n");
            linha();
            center_print("Deletar Produtos",50);
            linha();
            excluirProdutos(produtos);
            break;

        case 5:
            printf("\n\n\n");
            linha();
            center_print("Comprar Produtos",50);
            mainCarrinho(produtos, carrinho);
            break;

        default:
            printf("\n\n\n");
            linha();
            center_print("Opção Invalida!!!",50);
            break;
        }
    }

    return 0;
}
// teste de acesso 
// gcc AmazonCC.c -o prog
