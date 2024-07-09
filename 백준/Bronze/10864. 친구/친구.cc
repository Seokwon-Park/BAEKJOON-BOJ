#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> friends(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		friends[a]++;
		friends[b]++;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << friends[i] << '\n';
	}

	return 0;
}