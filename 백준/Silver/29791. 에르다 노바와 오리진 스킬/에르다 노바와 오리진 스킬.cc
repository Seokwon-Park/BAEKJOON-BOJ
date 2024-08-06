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

	int n, m;
	cin >> n >> m;
	ll origin = 0;
	ll originCooldown = 0;
	ll erda = 0;
	ll erdaCooldown = 0;

	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<ll> b(m);

	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++)
	{
		if (erdaCooldown <= a[i])
		{
			erda++;
			erdaCooldown = a[i] + 100LL;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (originCooldown <= b[i])
		{
			origin++;
			originCooldown = b[i] + 360LL;
		}
	}

	cout << erda << ' ' << origin;


	return 0;
}