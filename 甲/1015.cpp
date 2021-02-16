#include<iostream>
#include<vector>
#include<math.h>
#include<string>

using namespace std;

int tran(int x, int y) {
	//to radixY
	string s;
	while (x) {
		s += (x % y + '0');
		x /= y;
	}
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		res = (res * y + s[i] - '0');
	}
	return res;
}

bool isprimer(int x) {
	if (x <= 1) {
		return false;
	}
	int j = (int)(sqrt(x));
	for (int i = 2; i <= j; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	vector<string> v;
	while (true) {
		int x;
		cin >> x;
		if (x < 0) {
			break;
		}
		int y;
		cin >> y;
		if (isprimer(x)) {
			x = tran(x, y);
			if (isprimer(x)) {
				v.emplace_back("Yes");
			}
			else {
				v.emplace_back("No");
			}
		}
		else {
			v.emplace_back("No");
		}
	}
	for (string& s : v) {
		cout << s << endl;
	}
	return 0;
}