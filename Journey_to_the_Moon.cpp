/*
Problem Name: Journey to the Moon
Problem Algorithm: Graph Theory
Problem URL: https://www.hackerrank.com/challenges/journey-to-the-moon/problem
*/

void DFS(int i, vector<bool> &visited, vector<int> adj[], long *count) {
    visited[i] = true;
    (*count)++;
    for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
        if (visited[*it] == false) {
            DFS(*it, visited, adj, count);
        }
    }
}

// Complete the journeyToMoon function below.
long journeyToMoon(int n, vector<int> adj[]) {
    vector<bool> visited(n, false);
    long sum = 0;
    long res = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            long count = 0;
            DFS(i, visited, adj, &count);
            res += sum * count;
            sum += count;   
        }
    }
    return res;
}
