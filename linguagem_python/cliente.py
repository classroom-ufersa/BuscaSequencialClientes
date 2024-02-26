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

    arquivo = open('clientes.txt', 'a')
    
    cliente = {}
    
    cabeçalho("-", "Adicionar cliente")
    
    nome = (input("Digite o nome do cliente: ")).title()
    cidade = input("Digite a cidade do cliente: ")

    while True:
        try:
            codigo = int(input("Digite o código de cliente: "))
            break
        except ValueError:
            print('Insira um código válido')

    while True:
        if verifica_codigo(codigo):
            print("Código já existente!")
    
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
    
    arquivo.write(f"{cliente['nome']}\t{cliente['cidade']}\t{cliente['codigo']}\n")
    arquivo.close()

def lista_clientes():
    """Lista os clientes do arquivo clientes.txt
    Args:
        None
    Returns:
        None
    """

    arquivo = open('clientes.txt', 'r')
    
    print("-" * 50)
    print(f"{'Nome':<20}{'Cidade':<20}{'Código':<20}")
    print("-" * 50)
    
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

    arquivo = open('clientes.txt', 'r')
    
    while True:
        try:
            codigo = int(input("Digite o código de cliente: "))
            break
        except ValueError:
            print('Insira um código válido')

    busca = False
    
    cabeçalho("-", "Resultado da busca por código")
    
    for linha in arquivo:
        
        resultado = linha.split("\t")
        resultado[2] = resultado[2].replace("\n", "")
        
        if str(codigo) in resultado:
            busca = True
            print("-" * 50)
            print(f"{'Nome':<20}{'Cidade':<20}{'Código':<20}")
            print("-" * 50)
            print(f"{resultado[0]:<20}{resultado[1]:<20}{resultado[2]:<20}")
            break;
    print("-" * 50)
    
    if busca == False:
        print("Cliente não encontrado!")
        
    a = input("Pressione enter para continuar...")

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
    
    for linha in arquivo:
        resultado = linha.split("\t")

        if nome in resultado[0]:
            busca = True
            print("-" * 50)
            print(f"{'Nome':<20}{'Cidade':<20}{'Código':<20}")
            print("-" * 50)
            print(f"{resultado[0]:<20}{resultado[1]:<20}{resultado[2]:<20}")
    print("-" * 50)
    
    if busca == False:
        print("Cliente não encontrado!")
        
    a = input("Pressione enter para continuar...")
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
    
    for linha in arquivo:
        
        resultado = linha.split("\t")
        resultado[2] = resultado[2].replace("\n", "")

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