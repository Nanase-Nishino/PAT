#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	if (N == 0) {
		return 0;
	}
	unordered_map<int, vector<int>> mp;
	while (M != 0) {
		int ID, K;
		cin >> ID >> K;
		for (int i = 0; i < K; i++) {
			int tem;
			cin >> tem;
			mp[ID].emplace_back(tem);
		}
		M--;
	}
	vector<int> res;
	vector<int> tem;
	tem.emplace_back(1);
	while (!tem.empty()) {
		vector<int> next;
		int cnt = 0;
		for (int& x : tem) {
			if (!mp.count(x)) {
				cnt++;
			}
			else {
				for (int& y : mp[x]) {
					next.emplace_back(y);
				}
			}
		}
		tem = next;
		res.emplace_back(cnt);
	}
	for (int i = 0; i < res.size(); i++) {
		if (i == 0) {
			cout << res[i];
		}
		else{
			cout << " " << res[i];
		}
	}
	return 0;
}