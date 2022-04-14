<h1 align="center">O Sistema da AmazonCC</h1>

Você foi contratado pelo seu Carl Seagan da AmazonCC para criar um sistema com o
qual ele possa controlar alguns detalhes do seu business. Seu Carl já definiu o que é mais
importante, para que você comece a criar a estrutura do sistema para o melhor e-commerce do
sul do país. Os requisitos são os seguintes:
1. Seu programa principal (main) se chamará ```AmazonCC```.
2. Crie uma estrutura ```Produto``` com os seguintes atributos: código, o nome (nome sem
espaço - pode usar o ```scanf(“%s”,))```, o preço de venda e a quantidade.
3. AmazonCC deverá ter obrigatoriamente uma lista de produtos chamada produto
4. A compra no site é anônima (para facilitar a implementação).
5. A compra corresponde a um usuário incluir itens no carrinho: o produto (o usuário vê o
nome mas a estrutura armazena o código) e a quantidade comprada. O programa
mostra o preço que seria a quantidade vezes o preço do produto.
6. Crie um menu interativo que pergunta ao usuário o que deseja fazer:
   1. Cadastrar produto;
   2. Listar produtos;
   3. Buscar produto;
   4. Excluir produto;
   5. Comprar produtos (criar o carrinho);
   6. Sair do sistema;
7. O que acontece em cada item do menu:
   1. Ao escolher a ```Opção Cadastrar produto```: Leia valores via teclado e insira na lista. Não são permitidos dois produtos com o mesmo código.
   2. Ao escolher a ```Opção Listar produtos```: Mostre os dados de todos os produtos.
   3. Ao escolher a ```Opção Buscar produto```: Peça um código do produto e mostre os
dados do produto. Caso o código não esteja cadastrado apresentar a mensagem
‘Produto não cadastrado!’
   4. Ao escolher a Opção ```Excluir produto```: Peça um código do produto e exclua o
produto que possuir este código.
   5. Ao escolher a ```Opção Comprar produtos```: Essa opção deve levar outro menu em
que o usuário vai escolhendo os produtos para compra (colocando no carrinho) e
o sistema mostra o valor total da compra a cada inserção do produto no carrinho.
Neste menu, o usuário poderá consultar o carrinho e também finalizar a compra.
Ao finalizar, é apresentado o conteúdo do carrinho e o controle volta para o
menu principal. Lembre que o usuário poderá tirar um item do carrinho. Também
lembre de verificar o estoque quando um item for colocado no carrinho. Quando
a compra for finalizada, o estoque deve ser atualizado de acordo.
   6. Ao escolher a ```Opção Sair do sistema```: Saia do sistema e limpe a memória.

## Avaliação
- A avaliação será realizada considerando a apresentação do código e as funcionalidades
implementadas.
- O trabalho pode ser realizado em dupla, porém, a avaliação considera não só o
resultado final mas a participação e engajamento da equipe no desenvolvimento. Assim,
os membros da dupla podem ter notas distintas.
- Códigos que não sejam corretamente identados sofrerão duras penalidades.
- Reaproveitamento de código.
   - ○ Utilizar TAD de maneira adequada.
- A criatividade no desenvolvimento será recompensada.
   - Por exemplo, utilizar uma BST para agilizar a busca dos dados (opcional)

## Dicas
- Você pode utilizar as seguintes estruturas para implementar seu sistema

```c
struct _product {
    int code;
    char name[30];
    float price;
    int qt_stock;
    struct _product *next, *prev;
};
typedef struct _product Product;

typedef struct {
    Product *head;
    Product *tail;
} LProduct;

struct _cart {
    int codeprod;
    int qt_buy;
    struct _product *next, *prev;
};
typedef struct _cart Cart;
```
- A utilização de uma BST pode trazer mais desempenho para a busca das informações.
- A estrutura de dados para os produtos deve ser obrigatoriamente dinâmica. O carrinho
pode ser estático.
