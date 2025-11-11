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
	
	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	int ix = -1;
	ll xx = 1;
	ll yy = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (y[i] * xx > yy * x[i])
		{
			yy = y[i];
			xx = x[i];
			ix = i;
		}
	}

	int ans = 0;
	int len = 0;
	for (int i = ix; i < n; i++)
	{
		if (y[i] * xx == yy * x[i])
		{
			len++;
		}
		else
		{
			ans = max(ans, len);
			len = 0;
		}
	}
	ans = max(ans, len);

	ll g = gcd(xx, yy);
	cout << yy / g << ' ' << xx / g << '\n';
	cout << ans;



	return 0;
}