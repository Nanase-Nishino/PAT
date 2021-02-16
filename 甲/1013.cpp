#include<iostream>
#include<vector>
 
using namespace std;

class DisjointSetunion {
private:
    int n;
    vector<int> f, rank;
public:
    DisjointSetunion(int _n) {
        n = _n;
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            f.emplace_back(i);
        }
    }
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool Union(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
        return true;
    }
};
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<bool>> edge(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        edge[x][y] = true;
    }
    vector<vector<bool>> temp;
    int x, i;
    for ( i = 0; i < K; i++) {
        temp = edge;
        cin >> x;
        for (int j = 1; j < N + 1; j++) {
            temp[x][j] = temp[j][x] = false;
        }
        int cnt = N-1;
        DisjointSetunion dsu(N+1);
        for (int j = 1; j < N + 1; j++) {
            for (int h = 1; h < N + 1; h++) {
                if (j != x && h != x && (temp[j][h] == true || temp[h][j] == true)) {
                    if (dsu.Union(h, j)) {
                        cnt--;
                    }
                }
            }
        }
        cout << cnt - 1 << endl;
    }

    return 0;
}