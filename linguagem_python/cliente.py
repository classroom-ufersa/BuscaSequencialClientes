import os
from time import sleep

def cabeçalho(divisoria, titulo):
    """Imprime um cabeçalho com um título centralizado
    
    Args:
        divisoria (str): Caractere que será repetido 50 vezes
        titulo (str): Título que será centralizado
    Returns:
        None    
    """
    print(divisoria * 50)
    print(f"{titulo:^50}")
    print(divisoria * 50)

def adiciona_cliente():
    """Adiciona um cliente ao arquivo clientes.txt
    
    Args:
        None
    Returns:
        None
    """

    # abrir o arquivo 'clientes.txt' em modo de escrita
    arquivo = open('clientes.txt', 'a')
    
    # criação de um dicionário vazio chamado clientes
    cliente = {}
    
    cabeçalho("-", "Adicionar cliente")
    
    # solicitam os dados do usuário
    nome = (input("Digite o nome do cliente: ")).title()
    cidade = input("Digite a cidade do cliente: ")

    # verificando se o código é um inteiro
    while True:
        try:
            codigo = int(input("Digite o código de cliente: "))
            break
        except ValueError:
            print('Insira um código válido')

    while True:
        if verifica_codigo(codigo):
            print("Código já existente!")
            # verificando se o código é um inteiro
    
            # verificando novamente se é um inteiro
            while True:
                try:
                    codigo = int(input("Digite o código de cliente: "))
                    break
                except ValueError:
                    print('Insira um código válido')
        else:
            break


    cliente['nome'] = nome
    cliente['cidade'] = cidade
    cliente['codigo'] = codigo
    
    # Os dados do cliente são escritos no arquivo 'clientes.txt'
    arquivo.write(f"{cliente['nome']}\t{cliente['cidade']}\t{cliente['codigo']}\n")
    arquivo.close()

def lista_clientes():
    """Lista os clientes do arquivo clientes.txt
    Args:
        None
    Returns:
        None
    """

    # abre o arquivo 'clientes.txt' no modo leitura
    arquivo = open('clientes.txt', 'r')
    
    print("-" * 50)
    print(f"{'Nome':<20}{'Cidade':<20}{'Código':<20}")
    print("-" * 50)
    
    # laço de repetição para listar os clientes
    for linha in arquivo:
        resultado = linha.split("\t")
        print(f"{resultado[0]:<20}{resultado[1]:<20}{resultado[2]:<20}")
    print("-" * 50)
    a = input("Pressione enter para continuar...")
    arquivo.close()

def procura_codigo():
    """Procura um cliente pelo código no arquivo clientes.txt
    Args:
        None
    Returns:
        None
    """

    # abre o arquivo 'clientes.txt' em modo leitura 
    arquivo = open('clientes.txt', 'r')
    
    # verificando se o código é um inteiro
    while True:
        try:
            codigo = int(input("Digite o código de cliente: "))
            break
        except ValueError:
            print('Insira um código válido')

    busca = False
    
    cabeçalho("-", "Resultado da busca por código")
    
    # laço de repetição referente a busca sequencial pelo codigo (linha por linha)
    for linha in arquivo:
        
        resultado = linha.split("\t")
        resultado[2] = resultado[2].replace("\n", "")
        
        # caso a busca seja bem-sucedida, imprime os dados dos clientes
        if str(codigo) in resultado:
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
        
    a = input("Pressione enter para continuar...")

    # fecha o arquivo 'clientes.txt' que foi aberto anteriomente para leitura
    arquivo.close()
    
def procura_nome():
    """Procura um cliente pelo nome no arquivo clientes.txt
    Args:
        None
    Returns:
        None
    """
    arquivo = open('clientes.txt', 'r')
    nome = (input("Digite o nome do cliente: ")).title()
    busca = False
    
    cabeçalho("-", "Resultado da busca por nome")
    
    # laço de repetição referente a busca sequencial pelo nome do cliente (linha por linha)
    for linha in arquivo:
        resultado = linha.split("\t")

        # caso a busca seja bem-sucedida, imprime os dados dos clientes
        if nome in resultado:
            busca = True
            print("-" * 50)
            print(f"{'Nome':<20}{'Cidade':<20}{'Código':<20}")
            print("-" * 50)
            print(f"{resultado[0]:<20}{resultado[1]:<20}{resultado[2]:<20}")
    print("-" * 50)
    
    # caso a busca não for bem sucedida, será exibido que o cliente não foi encontrado
    if busca == False:
        print("Cliente não encontrado!")
        
    a = input("Pressione enter para continuar...")
    # fecha o arquivo 'clientes.txt' que foi aberto anteriomente para leitura
    arquivo.close()

def verifica_codigo(codigo):
    """Procura um cliente pelo código no arquivo clientes.txt para verificar se já há algum com esse código.
    Args:
        codigo (int): codigo a ser verficado se já existe.
    Returns:
        bool: valor a ser retornado. True se já existir, False caso contrário.
    """

    arquivo = open('clientes.txt', 'r')

    busca = False
    
    # laço de repetição referente a busca sequencial da existência do código no arquivo(linha por linha)
    for linha in arquivo:
        
        resultado = linha.split("\t")
        resultado[2] = resultado[2].replace("\n", "")

        # caso o código exista no arquivo
        if str(codigo) in resultado:
            busca = True
            break;
    
    return busca

def menu():
    """Menu principal do programa
    
    Args:
        None
    Returns:
        functon: menu (itself)
    
    """
    cabeçalho("=", "Menu principal")
    
    print("1|\t Adicionar cliente")
    print("2|\t Listar clientes")
    print("3|\t Procurar cliente por código")
    print("4|\t Procurar cliente por nome")
    print("5|\t Sair")
    print("-" * 45)
    
    opcao = input("Escolha uma opção: ")
    
    if opcao == "1":
        os.system('cls')
        adiciona_cliente()
        sleep(1)
        os.system('cls')
        return menu()
    elif opcao == "2":
        os.system('cls')
        lista_clientes()
        os.system('cls')
        return menu()
    elif opcao == "3":
        os.system('cls')
        procura_codigo()
        os.system('cls')
        return menu()
    elif opcao == "4":
        os.system('cls')
        procura_nome()
        os.system('cls')
        return menu()
    elif opcao == "5":
        print("Saindo...")
        sleep(1)
        os.system('cls')
    else:
        print("Opção inválida!")
        sleep(1)
        os.system('cls')
        return menu()
