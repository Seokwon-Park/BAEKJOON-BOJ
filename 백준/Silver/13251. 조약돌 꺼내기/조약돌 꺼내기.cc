#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> m;
	vector<int> v(m);
	
	int total = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
		total += v[i];
	}
	int k;
	cin >> k;

	double ans = 0;
	for (int i = 0; i < m; i++)
	{
		if (v[i] < k) continue;
		double res = 1.0;
		double totaltmp = total;
		double pick = v[i];
		for (int j = 0; j < k; j++)
		{
			res *= pick / totaltmp;
			pick--;
			totaltmp--;
		}
		ans += res;
	}
	cout << fixed << setprecision(9);
	cout << ans;

	return 0;
}