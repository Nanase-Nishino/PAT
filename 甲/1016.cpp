#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<numeric>
#include<iomanip>
#include<unordered_map>

using namespace std;

vector<int> mp(24);

int toDec(string& s) {
	int res = 0;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		res = (res * 10 + s[i] - '0');
	}
	return res;
}

class call {
public:
	string dd;
	string hh;
	string mm;
	string time;
	string status;
	string month;
	string recordTime;
	call(string& _time,string& _status):time(_time),status(_status){
		month = string(time.begin(), time.begin() + 2);
		dd = string(time.begin() + 3, time.begin() + 5);
		hh= string(time.begin() + 6, time.begin() + 8);
		mm= string(time.begin() + 9, time.begin() + 11);
		recordTime = string(time.begin() + 3, time.end());
	}
};

class customer {
public:
	string month;
	float total=0.0;
	vector<call> phone;
	vector<pair<string, string>> time;
	vector<int> min;
	vector<float> money;
	void cacu(string& s1, string& s2) {
		string dd1(s1.begin(), s1.begin() + 2);
		string dd2(s2.begin(), s2.begin() + 2);
		string hh1(s1.begin() + 3, s1.begin() + 5);
		string hh2(s2.begin() + 3, s2.begin() + 5);
		string mm1(s1.begin() + 6, s1.begin() + 8);
		string mm2(s2.begin() + 6, s2.begin() + 8);
		int d1 = toDec(dd1);
		int d2 = toDec(dd2);
		int h1 = toDec(hh1);
		int h2 = toDec(hh2);
		int m1 = toDec(mm1);
		int m2 = toDec(mm2);
		int curMoney = 0;
		int curMin = 0;
		if (d1 == d2) {
			if (h1 == h2) {
				curMin = m2 - m1;
				curMoney = curMin * mp[h1];
			}
			else {
				curMin = (60 - m1) + m2;
				curMoney = (60 - m1) * mp[h1] + m2 * mp[h2];
				for (int j = h1 + 1; j < h2; j++) {
					curMoney += (60 * mp[j]);
					curMin += 60;
				}
			}
		}
		else {
			curMin = (60 - m1) + m2;
			curMoney = (60 - m1) * mp[h1] + m2 * mp[h2];
			for (int j = h1 + 1; j < 24; j++) {
				curMoney += (60 * mp[j]);
				curMin += 60;
			}
			for (int j = d1 + 1; j < d2;j++) {
				for (int k = 0; k < 24; k++) {
					curMin += 60;
					curMoney += (60 * mp[k]);
				}
			}
			for (int j = 0; j < h2; j++) {
				curMoney += (60 * mp[j]);
				curMin += 60;
			}
		}
		min.emplace_back(curMin);
		money.emplace_back((float)(curMoney/100.0));
	}
	void cacu() {
		for (auto& p : time) {
			cacu(p.first, p.second);
		}
		for (auto& p : money) {
			total += p;
		}
	}

};
int main() {

	for (int i = 0; i < 24; i++) {
		cin >> mp[i];
	}
	int N;
	cin >> N;

	// 按时间进行排序
	auto cmp = [](call& c1, call& c2) {
		if (c1.month == c2.month) {
			if (c1.dd == c2.dd) {
				if (c1.hh == c2.hh) {
					return c1.mm < c2.mm;
				}
				else {
					return c1.hh < c2.hh;
				}
			}
			else {
				return c1.dd < c2.dd;
			}
		}
		else {
			return c1.month < c2.month;
		}
	};

	map<string, customer> cus;
	for (int i = 0; i < N; i++) {
		string n, t, s;
		cin >> n >> t >> s;
		call c(t, s);
		cus[n].phone.emplace_back(c);
	}

	//将每个人的时间统计
	for (auto& c : cus) {
		c.second.month = c.second.phone[0].month;
		sort(c.second.phone.begin(), c.second.phone.end(), cmp);
		int len = c.second.phone.size();
		for (int i = 0; i < len; i++) {
			if (c.second.phone[i].status == "on-line") {
				if (i + 1 < len && c.second.phone[i + 1].status == "off-line") {
					c.second.time.emplace_back(c.second.phone[i].recordTime, c.second.phone[i + 1].recordTime);
					i += 1;
				}
			}
			else {
				continue;
			}
		}
		c.second.cacu();
	}

	//输出
	for (pair<string, customer> c : cus) {
		//如果一个人没有合法信息 则跳过
		if (c.second.time.empty()) {
			continue;
		}
		cout << c.first << " " << c.second.month << endl;
		int len = c.second.time.size();
		for (int i = 0; i < len; i++) {
			cout << c.second.time[i].first << " " << c.second.time[i].second << " " << c.second.min[i] << " $" << fixed << setprecision(2) << c.second.money[i] << endl;
		}
		cout << "Total amount: $" << fixed << setprecision(2) << c.second.total << endl;
	}

	return 0;
}