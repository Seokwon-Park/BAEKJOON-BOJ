#include <bits/stdc++.h>

using namespace std;

int dp[1000005]; // i까지의 1씩 증가하는 수열의 길이

// 5 2 4 1 3
// 2 3은 고정으로 놓고 1 4 5 만 바꾸면 됨 = 답 3 = n - 가장 긴 1씩 증가하는 수열의 길이 = 5-2 = 3
// dp[5] = dp[4] + 1 = 1 (4가 이전에 나온적이 없음) // 4 까지의 최장 증가수열 길이에 1을 더해준다. // 여기서는 arr = {5}가 최장이기 때문에 1이 됨.
// dp[2] = dp[1] + 1 = 1 ( " )
// dp[4] = dp[3] + 1 = 1 ( " )
// dp[1] = dp[0] + 1 = 1 ( " )
// dp[3] = dp[1] + 1 = 2 ( " ) // 앞에서 2가 나왔으므로

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{ 
		int input;
		cin >> input;
		dp[input] = dp[input - 1] +1; // 
	}
	cout << n - *max_element(dp + 1, dp + n + 1);

	return 0;
}