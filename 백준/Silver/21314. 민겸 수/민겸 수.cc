#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;

	//make min
	int m = 0;
	int k = 0;
	string mn = "";
	for (auto c : s)
	{
		if (c == 'M')
		{
			m++;
		}
		if (c == 'K')
		{
			if (m > 0)
			{
				mn += '1';
				for (int i = 0; i < m-1; i++)
				{
					mn += '0';
				}
				m = 0;
			}
			k++;
		}
		if (k > 0)
		{
			k = 0;
			mn += '5';
		}
	}
	if (m > 0)
	{
		mn += '1';
		for (int i = 0; i < m - 1; i++)
		{
			mn += '0';
		}
		m = 0;
	}

	char ch = '\0';
	string mx = "";
	m = 0;
	for (auto c : s)
	{
		if (c == 'M')
		{
			if (ch == 'K')
			{
				mx += '5';
				for (int i = 0; i < m; i++)
				{
					mx += '0';
				}
				m = 0;
			}
			m++;
			ch = 'M';
		}
		else
		{
			if (ch == 'K')
			{
				mx += '5';
				for (int i = 0; i < m; i++)
				{
					mx += '0';
				}
				m = 0;
			}
			ch = 'K';
		}
	}
	if (ch == 'K')
	{
		mx += '5';
		for (int i = 0; i < m; i++)
		{
			mx += '0';
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			mx += '1';
		}
	}
	cout << mx << '\n';
	cout << mn;


	return 0;
}