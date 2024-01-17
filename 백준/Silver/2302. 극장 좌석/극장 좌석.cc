#include <bits/stdc++.h>

using namespace std;

int dp[45];

// dp[1] = A
// dp[2] = AB BA
// dp[3] = AB+C, BA+C (C가 자리를 옮김 X) A+CB (C가 자리를 옮김 o)
// dp[4] = ABC+D BAC+D ACB + D(D가 자리를 옮김 X) AB+DC BA+DC(D가 자리를 옮김 o)
// 이런식으로 생각해야 한다고 한다. 똑똑해지고 싶다...

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> arr;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input-1);
	}
	arr.push_back(n);
	
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	int st = 0;
	int answer = 1;
	for (int ix : arr)
	{
		int tmp = ix - st;
		answer *= dp[tmp];
		st = ix+1;
	}

	cout << answer;

	return 0;
}