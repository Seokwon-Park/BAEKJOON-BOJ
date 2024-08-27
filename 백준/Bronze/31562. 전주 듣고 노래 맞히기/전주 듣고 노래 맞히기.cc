#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<string> k(n);
	vector<vector<char>> song(n);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		string title;
		cin >> title;
		k[i] = title;
		vector<char> a(7);
		for (int j = 0; j < 7; j++)
		{
			cin >> a[j];
		}
		song[i].push_back(a[0]);
		song[i].push_back(a[1]);
		song[i].push_back(a[2]);
	}

	for (int i = 0; i < m; i++)
	{
		string ans = "!";
		vector<char> tmp(3);
		for (int j = 0; j < 3; j++)
		{
			cin >> tmp[j];
		}
		bool isFind = false;
		for (int j = 0; j < n; j++)
		{
			if (song[j] == tmp)
			{
				if (!isFind)
				{
					ans = k[j];
					isFind = true;
				}
				else
				{
					ans = "?";
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}