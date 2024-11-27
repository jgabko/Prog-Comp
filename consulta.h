#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"
#include "user_consulta.h"
#include "pedido_searchs.h"  


int pedido_user(){
    int cpf_alvo;
    int check;
    printf("Qual user deseja fazer pedido:");
    scanf("%d",&cpf_alvo);
    check=user_consultaR(cpf_alvo);
    return user_consultaR(cpf_alvo);

}


int searchPedidoNum(int num_pedido) {
    FILE *file = fopen("pedido.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Pedido pedidos[100];
    int count = 0;
    while (fscanf(file, "%d,%d,%49s[^\n]\n", &pedidos[count].num_pedido, &pedidos[count].preco, pedidos[count].user) != EOF) {
        count++;
    }
    fclose(file);

    ordenarPedidos(pedidos, count);

    Pedido *result = buscarPedido(pedidos, count, num_pedido);

    if (result != NULL) {
        printf("Pedido encontrado: Num: %d, Preço: %d, User: %s\n", result->num_pedido, result->preco, result->user);
    } else {
        printf("Pedido não encontrado.\n");
    }
}

void pedido_menu() {
    int escolha;
    int pedido_cpf;
    printf("1. Fazer pedido\n2. Pesquisar pedido\n3. Cancelar pedido\nEscolha uma opção: ");
    scanf("%d", &escolha);

    pedido_cpf=pedido_user();

    if (escolha == 1) {
        Pedido pedido;
        printf("Número do pedido: ");
        scanf("%d", &pedido.num_pedido);
        printf("Preço: ");
        scanf("%d", &pedido.preco);
        pedido.user=pedido_cpf;
        writePedidoToFile(pedido);
    } else if (escolha == 2) {
        int num_pedido;
        printf("escolha um user:");
        user_consulta();
        printf("Número do pedido para pesquisar: ");
        scanf("%d", &num_pedido);
        searchPedidoNum(num_pedido);
    } else if (escolha == 3) {
        int num_pedido;
        printf("Número do pedido para cancelar: ");
        scanf("%d", &num_pedido);
        deletePedidoFromFile(num_pedido);
    } else {
        printf("Opção inválida.\n");
    }

    return 0;
}