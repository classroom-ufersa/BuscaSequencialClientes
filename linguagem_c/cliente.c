#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

typedef struct cliente {
    char nome[100];
    char cidade[100];
    char codigo[100];
} Cliente;

int numero_inteiroc(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int verifica_codigo(char *codigo_digitado){
    char linha[300];
    char codigo_arquivo[100];
    char cidade_arquivo[100];
    char nome_arquivo[100];
    FILE *arquivo = fopen("clientes.txt", "r"); // Abre em modo de leitura
    
    if (arquivo == NULL) {
        return 0; // verifica se o arquivo foi aberto ou não
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) { //lê o arquivo linha por linha 
        if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", nome_arquivo, cidade_arquivo, codigo_arquivo) == 3) {
            // Verifica se o código lido é igual ao código fornecido
            if (strcmp(codigo_arquivo, codigo_digitado) == 0) {
                printf("\nCodigo ja existe.");
                fclose(arquivo);
                return 1; // Código encontrado
            }
        }
    }

    fclose(arquivo);
    return 0; // Código não encontrado
}

void adiciona_cliente() {
    FILE *arquivo = fopen("clientes.txt", "a"); //abre o arquivo no modo de escrita
    Cliente cliente;
    
    if(arquivo == NULL) { //verifica se o arquivo foi aberto ou não
        printf("Erro ao abrir o aquivo.\n");
        return;
    }

    char codigo_digitado[100]; //codigo digitado via teclado para comparação

    cabecalho("============", "Adiconar Cliente");
    printf("\nDigite o nome do cliente: ");
    scanf(" %99[^\n]", cliente.nome);
    getchar(); // Limpa o buffer de entrada
    printf("\nDigite a cidade do cliente: ");
    scanf(" %99[^\n]", cliente.cidade);
    getchar();


    //verificar se o código é um inteiro ou não e se já existe no arquivo 
    do{
    printf("\nDigite o codigo do cliente: ");
    scanf("%99[^\n]", codigo_digitado);
    getchar();
    }while (!numero_inteiroc(codigo_digitado) || verifica_codigo(codigo_digitado));


    strcpy(cliente.codigo, codigo_digitado);

    // Escrever os dados do cliente no arquivo 'clientes.txt'
    fprintf(arquivo, "\n%s \t %s \t %s \n", cliente.nome, cliente.cidade, cliente.codigo);

    fclose(arquivo);
}

void procura_codigo() {
    FILE *arquivo = fopen("clientes.txt", "r");
    
    char codigo[100], linha[256];
    int encontrou = 0;

    if(arquivo == NULL) { 
        printf("Erro ao abrir o aquivo.\n");
        return;
    }

    cabecalho("=", "Busca por codigo");
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



void lista_clientes(){} // criei pra ver se dava certo o menu

void cabecalho(char* linha, char* titulo) {
    printf("%s\t%s\t%s\n", linha, titulo, linha);
}

void menu() {
    char opcao[2];
    while (1) {
        cabecalho("============", "Menu principal");

        printf("1|\t Adicionar cliente\n");
        printf("2|\t Listar clientes\n");
        printf("3|\t Procurar cliente por codigo\n");
        printf("4|\t Procurar cliente por nome\n");
        printf("5|\t Sair\n");
        printf("---------------------------------------------\n");

        printf("Escolha uma opcao: ");
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
            printf("Opcao invalida!\n");
            sleep(1);
            system("clear");
        }
    }
}