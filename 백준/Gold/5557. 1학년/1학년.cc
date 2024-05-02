#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll dp[105][21]; // dp[i][j] 
// i : 0번째 ~ n-2번째 값까지 했을때
// j : 그 결과가 j(0~20)가 나오도록 하는 등식의 개수
// 답은 n-1번째값(마지막 값)과 동일한 값이 나오도록 하는 등식이 몇개인지 찾으면 되기 때문에 dp[n-2][v[n-1]]로 계산함.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	dp[0][v[0]] = 1;

	for (int i = 1; i < n-1; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (j - v[i] >= 0)
			{
				dp[i][j - v[i]] += dp[i - 1][j];
			}
			if (j + v[i] <= 20)
			{
				dp[i][j + v[i]] += dp[i - 1][j];
			}
		}
	}
	
	cout << dp[n - 2][v[n - 1]];

	return 0;
}
