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

	int n, inv;
	cin >> n >> inv;
	int l = 1, r = 1;
	int x;
	bool prevFlip = 0;
	for (int i = 1; i <= n; i++)
	{
		if (prevFlip)
		{
			cout << i - 1 << ' ' << i << endl;
		}
		else
		{
			cout << i << ' ' << i << endl;
		}
		cin >> x;
		if (x == 0) break;
		if (x >= inv)
		{
			prevFlip = 1;
		}
		else
		{
			prevFlip = 0;
			inv = x;
		}
	}

	return 0;
}
