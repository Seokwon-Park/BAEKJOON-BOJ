#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
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

	int n;
	cin >> n;

	vector<vector<char>> v(n * 2, vector<char>(n * 4 + 2, ' '));
	for (int i = 0; i < n * 2; i++)
	{
		v[i][n * 2 - 1 - i] = '*';
		if (i < n)
		{
			v[i][n * 2 + (n - i)] = '*';
			v[i][n * 4 + 2 - (n - i)] = '*';
		}
		else
		{
			v[i][n * 2 + (i - n) + 1] = '*';
			v[i][n * 4 + 2 - (i - n) - 1] = '*';
		}
	}

	for (int i = 0; i < n * 2; i++)
	{
		for (int j = 0; j < n * 4 + 2; j++)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}

	return 0;
}