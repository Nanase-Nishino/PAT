#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<char, string> mp{ {'0',"zero"}, {'1',"one"},{'2',"two"},{'3',"three"},{'4',"four"},{'5',"five"},{'6',"six"},{'7',"seven"},{'8',"eight"},{'9',"nine"} };

int main() {
	string x;
	cin >> x;
	int num = 0;
	for (char& ch : x) {
		num += (ch - '0');
	}
	string str = to_string(num);
	for (int i = 0; i < str.size(); i++) {
		if (i == 0) {
			cout << mp[str[i]];
		}
		else {
			cout << " " << mp[str[i]];
		}
	}
	return 0;
}