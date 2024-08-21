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
	vector<ll> v(n+1);
	vector<ll> pfsum(n + 1);
	vector<ll> sq(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	ll sqsum = 0;
	for (int i = 1; i <= n; i++)
	{
		pfsum[i] = pfsum[i - 1] + v[i];
		sq[i] = v[i] * v[i];
		sqsum += sq[i];
	}

	ll mn = LLONG_MAX;
	int mnix = 0;
	for (ll i = 1; i <= n; i++)
	{
		ll front = v[i] * i - pfsum[i];
		ll back = pfsum[n] - pfsum[i] - v[i] * (n - i);
		ll res = front + back;
		if (res < mn)
		{
			mn = res;
			mnix = i;
		}
	}

	ll mn2 = LLONG_MAX;
	int mnix2 = 0;
	for (ll i = 1; i <= 10000; i++)
	{
		ll res = sqsum;
		res += i*i * n;
		res -= 2 * i * pfsum[n];
		if (res < mn2)
		{
			mn2 = res;
			mnix2 = i;
		}
	}

	cout << v[mnix] << ' ' << mnix2;


	return 0;
}