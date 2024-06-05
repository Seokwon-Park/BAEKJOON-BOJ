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

	int tc;
	cin >> tc;
	for(int i = 1; i<=tc; i++)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> dp(n,0);
		for (int j = 0; j < n; j++)
		{
			cin >> v[j];
		}
		dp[0] = v[0];
		dp[1] = max(v[0], v[1]);
		
		for (int j = 2; j < n; j++)
		{
			dp[j] = max(dp[j - 1], dp[j - 2] + v[j]);
		}
		cout << "Data Set " << i << ":\n";
		cout << dp[n - 1] << "\n\n";
	}

	return 0;
}