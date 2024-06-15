#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll d, c, r;
	cin >> d >> c >> r;
	vector<ll> todo(c);
	int ans = r;
	for (int i = 0; i < c; i++)
	{
		cin >> todo[i];
	}
	for (int i = 0; i < r; i++)
	{
		int ri;
		cin >> ri;
		d += ri;
	}

	for (int i = 0; i < c; i++)
	{
		if (todo[i] <= d)
		{
			d -= todo[i];
			ans++;
		}
		else
			break;
	}

	cout << ans;

	return 0;
}