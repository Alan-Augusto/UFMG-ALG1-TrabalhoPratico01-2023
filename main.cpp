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


int main(int argc, char** argv) {

    int NumCidades;
    int NumEstradas;
    
    //Lendo os dados do arquivo
    cin >> NumCidades;
    cin >> NumEstradas;
    
    Grafo G = Grafo(2*NumCidades+1);

    //cout << NumCidades << " e " << NumEstradas << endl;

    for (int i=0; i< NumEstradas; i++){
        int origem;
        int destino;
        int distancia;

        cin >> origem;
        cin >> destino;
        cin >> distancia;

        if((distancia %2) == 0){ //Adiciona somente as arestas pares
            //Nós do Tipo A se ligam à Nós do tipo B
            G.adicionar_aresta(origem, (destino+NumCidades), distancia);
            //Nós do Tipo B se ligam à Nós do tipo A
            G.adicionar_aresta((origem+NumCidades), destino, distancia);

        }

    }
    //G.print();

    //cout << "Distancias minimas do vertice 1 até a última cidade" << endl;
    vector<int> MenorCaminho = G.dijkstra(1); //Obtem o menor caminho até todas as estradas partindo de "1"
    if(MenorCaminho[NumCidades] == INF){
        cout << -1 << endl;
    }
    else{
        cout << MenorCaminho[NumCidades] << endl; //Imprime o menor caminho até a última cidade
    }

}