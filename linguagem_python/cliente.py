import os
from time import sleep
SISTEMA_OPERACIONAL = "cls" #definido para windows

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

def valida_codigo(verificar_existencia):
    """Valida o código do cliente, vendo se é um número, além de verificar se já existe um cliente com esse código
    de acordo com o parâmetro passado.

    Args:
        verificar_existencia (bool): Parâmetro que indica se a função deve verificar se o código já existe.

    Returns:
        int: Código do cliente válido
    """
    
    while True:
        try:
            codigo = int(input("Digite o código de cliente: "))
            break
        except ValueError:
            print('Insira um código válido')

    if verificar_existencia:
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
            
    return codigo

def valida_string(mensagem):
    """Valida uma string, verificando se é vazia ou se contém apenas espaços em branco. 
    Também verifica se contém números ou caracteres especiais.
    
    Args:
        mensagem (str): Mensagem que será exibida ao usuário
    Returns:
        string: string válida e formatada com a primeira letra de cada palavra em maiúsculo.
    """
    while True:
        string = input(mensagem)
        if string.strip() == "":
            print("Digite algo válido!")
        elif not ((string).replace(" ", "")).isalpha():
            print("Não é permitido números ou caracteres especiais!")
        else:
            break
    
    return string.title()

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
    
    nome = valida_string("Digite o nome do cliente: ")
    cidade = valida_string("Digite a cidade do cliente: ")
    codigo = valida_codigo(verificar_existencia=True)

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
    a = input("Pressione ENTER para continuar...")
    arquivo.close()

def procura_codigo():
    """Procura um cliente pelo código no arquivo clientes.txt
    Args:
        None
    Returns:
        None
    """

    arquivo = open('clientes.txt', 'r')
    codigo = valida_codigo(verificar_existencia=False)

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
        
    a = input("Pressione ENTER para continuar...")

    arquivo.close()
    
def procura_nome():
    """Procura um cliente pelo nome no arquivo clientes.txt
    Args:
        None
    Returns:
        None
    """
    arquivo = open('clientes.txt', 'r')
    nome = valida_string("Digite o nome do cliente: ")
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
        
    a = input("Pressione ENTER para continuar...")
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
        os.system(SISTEMA_OPERACIONAL)
        adiciona_cliente()
        sleep(1)
        os.system(SISTEMA_OPERACIONAL)
        return menu()
    elif opcao == "2":
        os.system(SISTEMA_OPERACIONAL)
        lista_clientes()
        os.system(SISTEMA_OPERACIONAL)
        return menu()
    elif opcao == "3":
        os.system(SISTEMA_OPERACIONAL)
        procura_codigo()
        os.system(SISTEMA_OPERACIONAL)
        return menu()
    elif opcao == "4":
        os.system(SISTEMA_OPERACIONAL)
        procura_nome()
        os.system(SISTEMA_OPERACIONAL)
        return menu()
    elif opcao == "5":
        print("Saindo...")
        sleep(1)
        os.system(SISTEMA_OPERACIONAL)
    else:
        print("Opção inválida!")
        sleep(1)
        os.system(SISTEMA_OPERACIONAL)
        return menu()