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

void cabecalho(char* linha, char* titulo) {
    printf("%s\t%s\t%s\n", linha, titulo, linha);
}

void pressiona_enter(){
    printf("\nPressione ENTER para continuar.");
    while (getchar() != '\n');
    getchar();
}

int numero_inteiroc(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void formata_string(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (i==0){
            str[0] = toupper(str[0]);
        }
        else{
            if (str[i - 1] == ' ') {
                str[i] = toupper(str[i]);
            } 
            else {
                str[i] = tolower(str[i]);
            }
        }
    }
}

int verifica_codigo(char *codigo_digitado) {
    char linha[300];
    char codigo_arquivo[100];
    char cidade_arquivo[100];
    char nome_arquivo[100];

    FILE *arquivo = fopen("clientes.txt", "r"); 
    if (arquivo == NULL) {
        return 0; 
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) { 
        if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", nome_arquivo, cidade_arquivo, codigo_arquivo) == 3) {
            if (strcmp(codigo_arquivo, codigo_digitado) == 0) {
                printf("\nCodigo ja existe.");
                fclose(arquivo);
                return 1; 
            }
        }
    }

    fclose(arquivo);
    return 0; 
}

void adiciona_cliente() {
    Cliente cliente;
    FILE *arquivo = fopen("clientes.txt", "a"); 
    if(arquivo == NULL) { 
        printf("Erro ao abrir o aquivo.\n");
        return;
    }

    char nome_digitado[100];
    char cidade_digitada[100];
    char codigo_digitado[100]; 


    cabecalho("============", "Adicionar Cliente");
    do{
    printf("\nDigite o nome do cliente (apenas letras): ");
    scanf("%99[^\n]", nome_digitado);
    getchar();
    }while (!contem_apenas_letras(nome_digitado));
    
    formata_string(nome_digitado);
    strcpy(cliente.nome, nome_digitado);

    do{
        printf("\nDigite a cidade do cliente (apenas letras): ");
        scanf("%99[^\n]", cidade_digitada);
        getchar();
    }while (!contem_apenas_letras(cidade_digitada));
        
    formata_string(cidade_digitada);
    strcpy(cliente.cidade, cidade_digitada);

    do{
    printf("\nDigite o codigo do cliente (apenas numeros inteiros): ");
    scanf("%99[^\n]", codigo_digitado);
    getchar();
    }while (!numero_inteiroc(codigo_digitado) || verifica_codigo(codigo_digitado));

    strcpy(cliente.codigo, codigo_digitado);

    fprintf(arquivo, "\n%s \t %s \t %s \n", cliente.nome, cliente.cidade, cliente.codigo);

    fclose(arquivo);
}

void procura_codigo() {
    char codigo_digitado[100];
    char linha[300];

    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    do{
    printf("\nDigite o codigo do cliente (apenas numeros inteiros): ");
    scanf("%99[^\n]", codigo_digitado);
    getchar();
    }while (!numero_inteiroc(codigo_digitado));
  
    int encontrou = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        char nome[100], cidade[100], codigo_arquivo[100];
        if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", nome, cidade, codigo_arquivo) == 3) {
            if (strcmp(codigo_arquivo, codigo_digitado) == 0) {
                printf("Cliente encontrado\n");
                printf("Nome: %s\nCidade: %s\nCodigo: %s\n", nome, cidade, codigo_arquivo);
                encontrou = 1;
                break;
            }
        }
    }

    if (!encontrou) {
        printf("Cliente nao encontrado!\n");
    }

    pressiona_enter();

    fclose(arquivo);
}

int contem_apenas_letras(char *str) {
    for (int index = 0; str[index] != '\0'; index++) {
        if (!isalpha(str[index]) && str[index] != ' ') {
            printf("A string deve conter apenas letras.\n");
            return 0; 
        }
    }
    return 1; 
}

void procura_nome() {
    char nome_digitado[100];
    char linha[300];

    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    do{
        printf("Digite o nome do cliente que deseja buscar: ");
        scanf(" %99[^\n]", nome_digitado);
    } while (!contem_apenas_letras(nome_digitado));
    int encontrou = 0;

    formata_string(nome_digitado);

    while (fgets(linha, sizeof(linha), arquivo)) {
        char nome_arquivo[100], cidade[100], codigo[100];
        if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", nome_arquivo, cidade, codigo) >= 2) {
            if (strcmp(nome_arquivo, nome_digitado) == 0 || strstr(nome_arquivo, nome_digitado) != NULL) {
                printf("Nome: %s\nCidade: %s\nCodigo: %s\n", nome_arquivo, cidade, codigo);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("Cliente nao encontrado!\n");
    }

    pressiona_enter();
    fclose(arquivo);
}

void lista_clientes(){
    FILE *arquivo = fopen("clientes.txt", "r"); 
    char linha[300];

    if(arquivo == NULL) {
        printf("Erro ao abrir o aquivo.\n");
        return;
    }
    
    cabecalho("====", "Lista de clientes");
    printf("%s \t\t %s \t %s\n", "Nome", "Cidade", "Codigo");

    while(fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha); 
    }
    
    pressiona_enter();

    fclose(arquivo);

} 

void menu() {
    char opcao[100];

    char sistema_operacional[10];
    strcpy(sistema_operacional, "cls");

    while (1) {
        cabecalho("============", "Menu principal");

        printf("1|\t Adicionar cliente\n");
        printf("2|\t Listar clientes\n");
        printf("3|\t Procurar cliente por codigo\n");
        printf("4|\t Procurar cliente por nome\n");
        printf("5|\t Sair\n");
        printf("---------------------------------------------\n");

        do{
        printf("Escolha uma opcao dentre as do menu: ");
        scanf(" %[^\n]", opcao);
        getchar();
        }while(!numero_inteiroc(opcao));

        if (strcmp(opcao, "1") == 0) {
            system(sistema_operacional); 
            adiciona_cliente();
            sleep(1); 
            system(sistema_operacional); 
        } else if (strcmp(opcao, "2") == 0) {
            system(sistema_operacional);
            lista_clientes();
            system(sistema_operacional);
        } else if (strcmp(opcao, "3") == 0) {
            system(sistema_operacional);
            procura_codigo();
            system(sistema_operacional);
        } else if (strcmp(opcao, "4") == 0) {
            system(sistema_operacional);
            procura_nome();
            system(sistema_operacional);
        } else if (strcmp(opcao, "5") == 0) {
            printf("Saindo...\n"); 
            sleep(1);
            system(sistema_operacional);
            break;
        } else {
            printf("Opcao invalida!\n");
            sleep(1);
            system(sistema_operacional);
        }
    }
}