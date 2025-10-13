#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
//const int MOD = 1'000'000'007;
const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

double dist(pair<ll, ll> a, pair<ll, ll> b)
{
	ll x = a.first - b.first;
	ll y = a.second - b.second;
	return sqrt(x * x + y * y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<ll, ll>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	vector<double> dp(n);
	double ans = 0.0;
	
	for (int i = 1; i < n; i++) 
	{
		for (int j = 0; j < i; j++) 
		{
			if (v[j].first < v[i].first) 
			{
				dp[i] = max(dp[i], dp[j] + dist(v[j], v[i]));
			}
		}
	}

	cout << fixed << setprecision(6) << *max_element(dp.begin(), dp.end());
	
	return 0;
}