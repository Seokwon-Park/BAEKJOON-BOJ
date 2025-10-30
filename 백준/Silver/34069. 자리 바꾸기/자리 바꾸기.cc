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

vector<vector<int>> b;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	b.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	if (n % 2 && m % 2)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes\n";

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m && j + 1 < m; j += 2)
			{
				swap(b[i][j], b[i][j + 1]);
			}
		}
		if (m % 2)
		{
			for (int i = 0; i < n && i + 1 < n; i += 2)
			{
				swap(b[i][m - 1], b[i + 1][m - 1]);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j ++)
			{
				cout << b[i][j] << ' ';
			}
			cout << '\n';
		}
	}


	return 0;
}
