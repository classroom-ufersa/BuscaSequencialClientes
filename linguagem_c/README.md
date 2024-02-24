# Busca Sequencial de Clientes (C)

Esta pasta abriga o projeto de busca de clientes utilizando o algoritmo de busca sequencial em C. Neste arquivo você verá:

- Pré-Requisitos;
- Organização do repositório;
- Busca Sequencial na linguagem C;
- Execução do projeto.

## 1. Pré-Requisitos:

Certifique-se de que você possui um compilador C instalado. Recomendamos o uso do [GCC](https://gcc.gnu.org/) para compilar o código.

## 2. Organização do repositório:

A organização desta parte está disposta da seguinte forma:

``` 
📁 - BuscaSequencialClientes
│
└───linguagem_c
        │
        ├──cliente.c
        ├──clientes.h
        ├──main.c
        └── README.md
```
## 3. Busca Sequencial na linguagem C:

A implementação da **Busca Sequencial** deste projeto é dada no arquivo `cliente.c` de forma que é aplicada em duas funções para diferentes termos. Dessa forma, para cada linha do arquivo `clientes.txt` é criado um vetor das palavras dela. Assim, é feita uma comparação para verificar se o termo buscado se encontra na linha. Caso encontre, será impresso o resultado, se não, será impresso `Cliente não encontrado!`

As funções de busca são:

- `procura_nome`: Procura um cliente pelo nome no arquivo clientes.txt;
```
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
``` 
###### Trecho do código em que ocorre a busca sequencial na função procura_nome

- `procura_codigo`: Procura um cliente pelo código no arquivo clientes.txt.
```
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
``` 
###### Trecho em que ocorre a busca sequencial na função procura_codigo

## 4. Execução do projeto:
### 4.1 Compilação do código:
Para compilar o código, abra o terminal e navegue até a pasta `linguagem_c` e execute o seguinte comando:
```
gcc -c cliente.c 
```
Seguido do 
```
gcc -c main.c
```
E por fim, para executar o código, digite o comando:
```
gcc -o main cliente.o main.o
```
**Observação:** O  "main" é o nome do arquivo executável que será gerado após a compilação, você pode escolher o nome que desejar.

### 4.2 Execução do código:
Para executar o código, digite o comando:
```
./main
```
## Referências utilizadas: 
[OPERAÇÃO DE BUSCA SEQUENCIAL.](https://www.cin.ufpe.br/~garme/public/(ebook)Estruturas%20de%20Dados%20Usando%20C%20(Tenenbaum).pdf.)
