# Busca Sequencial de Clientes (Python)

Esta pasta abriga o projeto de busca de clientes utilizando o algoritmo de busca sequencial em Python, dessa forma, é necessário ter uma versão do Python 3.x instalado no seu computador. Neste arquivo você verá:

- [Organização do repositório;] (#1-organização-do-repositório)
- [Busca Sequencial na linguagem Python;] (#2-busca-sequencial-na-linguagem-python)
- [Execução do projeto;] (#3-execução-do-projeto)

## 1. Organização do repositório:

A organização desta parte está disposta da seguinte forma:

``` 
📁 - BuscaSequencialClientes
│
└───linguagem_python
        │
        ├──cliente.py
        ├──clientes.txt
        ├──main.py
        └── README.md
```

## 2. Busca Sequencial na linguagem Python:

A implementação da **Busca Sequencial** deste projeto é dada no arquivo `cliente.py` de forma que é aplicada em três funções para diferentes termos. Dessa forma, para cada linha do arquivo `clientes.txt` é criado um vetor das palavras dela. Assim, é feita uma comparação para verificar se o termo buscado se encontra na linha.


As funções de busca são:

- `procura_nome`: Procura um cliente pelo nome no arquivo clientes.txt;

```
    # laço de repetição referente a busca sequencial pelo nome do cliente (linha por linha)
    for linha in arquivo:
        resultado = linha.split("\t")

        # caso a busca seja bem-sucedida, imprime os dados dos clientes
        if nome in resultado[2]:
            busca = True
            print("-" * 50)
            print(f"{'Nome':<20}{'Cidade':<20}{'Código':<20}")
            print("-" * 50)
            print(f"{resultado[0]:<20}{resultado[1]:<20}{resultado[2]:<20}")
    print("-" * 50)
    
    # caso a busca não for bem sucedida, será exibido que o cliente não foi encontrado
    if busca == False:
        print("Cliente não encontrado!")
``` 

###### Trecho em que ocorre a busca sequencial na função procura_nome


- `procura_codigo`: Procura um cliente pelo código no arquivo clientes.txt.

```
    # laço de repetição referente a busca sequencial pelo codigo (linha por linha)
    for linha in arquivo:
        
        resultado = linha.split("\t")
        resultado[2] = resultado[2].replace("\n", "")
        
        # caso a busca seja bem-sucedida, imprime os dados dos clientes
        if codigo in resultado:
            busca = True
            print("-" * 50)
            print(f"{'Nome':<20}{'Cidade':<20}{'Código':<20}")
            print("-" * 50)
            print(f"{resultado[0]:<20}{resultado[1]:<20}{resultado[2]:<20}")
            break;
    print("-" * 50)
    
    # caso a busca não for bem sucedida, será exibido que o cliente não foi encontrado
    if busca == False:
        print("Cliente não encontrado!")
``` 

###### Trecho em que ocorre a busca sequencial na função procura_codigo

- `verifica_codigo`: verifica se o código já existe no arquivo.

```
    # laço de repetição referente a busca sequencial na verificação do código a ser adicionado (linha por linha)
    for linha in arquivo:
        
        resultado = linha.split("\t")
        resultado[2] = resultado[2].replace("\n", "")
        
        if str(codigo) in resultado:
            busca = True
            break;
    
    return busca
``` 

###### Trecho em que ocorre a busca sequencial na função verifica_codigo

## 3. Execução do projeto:

Para uma boa execução do projeto, garanta-se de, no **terminal** está no caminho da pasta `linguagem_python`. Além disso, há uma diferençã de execução para os diferentes tipos de sistema operacional. 

- Windows: Não é necessário mudar o código original, a constante de sistema operacional já está correta.

```SISTEMA_OPERACIONAL = "cls"```
###### Linha 3 do arquivo cliente.py

- Linux: É necessário a mudança da constante `SISTEMA_OPERACIONAL` presente na linha 3 do arquivo cliente.py. Garanta-se de salvar a mudança.

```SISTEMA_OPERACIONAL = "clear"```
###### Linha 3 do arquivo cliente.py

Por fim, execute a seguinte linha de comando **no caminho linguagem_python**:

```python main.py```
