#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// 当题目没有明确数据大小时 全部long long

long long tran(string& N1,long long radix) {
	long long res = 0;
	for (char& ch : N1) {
		int cur = isdigit(ch) ? ch - '0' : ch - 'a' + 10;
		res = (res * radix + cur);
	}
	return res;
}
long long find_radix(string& s, long long num) {
	char ch = *max_element(s.begin(), s.end());
	long long low = (isdigit(ch) ? ch - '0' : ch - 'a' + 10) + 1;
	long long high = max(low, num);
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long t = tran(s, mid);
		if (t<0 || t>num) {
			high = mid - 1;
		}
		else if (t == num) {
			return mid;
		}
		else {
			low = mid + 1;
		}
	}
	return -1;
}
int main() {
	string N1, N2;
	long long tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	long long rad = tag == 1 ? find_radix(N2, tran(N1, radix)) : find_radix(N1, tran(N2, radix));
	if (rad != -1) {
		cout << rad << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}