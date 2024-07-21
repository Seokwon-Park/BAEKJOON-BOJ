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
	
	int n, m, k;
	cin >> n >> m >> k;

	vector<double> v(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int ix;
			double s;
			cin >> ix >> s;
			if (v[ix] < s)
			{
				v[ix] = s;
			}
		}
	}

	sort(v.begin(), v.end(), greater<double>());
	cout <<fixed << setprecision(1) << accumulate(v.begin(), v.begin() + k, 0.0);
	
	return 0;
} 