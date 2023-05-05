#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include "graph.hpp"

using namespace std;

//ler a linha de comando
char* checkLineArguments(int argc, char **argv, int x){
    if(argc < 2){
        cout << "--------Few arguments---------" << endl;
        cout << "---provide the file address---" << endl;
        exit(0);
    }
    return argv[x];
}


void Assert(bool x, string text){
    if(!x){
        if(text == ""){
            cout << text;
            exit(0);
        }
        cout << text << endl;
        exit(0);
    }
}


int main(int argc, char  **argv) {
    
    //Recolhe endereço do arquivo e confere os argumentos:
    //char *inputNameArq = checkLineArguments(argc, argv, 1);
    
    //Variaveis principais
    //ifstream InputFile(inputNameArq);
    //Assert(InputFile.is_open(), "Opening error in input file");


    Grafo grafo(5); // cria um grafo com 5 vértices
    grafo.adicionar_aresta(0, 1, 1); // adiciona aresta entre os vértices 0 e 1 com peso 2
    grafo.adicionar_aresta(1, 2, 2); // adiciona aresta entre os vértices 0 e 3 com peso 1
    grafo.adicionar_aresta(1, 4, 15); // adiciona aresta entre os vértices 1 e 2 com peso 3
    grafo.adicionar_aresta(4, 2, 1); // adiciona aresta entre os vértices 1 e 3 com peso 2
    grafo.adicionar_aresta(4, 3, 3); // adiciona aresta entre os vértices 2 e 4 com peso 5
    grafo.adicionar_aresta(2, 3, 4); // adiciona aresta entre os vértices 3 e 1 com peso 1

    vector<int> distancia = grafo.dijkstra(0); // encontra as distâncias mínimas de todos os vértices em relação ao vértice 0

    cout << "Distancias minimas do vertice 0 a todos os outros vertices:" << endl;
    for (int i = 0; i < (int) distancia.size(); ++i) { // percorre todos os vértices do grafo
        cout << "Vertice " << i << ": " << distancia[i] << endl; // imprime a distância mínima do vértice 0 ao vértice i
    }
   
    return 0;
}