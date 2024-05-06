#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int v[100005];
int dp[2][100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	dp[0][1] = v[1];
	dp[1][1] = v[1];

	for (int i = 2; i <= n; i++)
	{
		dp[0][i] = max({ dp[0][i - 1] + v[i], v[i] }); // 그냥 최대 연속 합
		dp[1][i] = max({ dp[1][i - 1] + v[i], dp[0][i-1]});
		// case.
		// 1. 이전에 이미 제거한 상태의 값이면 제거 못하니까 무조건 더해야함.
		// 2. 만약 제거 안한 상태에서 i번째 값을 제거 하는 경우
		// 두 값을 비?교함.
	}

	cout << max(*max_element(dp[0]+1, dp[0]+n+1), *max_element(dp[1]+1, dp[1] + n+1));

	return 0;
}
