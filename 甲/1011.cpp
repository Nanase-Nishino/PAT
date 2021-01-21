#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<float> v(3);
	vector<char> ch(3);
	for (int i = 0; i < 3; i++) {
		float w, t, l;
		cin >> w >> t >> l;
		float maxV = max(t, max(w, l));
		if (w == maxV) {
			ch[i] = 'W';
		}
		else if (t == maxV) {
			ch[i] = 'T';
		}
		else if (l == maxV) {
			ch[i] = 'L';
		}
		v[i] = maxV;
	}
	cout << ch[0] << " " << ch[1] << " " << ch[2] << " ";
	cout << fixed << setprecision(2) << (v[0] * v[1] * v[2] * 0.65 - 1) * 2 << endl;
	return 0;
}