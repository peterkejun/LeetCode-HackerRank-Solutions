/*
Problem Name: Snakes and Ladders: The Quickest Way Up
Problem Algorithm: Graph Theory
Problem URL: https://www.hackerrank.com/challenges/the-quickest-way-up/problem
*/

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    int g[100][100]{0};
    for (int i = 0; i < 100; i++) {
        for (int j = 1; j < 7 && i + j < 100; j++) {
            g[i][i + j] = 1;
        }
    }
    for (auto ladder : ladders) {
        for (int i = 0; i < 100; i++) {
            if (g[i][ladder[0]] == 1) {
                g[i][ladder[1]] = 1;
                g[i][ladder[0]] = 0;
            }
        }
        memset(g[ladder[0]], 0, sizeof(int) * 100);
    }
    for (auto snake : snakes) {
        for (int i = 0; i < 100; i++) {
            if (g[i][snake[0]] == 1) {
                g[i][snake[0]] = 0;
                g[i][snake[1]] = 1;
            }
        }
        memset(g[snake[0]], 0, sizeof(int) * 100);
    }
    //BFS
    list<int> q;
    bool visited[100];
    int dist[100];
    for (int i = 0; i < 100; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    visited[0] = true;
    dist[0] = 0;
    q.push_back(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (int i = 0; i < 100; i++) {
            if (g[u][i] == 1 && !visited[i]) {
                q.push_back(i);
                visited[i] = true;
                dist[i] = dist[u] + 1;
                if (i == 99) return dist[99];
            }
        }
    }
    return -1;
}