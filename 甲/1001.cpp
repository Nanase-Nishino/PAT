#include<iostream>
#include<string>
using namespace std;


// 同余定理 
// len%3将字符串以3位一份切割 
// 当(i+1)%3==len%3时,此时则需要切割
int main() {
	int a, b;
	cin >> a >> b;
	string s = to_string(a + b);
	int len = s.size();
	for (int i = 0; i < len; i++) {
		cout << s[i];
		if (s[i] == '-') {
			continue;
		}
		else if (len % 3 == (i + 1) % 3 && i != len - 1) {
			cout << ',';
		}
	}
	cout << '\n';
	system("pause");
	return 0;
}