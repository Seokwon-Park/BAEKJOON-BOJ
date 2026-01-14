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
using hashmap = unordered_map<key, value>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	cout << n / 2 + m / 2 << '\n';
	for (int i = 2; i <= n; i += 2)
	{
		cout << i << ' ' << 1 << ' ' << i << ' ' << m << '\n';
	}

	for (int i = 2; i <= m; i += 2)
	{
		cout << 1 << ' ' << i << ' ' << n << ' ' << i << '\n';
	}

	return 0;
}