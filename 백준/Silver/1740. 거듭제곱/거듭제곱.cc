#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	string res = "";
	while (n)
	{
		res += n % 2 + '0';
		n /= 2;
	}

	ll k = 1;
	ll ans = 0;
	for (int i = 0; i < res.size(); i++)
	{
		ll m = res[i] - '0';
		ans += m * k;
		k *= 3;
	}

	cout << ans;

	return 0;
}