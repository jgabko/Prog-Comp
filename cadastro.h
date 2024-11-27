#include <stdio.h>
#include <string.h>


#ifndef CADASTRO_H
#define CADASTRO_H
typedef struct {
    char nome[100];
    int idade;
    int cpf;
    int cep;
    char nacionalidade[30];
    char email[100];
    int  status;
} User;

int validateCPF(int cpf) {

    return cpf > 0;
}


void writeUserToFile(User user) {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(file, "%s,%d,%d,%d,%s,%s,%d\n", user.nome, user.idade, user.cpf, user.cep, user.nacionalidade, user.email,user.status);
    fclose(file);
}

void cadastro() {
    User user;
    
    printf("Qual seu nome? ");
    scanf("%99s", user.nome);
    user.status=0;
    
    printf("Qual sua idade? ");
    scanf("%d", &user.idade);
    
    printf("Qual seu CPF? ");
    scanf("%d", &user.cpf);
    
    if (!validateCPF(user.cpf)) {
        printf("CPF inválido.\n");
        return 1;
    }
    
    printf("Qual seu CEP? ");
    scanf("%d", &user.cep);
    
    printf("Qual sua nacionalidade? ");
    scanf("%29s", user.nacionalidade);
    
    printf("Qual seu email? ");
    scanf("%99s", user.email);
    
    writeUserToFile(user);
    
    printf("Cadastro realizado com sucesso!\n");
    
    return 0;
    
}
#endif