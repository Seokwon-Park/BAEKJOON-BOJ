#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	ll tmp = 0;
	for (int i = 0; i < n; i++)
	{
		ll m;
		cin >> m;
		tmp += m;
	}

	tmp -= n * (n - 1) / 2LL;
	cout << tmp;

	return 0;
}