#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int month[13] = { 0, 31,28, 31,30,31,30,31,31,30,31,30,31 };

bool isleap(int year)
{
	if (year % 400 == 0)
	{
		return true;
	}
	else if (year % 4 == 0 && year % 100 != 0)
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
	int n;
	cin >> s >> n;
	int y = stoi(s.substr(0, 4));
	int m = stoi(s.substr(5, 2));
	int d = stoi(s.substr(8));

	for (int i = 0; i < n-1; i++)
	{
		if (isleap(y))
		{
			month[2] = 29;
		}
		else
		{
			month[2] = 28;
		}
		d++;
		if (d > month[m])
		{
			d = 1;
			m++;
			if (m > 12)
			{
				m = 1;
				y++;
			}
		}
	}
	cout << y << '-' <<setw(2)<<setfill('0')<< m << '-' << setw(2) << setfill('0') << d;

	return 0;
}