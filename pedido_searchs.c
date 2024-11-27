#include <stdio.h>
#include <stdlib.h>
#include "pedido_searchs.h"

int comparePedidos(const void *a, const void *b) {
    return ((Pedido *)a)->num_pedido - ((Pedido *)b)->num_pedido;
}

void ordenarPedidos(Pedido *pedidos, int count) {
    qsort(pedidos, count, sizeof(Pedido), comparePedidos);
}

Pedido *buscarPedido(Pedido *pedidos, int count, int num_pedido) {
    Pedido key = {.num_pedido = num_pedido};
    return bsearch(&key, pedidos, count, sizeof(Pedido), comparePedidos);
}

void deletePedidoFromFile(int num_pedido) {
    FILE *file = fopen("pedido.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Pedido pedido;
    while (fscanf(file, "%d,%d,%49[^\n]\n", &pedido.num_pedido, &pedido.preco, pedido.user) != EOF) {
        if (pedido.num_pedido != num_pedido) {
            fprintf(tempFile, "%d,%d,%s\n", pedido.num_pedido, pedido.preco, pedido.user);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("pedido.txt");
    rename("temp.txt", "pedido.txt");
}

void writePedidoToFile(Pedido pedido) {
    FILE *file = fopen("pedido.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(file, "%d,%d,%s\n", pedido.num_pedido, pedido.preco, pedido.user);
    fclose(file);


    
}