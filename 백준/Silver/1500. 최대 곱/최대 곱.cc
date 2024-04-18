#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s, k;
	cin >> s >> k;
	int a = s / k;
	int b = s % k;

	vector<ll> v(k, a);
	for (int i = 0; i < b; i++)
	{
		v[i]++;
	}

	ll ans = 1;
	for (int i = 0; i < k; i++)
	{
		ans *= v[i];
	}
	cout << ans;


	return 0;
}