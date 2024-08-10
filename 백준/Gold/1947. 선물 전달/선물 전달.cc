#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

ll dp[1000005];

// 풀이 메모
// 완전 순열이라는 개념이다.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	dp[1] = 0;
	dp[2] = 1;

	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		//i명이 있을때
		//만약 1 -> k에게 선물을 준경우
		//k도 1에게 선물을 줬으면 둘은 더이상 경우의 수에 포함되지 않으므로
		//i-2끼리 선물을 주고받는 경우의 수와 같다.(dp[i-2])
		//k가 1에게 선물을 주지 않았으면 i-1명끼리 선물을 주고받는 경우의 수와 같다(dp[i-1])
		//그리고 1이 k를 고르는 경우의 수는 (i-1)명 중에 하나 고르는 것이기 때문에 i-1의 경우가 있다.

		dp[i] = (i - 1LL) * (dp[i - 2] + dp[i - 1]);
		dp[i] %= 1'000'000'000;
	}

	cout << dp[n];

	return 0;
}