#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	int temp = 0;
	int tempId = 0;
	int leftId = 0;
	int rightId = N - 1;
	int sum = -1;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		temp += v[i];
		if (temp < 0) {
			temp = 0;
			tempId = i + 1;
		}
		else if (temp > sum) {
			sum = temp;
			leftId = tempId;
			rightId = i;
		}
	}
	if (sum < 0) {
		sum = 0;
	}
	cout << sum << " " << v[leftId] << " " << v[rightId] << endl;
	return 0;
}