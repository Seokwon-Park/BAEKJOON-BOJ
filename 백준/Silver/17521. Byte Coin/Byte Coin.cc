#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, w;
	cin >> n >> w;
	ll stock = 0;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n-1; i++)
	{
		if (v[i] > v[i + 1])
		{
			w += stock * v[i];
			stock = 0;
		}
		else if (v[i] < v[i + 1])
		{
			stock += w / v[i];
			w %= v[i];
		}
	}

	w += stock * v[n - 1];
	cout << w;


	return 0;
}
