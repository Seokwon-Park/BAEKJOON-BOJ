#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

bool dp[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 1; i * i <= 1000000; i++)
	{
		dp[i * i] = 1;
	}

	for (int i = 1; i <= 1000000; i++)
	{
		if (dp[i]) continue;
		bool checker = true;
		for (int j = 1; j * j <= i; j++)
		{
			checker &= dp[i - j * j];
		}
        dp[i] = !checker;
	}


	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;

        if (!dp[n])
			cout << "cubelover";
		else
			cout << "koosaga";
		cout << '\n';
	}
	

	return 0;
}
