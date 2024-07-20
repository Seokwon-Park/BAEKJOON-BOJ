#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;;

	if (n + m - 1 > k)
	{
		cout << "NO";
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		b[0][i] = i + 1;
	}
	for (int i = 1; i < n; i++)
	{
		for(int j = 0; j< m; j++)
		{
			b[i][j] = b[i - 1][j] + 1;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}