#include<iostream>
#include<string>
#include<limits.h>

using namespace std;

int main() {
	int M;
	cin >> M;
	string lockName = "";
	string unlockName = "";
	int lockTime = -1;
	int unlockTime = INT_MAX;
	for (int i = 0; i < M; i++) {
		string temName = "";
		cin >> temName;
		int hh1, mm1, ss1;
		int hh2, mm2, ss2;
		scanf_s("%d:%d:%d %d:%d:%d", &hh1, &mm1, &ss1, &hh2, &mm2, &ss2);
		int signInTime = hh1 * 3600 + mm1 * 60 + ss1;
		int signOutTime = hh2 * 3600 + mm2 * 60 + ss2;
		if (signInTime < unlockTime) {
			unlockTime = signInTime;
			unlockName = temName;
		}
		if (signOutTime >= lockTime) {
			lockTime = signOutTime;
			lockName = temName;
		}
	}
	cout << unlockName << " " << lockName << endl;
	return 0;
}