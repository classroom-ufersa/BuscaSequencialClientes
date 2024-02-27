# Busca de Clientes utilizando Busca Sequencial 

Esse projeto foi desenvolvido como parte de uma avaliação para a disciplina de Estrutura de Dados I, utilizando a busca sequencial. Neste repositório, você encontrará a implementação do algoritmo de busca sequencial em Python e em C.

- [Projeto em Python](https://github.com/classroom-ufersa/BuscaSequencialClientes/tree/main/linguagem_python)
- [Projeto em C](https://github.com/classroom-ufersa/BuscaSequencialClientes/tree/main/linguagem_c)

## O que é Busca Sequencial?

A busca sequencial é um método simples de busca em que os elementos de uma coleção (como um array ou lista) são examinados um a um até que o item desejado seja encontrado ou até que todos os elementos tenham sido verificados. É um processo linear que percorre os elementos em ordem, comparando cada um deles com o valor procurado.

![image](https://github.com/classroom-ufersa/BuscaSequencialClientes/assets/126128839/31ab2fec-97ea-4d2d-8785-719695f6bcee)
###### Figura 1: exemplo de busca sequencial em um vetor de inteiros. Fonte: [USP - Resolução de Problemas Usando Python](https://panda.ime.usp.br/panda/static/pythonds_pt/05-OrdenacaoBusca/BuscaSequencial.html).



## Como funciona a Busca Sequencial? 
O algoritmo começa examinando o primeiro elemento da array e compara seu valor com o que está sendo procurado.Se houver uma correspondência, a busca é concluída e a posição ou o elemento é retornado como resultado. Caso o valor procurado não seja encontrado no primeiro elemento, o algoritmo avança para o próximo elemento na sequência.   

Esse processo de comparação e avanço é repetido até que o valor desejado seja localizado ou até que todos os elementos da coleção tenham sido verificados. Se o valor não for encontrado, a busca sequencial geralmente retorna um indicativo, como -1, para indicar que o valor não está presente na coleção.

## Como o repositório está organizado:
O repositório está organizado da seguinte forma:

``` 
📁 - BuscaSequencialClientes
│
└───assets
        │
        ├── complexidade_espacial_temporal_codigo.png
        ├── complexidade_espacial_temporal_nome.png
        ├── melhor_caso_tempo.png
        ├── melhor_caso_tempo_nome.png
        ├── pior_caso_tempo.png
        └── pior_caso_tempo_nome.png
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
        ├──main.py
        └── README.md
│
└─── .gitignore
└─── README.md
```
###### Organização do repositório

## Referências utlizadas:
- [OPERAÇÃO DE BUSCA SEQUENCIAL](https://www.cin.ufpe.br/~garme/public/(ebook)Estruturas%20de%20Dados%20Usando%20C%20(Tenenbaum).pdf.)

- [Resolução de Problemas Usando Python](https://panda.ime.usp.br/panda/static/pythonds_pt/05-OrdenacaoBusca/BuscaSequencial.html)
