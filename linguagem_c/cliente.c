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
    //cria um cabeçalho centralizado
    printf("%s\t%s\t%s\n", linha, titulo, linha);
}

void pressiona_enter(){
    printf("\nPressione ENTER para continuar.");
    // Limpa o buffer de entrada
    while (getchar() != '\n');
    // Espera o usuário pressionar Enter
    getchar();
}

int numero_inteiroc(char *str) {
    //verifica se cada posição da string é um número
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int verifica_codigo(char *codigo_digitado) {
    //variáveis usadas na comparação 
    char linha[300];
    char codigo_arquivo[100];
    char cidade_arquivo[100];
    char nome_arquivo[100];

    //abre em modo de leitura
    FILE *arquivo = fopen("clientes.txt", "r"); 
    if (arquivo == NULL) {
        return 0; //verifica se o arquivo foi aberto ou não
    }

    //lê o arquivo linha por linha 
    while (fgets(linha, sizeof(linha), arquivo) != NULL) { 
        //verifica se o sscanf conseguiu interpretar os 3 campos da linha
        if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", nome_arquivo, cidade_arquivo, codigo_arquivo) == 3) {
            //verifica se o código lido é igual ao código fornecido via teclado
            if (strcmp(codigo_arquivo, codigo_digitado) == 0) {
                printf("\nCodigo ja existe.");
                fclose(arquivo);
                return 1; //código encontrado
            }
        }
    }

    fclose(arquivo);
    return 0; //código não encontrado
}

void adiciona_cliente() {
    //inicializa a struct Cliente
    Cliente cliente;
    //abre o arquivo no modo de escrita
    FILE *arquivo = fopen("clientes.txt", "a"); 
    //verifica se o arquivo foi aberto
    if(arquivo == NULL) { 
        printf("Erro ao abrir o aquivo.\n");
        return;
    }

    //codigo digitado via teclado para comparação
    char nome_digitado[100];
    char codigo_digitado[100]; 


    cabecalho("============", "Adiconar Cliente");
    do{
    printf("\nDigite o nome do cliente (apenas letras): ");
    scanf("%99[^\n]", nome_digitado);
    getchar();
    }while (!contem_apenas_letras(nome_digitado));
    
    //copia o que nome_digitado para a struct
    strcpy(cliente.nome, nome_digitado);

    printf("\nDigite a cidade do cliente: ");
    scanf(" %99[^\n]", cliente.cidade);
    getchar();

    //verifica se o código é um inteiro ou não e se já existe no arquivo 
    do{
    printf("\nDigite o codigo do cliente (apenas numeros inteiros): ");
    scanf("%99[^\n]", codigo_digitado);
    getchar();
    }while (!numero_inteiroc(codigo_digitado) || verifica_codigo(codigo_digitado));

    //copia o que codigo_digitado para a struct
    strcpy(cliente.codigo, codigo_digitado);

    //escreve os dados do cliente no arquivo 'clientes.txt'
    fprintf(arquivo, "\n%s \t %s \t %s \n", cliente.nome, cliente.cidade, cliente.codigo);

    fclose(arquivo);
}

void procura_codigo() {
    //variáveis usadas para comparação
    char codigo_digitado[100];
    char linha[300];

    //abre o arquivo no modo leitura
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    //verifica se o código digitado é inteiro
    do{
    printf("\nDigite o codigo do cliente (apenas numeros inteiros): ");
    scanf("%99[^\n]", codigo_digitado);
    getchar();
    }while (!numero_inteiroc(codigo_digitado));
  
    //variável para indentificar se encontrou ou não o cliente
    int encontrou = 0;
    //busca sequencial pelo código do cliente
    while (fgets(linha, sizeof(linha), arquivo)) {
        //variaveis para a comparação
        char nome[100], cidade[100], codigo_arquivo[100];
        //verifica se o sscanf conseguiu capturar os 3 campos;
        if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", nome, cidade, codigo_arquivo) == 3) {
            //compara o que foi digitado com o que tem no arquivo
            if (strcmp(codigo_arquivo, codigo_digitado) == 0) {
                printf("Cliente encontrado\n");
                printf("Nome: %s\nCidade: %s\nCodigo: %s\n", nome, cidade, codigo_arquivo);
                encontrou = 1; //cliente encontrado
                break;
            }
        }
    }

    if (!encontrou) {
        printf("Cliente nao encontrado!\n");
    }

    //pede para pressionar enter para sair da função
    pressiona_enter();

    fclose(arquivo);
}

int contem_apenas_letras(char *str) {
    //percorre cada posição na string 
    for (int index = 0; str[index] != '\0'; index++) {
        //compara se cada posição é uma letra e se não é um espaço
        if (!isalpha(str[index]) && str[index] != ' ') {
            printf("A string deve conter apenas letras.\n");
            return 0; //contem apenas letras
        }
    }
    return 1; //não contém apenas letras
}

void procura_nome() {
    //variáveis de comparação
    char nome_digitado[100];
    char linha[300];

    //arquivo aberto em modo leitura
    FILE *arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    //laço para verificar se o que foi digitado contém apenas letras
    do{
        printf("Digite o nome do cliente que deseja buscar: ");
        scanf(" %99[^\n ]", nome_digitado); 
    }while(!contem_apenas_letras(nome_digitado));
    
    //variável que define se o cliente foi ou não encontrado no arquivo
    int encontrou = 0;

    //percorre cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        //variáveis de comparação
        char nome_arquivo[100], cidade[100], codigo[100];
        //verifica se o sscanf capturou todos os 3 campos da linha
        if (sscanf(linha, "%99[^\t ]\t%99[^\t]\t%99[^\t ]", nome_arquivo, cidade, codigo) == 3) {
            //compara o que foi digitado com o que contém no arquivo
            if (strcmp(nome_arquivo, nome_digitado) == 0) {
                printf("Cliente encontrado\n");
                printf("Nome: %s\nCidade: %s\nCodigo: %s\n", nome_arquivo, cidade, codigo);
                encontrou = 1; //cliente encontrado
            }
        }
    }

    if (!encontrou) {
        printf("Cliente nao encontrado!\n");
    }

    //pede para pressionar enter para sair da função
    pressiona_enter();
    fclose(arquivo);
}

void lista_clientes(){
    //abre o arquivo no modo de leitura
    FILE *arquivo = fopen("clientes.txt", "r"); 
    char linha[300];

    //verifica se o arquivo foi aberto
    if(arquivo == NULL) {
        printf("Erro ao abrir o aquivo.\n");
        return;
    }
    
    //cabeçalho centralizado
    cabecalho("====", "Lista de clientes");
    //parte de cima da planilha
    printf("%s \t\t %s \t %s\n", "Nome", "Cidade", "Codigo");

    //lê o arquivo linha por linha 
    while(fgets(linha, sizeof(linha), arquivo)) {
        //imprime cada linha do arquivo
        printf("%s", linha); 
    }
    
    //pede para o usuário pressionar enter para sair da função
    pressiona_enter();

    fclose(arquivo);

} 

void menu() {
    //variável usada para navegar no menu
    char opcao[2];

    //laço de repetição "infinito"
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
        getchar();

        if (strcmp(opcao, "1") == 0) {
            system("clear"); //usado para limpar o terminal
            adiciona_cliente();
            sleep(1); //execução pausada por 1 segundo
            system("clear"); //usado para limpar o terminal
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