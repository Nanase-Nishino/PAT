#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_map>

using namespace std;
unordered_map<int, char> mp{ {0,'A'},{1,'C'},{2,'M'},{3,'E'} };


// 排名注意可以并列！！

int main() {
	int N,M;
	cin >> N >> M;
	vector<pair<string, vector<double>>> inf;
	for (int i = 0; i < N; i++) {
		string id;
		double c, m, e, a;
		cin >> id >> c >> m >> e;
		a = (c + m + e) / 3;
		inf.emplace_back(make_pair(id, vector<double>{a, c, m, e}));
	}
	unordered_map<string, pair<int, char>> rank;
	for (int i = 0; i < 4; i++) {
		sort(inf.begin(), inf.end(), [&](const auto& a, const auto& b) {
			return a.second[i] > b.second[i];
			});
		int pre = -1;
		for (int j = 0; j < N; j++) {
			pair<int, char> cur;
			if (j > 0 && inf[j].second[i] == inf[j - 1].second[i]) {
				cur = make_pair(pre, mp[i]);
			}
			else {
				cur = make_pair(j + 1, mp[i]);
				pre = j + 1;
			}
			if (!rank.count(inf[j].first)) {
				rank[inf[j].first] = cur;
			}
			else if (cur.first < rank[inf[j].first].first) {
				rank[inf[j].first] = cur;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		string id;
		cin >> id;
		if (!rank.count(id)) {
			cout << "N/A" << endl;
		}
		else {
			cout << rank[id].first << " " << rank[id].second << endl;
		}
	}
	return 0;
}