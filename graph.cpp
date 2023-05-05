#include "graph.hpp"

//Construtor
Grafo::Grafo(int V) {
    this->V = V;
    adj.resize(V);
}

void Grafo::adicionar_aresta(int u, int v, int peso) {
    adj[u].push_back(make_pair(v, peso));
    adj[v].push_back(make_pair(u, peso));
}


void Grafo::print(){
    for(int i = 0; i < V/2; i++){
        cout << "Vértice " << i << endl;
        for(int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j].first << " " << adj[i][j].second << " ";
            cout << endl;
        }
        cout << endl;
    }
}

vector<int> Grafo::dijkstra(int origem) {
    vector<int> dist(V, INF); //inicializa todas as distâncias com infinito
    dist[origem] = 0; //a distância da origem para ela mesma é 0

    priority_queue<int, vector<int>, greater<int>> pq; //fila de prioridade
    pq.push(origem); //insere a origem na fila

    while (!pq.empty()) { //enquanto a fila não estiver vazia
        int u = pq.top(); //extrai o vértice com menor distância (vértice atual)
        pq.pop();

        for (const auto& v : adj[u]) { //percorre todos os vizinhos do vértice atual
            
            int vizinho = v.first;
            int peso = v.second;

            if ((dist[u] + peso) < dist[vizinho]) { //se a distância atual for menor do que a distância armazenada
                dist[vizinho] = dist[u] + peso; //atualiza a distância
                pq.push(vizinho); //insere o vizinho na fila
            }
        }
    }

    return dist; //retorna as distâncias mínimas
}