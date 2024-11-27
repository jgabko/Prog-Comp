#include <stdio.h>
#include <string.h>
#include "cadastro.h"
#ifndef USER_CONSULTA_H
#define USER_CONSULTA_H

void UserPorCPF(int cpf) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    User user;
    int found = 0;
    while (fscanf(file, "%99[^,],%d,%d,%d,%29[^,],%99[^\n]\n", user.nome, &user.idade, &user.cpf, &user.cep, user.nacionalidade, user.email) != EOF) {
        if (user.cpf == cpf) {
            printf("Nome: %s\nIdade: %d\nCPF: %d\nCEP: %d\nNacionalidade: %s\nEmail: %s\n", user.nome, user.idade, user.cpf, user.cep, user.nacionalidade, user.email);
            found = 1;
            return cpf;
        }
    }
    
    if (!found) {
        printf("Usuário com CPF %d não encontrado.\n", cpf);
    }
    
    fclose(file);
}

void UserPorNome(char *nomeConsulta) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    User user;
    int found = 0;
    while (fscanf(file, "%99[^,],%d,%d,%d,%29[^,],%99[^\n]\n", user.nome, &user.idade, &user.cpf, &user.cep, user.nacionalidade, user.email) != EOF) {
        if (strcmp(user.nome, nomeConsulta) == 0) {
            printf("Nome: %s\nIdade: %d\nCPF: %d\nCEP: %d\nNacionalidade: %s\nEmail: %s\n", user.nome, user.idade, user.cpf, user.cep, user.nacionalidade, user.email);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Usuário com nome %s não encontrado.\n", nomeConsulta);
    }
    
    fclose(file);
}

void user_consulta() {
    int escolha_cpf_nome;
    int retorno_user;
    printf("1. Pesquisar por CPF\n2. Pesquisar por nome\nEscolha uma opção: ");
    scanf("%d", &escolha_cpf_nome);

    if (escolha_cpf_nome == 1) {
        int cpfConsulta;
        printf("Digite o CPF para consultar: ");
        scanf("%d", &cpfConsulta);
        UserPorCPF(cpfConsulta);
        
    } else if (escolha_cpf_nome == 2) {
        char nomeConsulta[100];
        printf("Digite o nome para consultar: ");
        scanf("%99s", nomeConsulta);
        UserPorNome(nomeConsulta);
        
    } else {
        printf("Opção inválida.\n");
   
    }

    return 0;

}
#endif