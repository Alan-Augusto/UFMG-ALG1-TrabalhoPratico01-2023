#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF 0x3f3f3f3f

class Graph {
    private:
        // número de vértices
        int V; 
        
        // lista de adjacência
        vector<vector<pair<int, int>>> adj; 
        
    public:
        //Construtor
        Graph(int V);

        //Adicionar aresta
        void add_edge(int u, int v, int distance);
        
        //Printar grafo para controle interno de desenvolvimento
        void print();

        //Algoritmo djikstra para encontrar o menor caminho de uma origem qualquer até os demais vértices do grafo
        vector<int> dijkstra(int origin);
};

#endif
