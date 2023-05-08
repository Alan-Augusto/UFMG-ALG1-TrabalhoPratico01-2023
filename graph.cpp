#include "graph.hpp"

//Construtor
Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::add_edge(int u, int v, int distance) {
    //Sempre adicionar o par de arestas por ser NAO dorecionado
    adj[u].push_back(make_pair(v, distance));
    adj[v].push_back(make_pair(u, distance));
}

void Graph::print(){
    //Apenas para controle interno de desenvolvimento
    for(int i = 0; i < V/2; i++){
        cout << "Vértice " << i << endl;
        for(int j = 0; j < (int) adj[i].size(); j++){
            cout << adj[i][j].first << " " << adj[i][j].second << " ";
            cout << endl;
        }
        cout << endl;
    }
}

vector<int> Graph::dijkstra(int origin) {
    vector<int> dist(V, INF);   //Vetor com as distâncias masi curtas até cada elemento
                                //inicializa todas as distâncias com infinito
    dist[origin] = 0; //a distância da origem para ela mesma é 0

    priority_queue<int, vector<int>, greater<int>> priority_queue; //Cria fila de prioridade
    priority_queue.push(origin); //insere a origem na fila

    while (!priority_queue.empty()) { //enquanto a fila não estiver vazia
        
        int u = priority_queue.top(); //copia o vértice com menor distância (vértice atual)
        priority_queue.pop(); //Remove esse vértice da fila

        for (const auto& v : adj[u]) { //para cada um dos vizinhos do vértice atual
            
            int neighbor = v.first; //armazena o identificador do vizinho
            int distance = v.second;   //armazena o distance da aresta

            if ((dist[u] + distance) < dist[neighbor]) { //se a distância atual até esse vizinho 
                                                    //for menor do que a distância armazenada

                dist[neighbor] = dist[u] + distance; //atualiza a distância mais curta até esse elemento
                priority_queue.push(neighbor); //insere o vizinho na fila de prioridade
            }
        }
    }

    return dist; //retorna as distâncias mínimas
}