#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int dp[105][105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<double> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		//left
		double prev = 1e9;
		for (int j = i - 1; j >= 0; j--)
		{
			double a = (v[i] - v[j]) / (i - j);
			if (a < prev)
			{
				cnt++;
				prev = a;
			}
		}
		int cnt2 = 0;
		prev = -1e9;
		for (int j = i + 1; j < n; j++)
		{
			double a = (v[i] - v[j]) / (i - j);
			if (a > prev)
			{
				cnt++;
				prev = a;
			}
		}
		ans = max(ans, cnt + cnt2);
	}
	cout << ans << '\n';



	return 0;
}