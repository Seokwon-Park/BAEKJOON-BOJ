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

	int n, m;
	cin >> n >> m;
	int maxh = 1;
	cout << m * 2 + 1 << '\n';
	cout << "U " << 1 << ' ' << -1 << '\n';
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		cout << "U " << x+1 << ' ' << maxh++ << '\n';
		cout << "P\n";
	}

	return 0;
}