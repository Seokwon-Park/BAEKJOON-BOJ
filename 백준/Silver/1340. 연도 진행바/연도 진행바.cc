#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int pfdays[13] = { 0,0,31,59,90,120, 151, 181, 212, 243, 273, 304, 334 };

bool isYoon(int n)
{
	if (n % 400 == 0 || (n%4 == 0 && n%100 != 0))
	{
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);

	unordered_map<string, int> mon;
	mon["January"] = 1;
	mon["February"] = 2;
	mon["March"] = 3;
	mon["April"] = 4;
	mon["May"] = 5;
	mon["June"] = 6;
	mon["July"] = 7;
	mon["August"] = 8;
	mon["September"] = 9;
	mon["October"] = 10;
	mon["November"] = 11;
	mon["December"] = 12;

	istringstream iss(s);
	string tmp;
	vector<string> v;
	while (getline(iss, tmp, ' '))
	{
		v.push_back(tmp);
	}


	int month = mon[v[0]];
	int day = stoi(v[1].substr(0, 2));
	int year = stoi(v[2]);
	int hour = stoi(v[3].substr(0, 2));
	int min = stoi(v[3].substr(3));

	int totalday = 365;
	bool yoon = isYoon(year);
	if (yoon)
	{
		totalday += 1;
	}

	double totalmin = totalday * 24 * 60;

	int curday = pfdays[month] + day-1;
	if (yoon && month > 2)
	{
		curday += 1;
	}
	double curmin = curday * 24 * 60 + hour * 60 + min;
	
	cout << fixed << setprecision(9);
	cout << curmin / totalmin * 100.0;

	return 0;
}