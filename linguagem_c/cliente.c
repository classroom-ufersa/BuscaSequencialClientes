#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct cliente {
    char nome[100];
    char cidade[100];
    char codigo[100];
} Cliente;

void adiciona_cliente() {
}

void procura_codigo() {
    FILE *arquivo = fopen("clientes.txt", "r");
    
    char codigo[100], linha[256];
    int encontrou = 0;

    if(arquivo == NULL) {
        printf("Erro ao abrir o aquivo.\n");
        return;
    }

    printf("Busca por codigo");
    printf("Digite o código do cliente: ");
    fgets(codigo, 100, stdin);
    codigo[strcspn(codigo, "\n")] = 0; //função que garante que a string termine no local onde o usuário pressionou enter
    printf("%s \t %s \t %s\n", "Nome", "Cidade", "Codigo");

    while(fgets(linha, sizeof(linha), arquivo)) {
        char *token = strtok(linha, "\t"); //divide a string em partes com base no delimitador \t
        
        //realiza a comparação entre o código fornecido pelo usuário e os existentes
        if(strcmp(token, codigo) == 0) {
            printf("%s", linha);
            encontrou = 1;
            break;
        }
    }

    if(!encontrou) {
        printf("Cliente nao encontrado!\n");
    }

    fclose(arquivo);
}

void procura_nome() {
    FILE *arquivo = fopen("clientes.txt", "r");
    
    char nome[100], linha[256];
    int encontrou = 0;

    if(arquivo == NULL) {
        printf("Erro ao abrir o aquivo.\n");
        return;
    }

    printf("Busca por Nome");
    printf("Digite o nome do cliente: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = 0; //função que garante que a string termine no local onde o usuário pressionou enter

    printf("%s \t %s \t %s\n", "Nome", "Cidade", "Codigo");
    
    while(fgets(linha, sizeof(linha), arquivo)) {
        char *token = strtok(linha, "\t"); //divide a string em partes com base no delimitador \t

        if(strcmp(token, nome) == 0) {
            printf("%s", linha);
            encontrou = 1;
        }
    }

    if(!encontrou) {
        printf("Cliente nao encontrado!\n");
    }

    fclose(arquivo);
}

void cabecalho(char* linha, char* titulo) {
    printf("%s\n%s\n%s\n", linha, titulo, linha);
}

void menu() {
    char opcao[2];
    while (1) {
        cabecalho("=", "Menu principal");

        printf("1|\t Adicionar cliente\n");
        printf("2|\t Listar clientes\n");
        printf("3|\t Procurar cliente por código\n");
        printf("4|\t Procurar cliente por nome\n");
        printf("5|\t Sair\n");
        printf("---------------------------------------------\n");

        printf("Escolha uma opção: ");
        scanf("%1s", opcao);

        if (strcmp(opcao, "1") == 0) {
            system("clear");
            adiciona_cliente();
            sleep(1);
            system("clear");
        } else if (strcmp(opcao, "2") == 0) {
            system("clear");
            lista_clientes();
            system("clear");
        } else if (strcmp(opcao, "3") == 0) {
            system("clear");
            procura_codigo();
            system("clear");
        } else if (strcmp(opcao, "4") == 0) {
            system("clear");
            procura_nome();
            system("clear");
        } else if (strcmp(opcao, "5") == 0) {
            printf("Saindo...\n");
            sleep(1);
            system("clear");
            break;
        } else {
            printf("Opção inválida!\n");
            sleep(1);
            system("clear");
        }
    }
}