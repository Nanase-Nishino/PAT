#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

string toTime(int x) {
	string HH, MM;
	int hh = x / 60 + 8;
	int mm = x % 60;
	if(hh<10){
		HH = "0";
	}
	if (mm < 10) {
		MM = "0";
	}
	HH += to_string(hh);
	MM += to_string(mm);
	return HH + ":" + MM;
}
struct customer {
	int num;
	int processTime;
	customer() {
		num = -1;
		processTime = 0;
	}
};
struct wait {
	int cnt;
	int num;
};
int main() {
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
	vector<customer> cus;
	for (int i = 0; i < K; i++) {
		int pT;
		cin >> pT;
		customer x;
		x.processTime = pT;
		x.num = i;
		cus.emplace_back(x);
	}
	//每次选择最短的窗口排队
	auto cmp = [](wait& a, wait& b) {
		if (a.cnt == b.cnt) {
			return a.num<b.num;
		}
		return a.cnt < b.cnt;
	};
	
	vector<wait> waitNum;
	for (int i = 0; i < N; i++) {
		wait curWait;
		curWait.cnt = 0;
		curWait.num = i;
		waitNum.emplace_back(curWait);
	}

	vector<queue<customer>> waitqueue(N);
	vector<string> doneTime(K);
	vector<customer> curTime(N);
	int i = 0;
	int Time = 0;
	bool alldone = false;
	// 预处理
	for (i = 0; i < N; i++) {
		if (i < K) {
			curTime[i] = cus[i];
		}
	}
	for (int j = 0; j < M - 1; j++) {
		for (int k = 0; k < N; k++) {
			if (i >= K) {
				break;
			}
			waitNum[k].cnt++;
			waitqueue[k].emplace(cus[i]);
			i++;
		}
	}
	while (!alldone) {
		Time++;
		for (int j = 0; j < N; j++) {
			if (curTime[j].processTime != 0) {
				curTime[j].processTime--;
				if (curTime[j].processTime == 0) {
					doneTime[curTime[j].num] = toTime(Time);
					if (!waitqueue[j].empty() && Time < 540) {
						curTime[j] = waitqueue[j].front();
						waitqueue[j].pop();
						for (wait& w : waitNum) {
							if (w.num == j) {
								w.cnt--;
							}
						}
					}
					if (i < K && Time < 540) {
						sort(waitNum.begin(), waitNum.end(), cmp);
						waitNum[0].cnt++;
						waitqueue[waitNum[0].num].emplace(cus[i]);
						i++;
					}
				}
			}
		}
		int jj = 0;
		for (; jj < N; jj++) {
			if (curTime[jj].processTime != 0) {
				break;
			}
		}
		if (jj == N) {
			alldone = true;
		}
	}

	for (int j = 0; j < K; j++) {
		if (doneTime[j].empty()) {
			doneTime[j] = "Sorry";
		}
	}

	for (int j = 0; j < Q; j++) {
		int x;
		cin >> x;
		cout << doneTime[x - 1] << endl;
	}
	return 0;
}