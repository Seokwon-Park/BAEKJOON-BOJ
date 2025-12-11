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



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		vector<vector<char>> v(x, vector<char>(x, '.'));

		for (int i = 0; i < x; i++)
		{
			v[i][0] = '#';
			v[i][x - 1] = '#';
			if (i <= x / 2)
			{
				v[i][i] = '#';
				v[i][x - 1 - i] = '#';
			}
		}

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << v[i][j];
			}
			cout << '\n';
		}

	}

	return 0;
}
