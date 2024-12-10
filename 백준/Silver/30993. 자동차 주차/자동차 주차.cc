#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


//nCk
ll comb(int n, int k)
{
	ll res = 1;
	ll div = 1;
	for (int i = 0; i < k; i++)
	{
		res *= n - i;
		div *= (i + 1);
	}
	return res / div;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b, c;
	cin >> n >> a >> b >> c;

	cout << comb(n, a) * comb(n - a, b); // * comb(n-a-b, c) = comb(c,c) = 1;

	return 0;
}