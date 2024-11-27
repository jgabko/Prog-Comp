#include <stdio.h>
#include <string.h>
#include "user_consulta.h"
#include "cadastro.h"
#include "consulta.h"
#include "pedido_searchs.h"
#include <stdio.h>
#include <string.h>
#include "cadastro.h"
#include <stdio.h>
#include <string.h>
#include "cadastro.h"

int main(){
    int resposta_main;
    printf("1.Users\n2.Pedidos");
    scanf("%d",&resposta_main);

    switch (resposta_main)
    {
     case 1:
     menu_user();

     case 2:
    pedido_menu();
        
    
    default:
        break;
    }








}