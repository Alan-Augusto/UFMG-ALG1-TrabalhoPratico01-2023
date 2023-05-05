# UFMG-ALG1-TrabalhoPratico01-2023

Este repositório contém a solução do trabalho prático TP1 - Aritmofobia da disciplina de Algoritmos I.

## Descrição do problema
O objetivo deste trabalho é modelar o problema computacional descrito a seguir utilizando estruturas de dados e algoritmos, em particular aqueles vistos na disciplina, que permitam resolvê-lo de forma eficiente.

Steven Jodds sofre de um transtorno peculiar: ele tem fobia a números ímpares. Felizmente, esse problema não o impediu de se tornar um empresário de sucesso e viajar pelo país inteiro para realizar reuniões com clientes. Infelizmente, Steve também tem medo de viajar de avião e precisa fazer todas as viagens de carro.

Steve deseja criar um algoritmo para planejar melhor suas viagens. No entanto, devido à sua aversão a números ímpares, ele nunca conseguiu aprender a programar. Por isso, ele pediu a ajuda de um exímio programador – você – para ajudá-lo nessa tarefa. Steve quer criar um algoritmo que determine o menor caminho entre duas cidades, dado um grafo que representa a rede de cidades e estradas que interconectam a região. No entanto, seu algoritmo deve levar em consideração as peculiaridades de Steve:

1. Steve só viaja entre duas cidades adjacentes se a estrada que conecta as duas cidades tiver comprimento par;
2. O caminho traçado pelo algoritmo deve passar por um número par de estradas.

## Modelagem do problema
Este trabalho prático aborda a parte de grafos da ementa desta disciplina. Para a resolução do problema a sua modelagem precisa usar grafos e deve ser descrita sucintamente no relatório apresentado.

## Formato da entrada esperada

O programa deverá processar um caso de teste em cada execução. A primeira linha de um cenário de teste é composta de dois número inteiros N e A, representando respectivamente o número de cidades (2 ≤ N ≤ 10000) e o número de estradas conectando pares de cidades (1 ≤ A ≤ 100000).

Cada uma das próximas A linhas descreve uma estrada entre duas cidades, representadas pelo identificador de uma cidade de origem, um identificador de uma cidade de destino e o comprimento da estrada que liga diretamente as respectivas cidades. Os dois identificadores e o comprimento da estrada são representados por inteiros positivos, a saber X1, X2 e D, os quais devem satisfazer as seguintes condições: 1 ≤ X1, X2 ≤ N, X1 ≠ X2 e 0 < D ≤ 10000.

## Execução do programa
O programa pode ser executado através do arquivo main.cpp. Para executar o programa, basta abrir o terminal na pasta onde se encontra o arquivo main.py e digitar o comando abaixo:
~~~c++
main.cpp input.txt output.txt
~~~

Onde input.txt é o arquivo com os casos de teste de entrada e output.txt é o arquivo onde serão salvos os resultados.

## Autor
Trabalho executado por:
### Alan Augusto
Graduando em Sistemas de Informação pela UFMG
