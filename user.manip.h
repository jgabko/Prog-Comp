#include <stdio.h>
#include <string.h>
#include "user_consulta.h"
#include "cadastro.h"
#include "consulta.h"
#include "pedido_searchs.h"
#include <stdio.h>
#include <string.h>
#include "cadastro.h"
#include "user_exc.h"



#ifndef USER_MANIP_H
#define USER_MANIP_H

void user_edit() {
    int edit_resp;
    int num_pedido2;
    int target_cpf;


    printf("Número de cpf para editar: ");
    scanf("%d", &num_pedido2);
    searchPedidoNum(num_pedido2);

    printf("Qual alteração deseja fazer?\n");
    printf("1. Desativar\n2. Excluir\n");
    scanf("%d", &edit_resp);

    switch (edit_resp) {
        case 1:
            if (deactivate_user(num_pedido2) == 0) {
                printf("Usuário desativado com sucesso.\n");
            }
            break;
        case 2:
        delete_user(num_pedido2);
            
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}



#endif