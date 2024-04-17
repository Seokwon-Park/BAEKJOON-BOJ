#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bool dp[1005]; // true:SK, false:CY win

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;
	
	//상근이가 이기는 방법이 하나라도 있으면 창영이가 진다.
	int n;
	cin >> n;
	for (int i = 5; i <= n; i++)
	{
		dp[i] = !(dp[i - 1] && dp[i - 3] && dp[i - 4]);
	}

	if (dp[n])
		cout << "SK";
	else
		cout << "CY";

	return 0;
}
