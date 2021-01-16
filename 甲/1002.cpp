#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

int main(){
	vector<float> v(1001, 0.0);
	for (int i = 0; i < 2; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a;
			float b;
			cin >> a >> b;
			v[a] += b;
		}
	}
	int cnt = 0;
	for (float& x : v) {
		if (x!=0.0) {
			cnt++;
		}
	}
	cout << cnt;
	for (int i = 1000; i >= 0; i--) {
		if (v[i]!=0.0) {
			cout << ' ' << i << ' ' << fixed << setprecision(1) << v[i];
		}
	}
	cout << endl;
	return 0;
}