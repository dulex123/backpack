#include <iostream>
#include <vector>
#include <stack>

#define NUM_NODES 11

using namespace std;

struct Node {
    vector<int> adj;
};

Node graph[NUM_NODES];
bool visited[NUM_NODES] = {0};

/* Recursive DFS */
void DFS(int node) {
    if(!visited[node]) {
        cout << "Current " << node << endl;
        visited[node] = true;
        for(int i=0; i < graph[node].adj.size(); i++) {
            DFS(graph[node].adj[i]);
        }
    }
}

void STACK_DFS(int node) {
    stack<int> dfs_stack;
    dfs_stack.push(node);
    while(!dfs_stack.empty()) {
        int current = dfs_stack.top();
        dfs_stack.pop();
        if(visited[current])
            continue;
        cout << "Current " << current << endl;
        visited[current]=true;
        for(int i=0; i<graph[current].adj.size(); i++) {
            int neighbour = graph[current].adj[i];
            if(!visited[neighbour]) {
                dfs_stack.push(neighbour);
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

    int edges[2][14] = {
            {0, 0, 0, 2, 2, 3, 5, 5, 6, 4, 5, 7, 7, 8},
            {1, 2, 3, 4, 5, 5, 6, 9, 9, 7, 8, 8, 10, 10}
    };

    for(int i=0; i < 14; i++) {
        connect(edges[0][i], edges[1][i]);
    }

    STACK_DFS(0);
    return 0;
}