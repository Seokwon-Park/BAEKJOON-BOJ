#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	ll res = a * b * c;
	std::vector<int> v(10, 0);
	while (res)
	{
		v[res % 10]++;
		res /= 10;
	}

	for (auto i : v)
	{
		cout << i << '\n';
	}

	return 0;
}