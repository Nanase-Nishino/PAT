#include<iostream>
using namespace std;

int main() {
	int sum = 0;
	int cur = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tem;
		cin >> tem;
		if (tem > cur) {
			sum += ((tem - cur) * 6);
		}
		else {
			sum += ((cur - tem) * 4);
		}
		cur = tem;
		sum += 5;
	}
	cout << sum << endl;
	return 0;
}