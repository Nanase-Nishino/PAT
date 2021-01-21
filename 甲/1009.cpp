#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>

using namespace std;

int main() {
	unordered_map<int, float> mp1;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		float coe;
		int exp;
		cin >> exp >> coe;
		mp1[exp] = coe;
	}
	map<int, float,greater<int>> mp2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		float coe;
		int exp;
		cin >> exp >> coe;
		for (auto& x: mp1) {
			int temExp = x.first + exp;
			float temCoe = x.second * coe;
			if (!mp2.count(temExp)) {
				mp2[temExp] = temCoe;
			}
			else {
				mp2[temExp] += temCoe;
			}
			if (mp2[temExp] == 0) {
				mp2.erase(temExp);
			}
		}
	}
	cout << mp2.size();
	for (auto& x : mp2) {
		cout << " " << x.first << " " << fixed << setprecision(1) << x.second;
	}
	return 0;
}