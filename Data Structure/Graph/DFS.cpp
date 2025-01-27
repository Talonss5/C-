#include <iostream>
using namespace std;

void DFS(int u, int A[][8], int n) {
    static int visited[8]{ 0 };

    if (visited[u] == 0) {
        cout << u << ", " << flush;
        visited[u] = 1;
        for (int v = 1; v < n; v++) {
            if (A[u][v] == 1 && visited[v] == 0) {
                DFS(v, A, n);
            }
        }
    }
}