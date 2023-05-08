#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include "graph.hpp"

using namespace std;


int main(int argc, char** argv) {

    //Declaração das variáveis iniciais de entrada
    int NumCities;
    int NumRoads;
    
    //Leitura dos dados inicias do problema
    cin >> NumCities;
    cin >> NumRoads;
    
    //Declaração do Graph
    Graph G = Graph(2*NumCities+1);
        //Deve conter 2 vezes o número de cidades pois os vértices são duplicados
        //para que o problema da quantdiade par de estradas seja resolvida.

    
    for (int i=0; i< NumRoads; i++){ //Para cada uma das estradas recebidas
        
        int origin;     //Recebe a cidade de origem
        cin >> origin;
        
        int destiny;    //Recebe a cidade de destino
        cin >> destiny;
        
        int distance;   //Recebe o comprimento da estrada
        cin >> distance;

        if((distance %2) == 0){ //Somente se o comprimento da estada for par
            
            //Liga uma cidade à outra seguindo a regra do Graph bipartido:

                //Nós do Tipo A se ligam à Nós do tipo B
                G.add_edge(origin, (destiny+NumCities), distance);
                //Nós do Tipo B se ligam à Nós do tipo A
                G.add_edge((origin+NumCities), destiny, distance);

        }

    }
    
    //Cria um vetor com o menor caminho disponível até todas as cidades, saindo da cidade 1. -> Usando Dijkstra
    vector<int> MenorCaminho = G.dijkstra(1); 
    
    //Estamos buscando o menor caminho VÁLIDO até a última cidade -> MenorCaminho[NumCities]
    if(MenorCaminho[NumCities] == INF){ //Se esse comprimento for infinito, significa que não existe um caminho VÁLIDO.
        cout << -1 << endl; //Nesse caso, imprime apenas "-1"
    }
    else{
        cout << MenorCaminho[NumCities] << endl; //Imprime o menor caminho até a última cidade
    }

}