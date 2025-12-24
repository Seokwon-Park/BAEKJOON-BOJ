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

int b[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			int x = i * m / 2 + j + 1;
			b[i][j] = x;
			b[i][m - j - 1] = x;
			b[n - i - 1][j] = x;
			b[n - i - 1][m - j - 1] = x;
 		}
	}

	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}