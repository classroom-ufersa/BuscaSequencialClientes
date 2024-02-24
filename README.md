# Busca de Clientes utilizando Busca Sequencial 

Esse projeto foi desenvovido como parte de uma avaliação para a disciplina de Estrutura de Dados I, utilizando a busca sequencial. Neste repositório, você encontrará a implementação do algoritmo de busca sequencial em Python e em C.

## O que é Busca Sequencial?

A busca sequencial é um método simples de busca em que os elementos de uma coleção (como um array ou lista) são examinados um a um até que o item desejado seja encontrado ou até que todos os elementos tenham sido verificados. É um processo linear que percorre os elementos em ordem, comparando cada um deles com o valor procurado.

## Como funciona a Busca Sequencial? 
O algoritmo começa examinando o primeiro elemento da arrray e compara seu valor com o que está sendo procurado.Se houver uma correspondência, a busca é concluída, e a posição ou o elemento é retornado como resultado. Caso o valor procurado não seja encontrado no primeiro elemento, o algoritmo avança para o próximo elemento na sequência.   

Esse processo de comparação e avanço é repetido até que o valor desejado seja localizado ou até que todos os elementos da coleção tenham sido verificados. Se o valor não for encontrado, a busca sequencial geralmente retorna um indicativo, como -1, para indicar que o valor não está presente na coleção.

## Como o repositório está organizado:
O repositório está organizado da seguinte forma:

``` 
📁 - BuscaSequencialClientes
│
└───linguagem_c
        │
        ├──cliente.c
        ├──clientes.h
        ├──main.c
        └── README.md
│
└───linguagem_python
        │
        ├──cliente.py
        ├──clientes.txt
        ├──comentarios.txt
        ├──main.py
        └── README.md
│
└─── .gitignore
└─── README.md
```