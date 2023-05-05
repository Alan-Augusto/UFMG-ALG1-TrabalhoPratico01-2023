#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include "graph.hpp"

using namespace std;

//ler a linha de comando
char* checkLineArguments(int argc, char **argv, int x){
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
    char inputNameArq []= "./test_cases/inputs/test_case1.txt";
    
    //Variaveis principais
    ifstream InputFile(inputNameArq);
    Assert(InputFile.is_open(), "Opening error in input file");
    
    

    int NumCidades;
    int NumEstradas;
    
    //Lendo os dados do arquivo
    InputFile >> NumCidades;
    InputFile >> NumEstradas;
    
    Grafo G = Grafo(2*NumCidades);

    cout << NumCidades << " e " << NumEstradas << endl;

    for (int i=0; i< NumEstradas; i++){
        int origem;
        int destino;
        int distancia;

        InputFile >> origem;
        InputFile >> destino;
        InputFile >> distancia;

        G.adicionar_aresta(origem, destino, distancia);

    }
    G.print();

    cout << "Distancias minimas do vertice 1 até a última cidade" << endl;
    vector<int> MenorCaminho = G.dijkstra(1); //Obtem o menor caminho até todas as estradas partindo de "1"
    cout << MenorCaminho[NumCidades] << endl; //Imprime o menor caminho até a última cidade

}