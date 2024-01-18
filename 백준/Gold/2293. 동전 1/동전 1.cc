#include <bits/stdc++.h>

using namespace std;

int dp[100005]; // 동전의 가치가 10만까지라고 해서 범위를 k보다 넓게 잡음.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	//동전의 가치들을 저장함.
	vector<int> coin;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		coin.push_back(c); 
	}

	dp[0] = 1; // 0원을 만드는 방법은 아무것도 쓰지 않는 것 1가지이다.

	for (int i = 0; i < n; i++) // i번째 동전에 대해서 dp값을 계산해서 더한다.
	{
		for (int j = coin[i]; j <= k; j++) // 예제 처럼 1, 2, 5가 주어진 경우 j는 각각 자신의 값에서 시작한다. 
			// 자신의 값 이하인 값으로는 만들 수 없기 때문에
			// 1원 만드는 방법 = 0원 만들기(dp[0])에서 가치 1의 동전을 쓰는 것이다
			// 따라서 dp[1] += dp[1 - coin[i]]
			// 이후 dp[2] += dp[2 - 1] 을 한다. 
			// 이건 2원을 만들 때, 1원을 만드는 방법에 1원을 더해주면 2원을 만드는 방법이 되는 것을 표현한것
			// dp[2] = {1, 1}이 되는거임
			// 나중에 coin[i] = 2 에 대해서 구할때 dp[2-coin[i]] coin[i] = 2 일 때의 경우에 들어오면
			// dp[2] = {1,1}, {2} 해서 2가지를 저장하는 것을 알 수 있다.
			// 걍 잘 모르겠다
		{
			dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k];

	return 0;
}