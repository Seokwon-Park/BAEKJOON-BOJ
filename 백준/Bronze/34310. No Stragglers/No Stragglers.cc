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

	Hash<string, int> h;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		int c;
		cin >> a >> b >> c;
		if (b == "IN")
		{
			h[a] += c;
		}
		else
		{
			h[a] -= c;
		}
	}

	int l = 0;
	for (auto [x, y] : h)
	{
		l += y;
	}
	cout << (l == 0 ? "NO STRAGGLERS" : to_string(l));

	return 0;
}