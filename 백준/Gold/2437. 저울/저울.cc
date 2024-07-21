#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ll st = 0;
	for (int i = 0; i < n; i++)
	{
		if (st >= v[i] - 1)
			st = st + v[i];
		else
		{
			cout << st + 1;
			return 0;
		}
	}
	cout << st + 1;

	return 0;
}