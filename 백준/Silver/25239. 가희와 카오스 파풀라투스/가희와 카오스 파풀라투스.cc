#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int GetSection(int hour)
{
	for (int i = 0; i < 6; i++)
	{
		if (hour >= i * 2 && hour < (i + 1) * 2)
			return i;
	}
}

void AddTime(int& h, int& m, int addh, int addm)
{
	m += addm;
	int carry = 0;
	if (m >= 60)
	{
		m %= 60;
		carry = 1;
	}
	h += addh + carry;
	if (h >= 12)
	{
		h %= 12;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string t;
	cin >> t;
	int hh = stoi(t.substr(0, 2));
	int mm = stoi(t.substr(3));

	int cur = GetSection(hh);
	vector<int> v(6);
	for (int i = 0; i < 6; i++)
	{
		cin >> v[i];
	}
	int l;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		double st;
		string cmd;
		cin >> st >> cmd;
		if (cmd == "^")
			v[cur] = 0;
		else if (cmd == "10MIN")
		{
			AddTime(hh, mm, 0, 10);
		}
		else if (cmd == "30MIN")
		{
			AddTime(hh, mm, 0, 30);
		}
		else if (cmd == "50MIN")
		{
			AddTime(hh, mm, 0, 50);
		}
		else if (cmd == "2HOUR")
		{
			AddTime(hh, mm, 2, 0);
		}
		else if (cmd == "4HOUR")
		{
			AddTime(hh, mm, 4, 0);
		}
		else if (cmd == "9HOUR")
		{
			AddTime(hh, mm, 9, 0);
		}
		cur = GetSection(hh);
	}

	cout << min(100, accumulate(v.begin(), v.end(), 0));


	return 0;
}