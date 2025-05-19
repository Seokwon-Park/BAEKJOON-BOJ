#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dp[25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v;
	int cont = 0;
	for (int i = 0; i < n;)
	{
		if (s[i] == 'l')
		{
			string chk = s.substr(i, 4);
			if (chk == "long")
			{
				cont++;
				i += 4;
				continue;
			}
		}
		if (cont != 0)
		{
			v.push_back(cont);
			cont = 0;
		}
		i++;
	}
	if (cont != 0)
	{
		v.push_back(cont);
	}
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 20; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	ll ans = 1;
	for (int i : v)
	{
		ans *= dp[i];
	}
	cout << ans;

	

	return 0;
}