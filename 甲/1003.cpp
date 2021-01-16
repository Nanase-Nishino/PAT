#include<iostream>
#include<vector>
#include<limits.h>//INT_MAX的头文件

using namespace std;

int main() {
	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	vector<int> weight(N);
	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}
	vector<vector<int>> edge(N, vector<int>(N, INT_MAX));
	for (int i = 0; i < M; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		edge[x][y] = edge[y][x] = c;
	}
	vector<int> dis, num, w;
	vector<bool> visited(N, false);
	dis.resize(N, INT_MAX);
	num.resize(N);
	w.resize(N);
	dis[C1] = 0;
	num[C1] = 1;
	w[C1] = weight[C1];
	for (int i = 0; i < N; i++) {
		int u = -1;
		int minDis =INT_MAX;
		for (int j = 0; j < N; j++) {
			if (visited[j] == false && dis[j] < minDis) {
				u = j;
				minDis = dis[j];
			}
		}
		if (u == -1) {
			break;
		}
		visited[u] = true;
		for (int v = 0; v < N; v++) {
			if (visited[v] == false && edge[u][v] != INT_MAX) {
				if (dis[u] + edge[u][v] < dis[v]) {
					dis[v] = dis[u] + edge[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}else if (dis[u] + edge[u][v] == dis[v]) {
					num[v] += num[u];
					if (w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	}
	cout << num[C2] << " " << w[C2] << endl;
	return 0;
}