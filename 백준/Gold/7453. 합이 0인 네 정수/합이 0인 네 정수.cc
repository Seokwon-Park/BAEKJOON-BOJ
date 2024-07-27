#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

vector<int> ab;
vector<int> cd;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a, b, c, d;

	for (int i = 0; i < n; i++)
	{
		int aa, bb, cc, dd;
		cin >> aa >> bb >> cc >> dd;
		a.push_back(aa);
		b.push_back(bb);
		c.push_back(cc);
		d.push_back(dd);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ab.push_back(a[i] + b[j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cd.push_back(c[i] + d[j]);
		}
	}

	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	ll ans = 0;
	for (int i = 0; i < ab.size(); i++)
	{
		ans += (ll)(upper_bound(cd.begin(), cd.end(), -ab[i]) - lower_bound(cd.begin(), cd.end(), -ab[i]));
	}
	cout << ans;

	return 0;
}