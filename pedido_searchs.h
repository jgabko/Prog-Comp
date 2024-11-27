#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int num_pedido;
    int preco;
    int user;
} Pedido;

void ordenarPedidos(Pedido *pedidos, int count);
Pedido *buscarPedido(Pedido *pedidos, int count, int num_pedido);
void deletePedidoFromFile(int num_pedido);
void writePedidoToFile(Pedido pedido);
