#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // constante para representar infinito

class Grafo {
    private:
        // número de vértices
        int V; 
        // lista de adjacência
        vector<vector<pair<int, int>>> adj; 
        
    public:
        Grafo(int V);

        void adicionar_aresta(int u, int v, int peso);

        vector<int> dijkstra(int origem);
};

#endif
