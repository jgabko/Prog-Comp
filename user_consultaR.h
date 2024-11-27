#include <stdio.h>
#include <string.h>
#include "cadastro.h"
#ifndef USER_CONSULTAR_H
#define USER_CONSULTAR_H

int UserPorCPF(int cpf) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    User user;
    int found = 0;
    while (fscanf(file, "%99[^,],%d,%d,%d,%29[^,],%99[^\n]\n", user.nome, &user.idade, &user.cpf, &user.cep, user.nacionalidade, user.email) != EOF) {
        if (user.cpf == cpf) {
            found = 1;
            return cpf;
        }
    }
    
    if (!found) {
        printf("Usuário com CPF %d não encontrado.\n", cpf);
        return -1;
    }
    
    fclose(file);
}



int user_consultaR(int cpfConsulta) {
 
        UserPorCPF(cpfConsulta);
        return cpfConsulta;
        
   


}
#endif