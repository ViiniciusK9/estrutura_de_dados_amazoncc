#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



int main() {

    int id, qnt;
    double pt;
    char des;


    scanf("%d", &id);
    scanf("%lf", &pt);
    scanf("%d", &qnt);

    des = "Coca-Cola";

    center_print("Coca-Cola", 50);


/*     printf("╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("║ \t\t\t .::Carrinho de Compras::.                      ║\n");
    printf("╠════╦════════════════════════════════════════════════════╦═══════╦═════╣\n");
    printf("║ ID ║                    DESCRIÇÂO                       ║ PREÇO ║ QNT ║\n");
    printf("╠════╬════════════════════════════════════════════════════╬═══════╬═════╣\n");
    printf("║ %d ║  %d                                         ║ %d  ║ %d  ║\n", id, des, pt, qnt);
    printf("╚════╩════════════════════════════════════════════════════╩═══════╩═════╝\n"); */
    return 0;

}