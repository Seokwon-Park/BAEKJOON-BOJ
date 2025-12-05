#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int up[505][505];
int front[505];
int side[505];


int realfront[505];
int realside[505];
int ans[505][505];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> up[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> front[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> side[n-i-1];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (up[i][j] == 0) continue;
			ans[i][j] = min(front[j], side[i]);
			realfront[j] = max(realfront[j], ans[i][j]);
			realside[i] = max(realside[i], ans[i][j]);
		}
	}

	bool chk = true;
	for (int i = 0; i < m; i++)
	{
		if (realfront[i] != front[i])
		{
			chk = false; break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (realside[i] != side[i])
		{
			chk = false; break;
		}
	}

	
	if (chk)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	else
	{
		cout << -1;
	}



	return 0;
}