/* Graph BFS implementation with vectors/lists */

#include <iostream>
#include <vector>
#include <queue>

#define NUM_NODES 11

using namespace std;

/* Every node has only a list of its neighbours */
struct Node {
    vector<int> adj;
};


Node graph[NUM_NODES];
bool visited[NUM_NODES] = {0};
queue<int> bfs_queue;


void BFS(int node) {
    visited[node] = true;
    bfs_queue.push(node);
    while (!bfs_queue.empty()) {
        int curr = bfs_queue.front();
        bfs_queue.pop();
        visited[curr] = true;
        for (int k = 0; k < graph[curr].adj.size(); k++) {
            int neighbour = graph[curr].adj[k];
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                bfs_queue.push(neighbour);
                cout << "curr : " << curr << " neigbour:" << neighbour << endl;
            }
        }
    }
}

/* Since it is not directed graph we connect both ways */
void connect(int node1, int node2) {
    graph[node1].adj.push_back(node2);
    graph[node2].adj.push_back(node1);
}

int main() {
    /* Column-wise defined edges */
    int edges[2][14] = {
            {0, 0, 0, 2, 2, 3, 5, 5, 6, 4, 5, 7, 7, 8},
            {1, 2, 3, 4, 5, 5, 6, 9, 9, 7, 8, 8, 10, 10}
    };

    for(int i=0; i < 14; i++) {
        connect(edges[0][i], edges[1][i]);
    }

    BFS(0);
    return 0;
}