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


#ifndef USER_EXC_H
#define USER_EXC_H

int delete_user(int target_cpf) {
    FILE *file = fopen("users.txt", "r");
    FILE *tempFile = fopen("temp_users.txt", "w");
    if (file == NULL || tempFile == NULL) {
        perror("Failed to open file");
        return -1;
    }

    User user;
    int found = 0;

    while (fread(&user, sizeof(User), 1, file)) {
        if (user.cpf == target_cpf) {
            found = 1;
            continue; // Skip writing this user to the temp file
        }
        fwrite(&user, sizeof(User), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("User with CPF %d not found.\n", target_cpf);
        remove("temp_users.txt");
        return -1;
    }

    // Replace the original file with the temp file
    remove("users.txt");
    rename("temp_users.txt", "users.txt");

    printf("User deleted successfully.\n");
    return 0;
}


int deactivate_user(int target_cpf) {
    FILE *file = fopen("users.txt", "r+");
    if (file == NULL) {
        perror("Failed to open file");
        return -1;
    }

    User user;
    int found = 0;
    long pos;

    while (fread(&user, sizeof(User), 1, file)) {
        if (user.cpf == target_cpf) {
            user.status = 0; // Set status to inactive
            pos = ftell(file) - sizeof(User);
            fseek(file, pos, SEEK_SET);
            fwrite(&user, sizeof(User), 1, file);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("User with CPF %d not found.\n", target_cpf);
        return -1;
    }

    printf("User status updated successfully.\n");
    return 0;
}
#endif