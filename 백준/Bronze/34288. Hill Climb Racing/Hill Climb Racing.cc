#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, a;
	cin >> l >> a;
	int prev = INF;
	bool isPossible = true;
	for (int i = 0; i < l + 1; i++)
	{
		int x;
		cin >> x;
		int slope = x - prev;
		prev = x;
		if (slope > a)
		{
			isPossible = false;
		}
	}

	cout << (isPossible ? "POSSIBLE" : "BUG REPORT");

	return 0;
}