
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		int d, t;
		cin >> d >> t;
		v[i] = { t, d };
	}
	
	sort(v.begin(), v.end(), greater<pair<int,int>>());

	ll ans = 0;
	int cur = INF;
	for (int i = 0; i < n; i++)
	{
		auto [t, d] = v[i];
		int dead = t - d;
		if (t < cur)
		{
			cur = dead;
		}
		else
		{
			cur -= d;
		}
	}
	cout << cur;

	return 0;
}