#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

bool dp[6][6];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	if (n != 3)
	{
		cout << "Woof-meow-tweet-squeek";
		return 0;
	}

	while (n--)
	{
		int a, b;
		cin >> a >> b;
		dp[a][b] = 1;
		dp[b][a] = 1;
	}

	if (dp[1][3] && dp[1][4] && dp[3][4])
		cout << "Wa-pa-pa-pa-pa-pa-pow!";
	else
		cout << "Woof-meow-tweet-squeek";
	
	return 0;
}
