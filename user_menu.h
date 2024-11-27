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
#include "user.manip.h"



#ifndef USER_MENU_H
#define USER_MENU_H

void menu_user(){
int escolha_UserMenu;
printf("1.cadastro user\n2.pesquisar user\n3.Desativar/Excluir user");
scanf("%d",&escolha_UserMenu);

switch(escolha_UserMenu){

case 1:
    cadastro();
case 2:
    user_consulta();
case 3:
    user_edit();


}



}




#endif