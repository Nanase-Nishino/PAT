#include<iostream>
#include<string>
using namespace std;


// ͬ�ඨ�� 
// len%3���ַ�����3λһ���и� 
// ��(i+1)%3==len%3ʱ,��ʱ����Ҫ�и�
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