#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

//subtask1. 처음에 당근이 0이기 때문에 1초에는 무조건 +s = 1
// 그다음 2초에 구매를 해버리면 당근의 개수는 0개고 s값만 더해지기 때ㅜㅁㄴ에 그냥 당근 추가 버튼 2번이 무조건 최대
//subtask2. 매초 k+1개의 선택을 계산해서 브루트 포스로 해결
//subtask3. dp[i][j]를 "i초에 s의 값이 j 일 때 가질 수 있는 당근의 최대 개수"로 정의합시다.

ll dp[105][5005];
pii v[105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= k; i++)
	{
		fill(dp[i], dp[i] + 5005, -1);
	}

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	dp[0][1] = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= 5000; j++)
		{
			if (dp[i - 1][j] != -1)
			{
				dp[i][j] = dp[i - 1][j] + j;
			}
			for (int l = 0; l < n; l++)
			{
				auto [cost, value] = v[l];
				if (j - value > 0 && dp[i - 1][j - value] >= cost)
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - value] - cost);
				}
			}
		}
	}
	cout << *max_element(dp[k], dp[k] + 5001);

	return 0;
}