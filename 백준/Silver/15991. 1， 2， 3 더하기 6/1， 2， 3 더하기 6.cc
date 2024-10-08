#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

ll dp1[100005]; // 어떤값 n을 1,2,3으로 표현하는 방법이라고 하자? // 순서가 다르면 다른방법으로


ll dp2[100005]; // 어떤값 n을 대칭으로 표현하는 방법이라고 하자

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	
	dp1[1] = 1;
	dp1[2] = 2;
	dp1[3] = 4;

	dp2[1] = 1;
	dp2[2] = 2;
	dp2[3] = 2;
	
	for (int i = 4; i <= 50000; i++)
	{
		dp1[i] = (dp1[i - 1] + dp1[i - 2] + dp1[i - 3])%MOD;
	}

	for (int i = 4; i <= 100000; i++)
	{
		if (i % 2 == 0)
		{
			dp2[i] += dp1[(i - 2) / 2]; // ex) 4 => 1, 1을 기준으로 dp[2]를 가운데 집어넣으면 남은값인 2를 양쪽에 똑같이 표현해야 하는데 이때는 
			//대칭 배열이 아니어도 괜찮기 때문에 dp1에서 가져온다. (1),2,(1);
			dp2[i] %= MOD;
			dp2[i] += dp1[i / 2]; //4 =>를 그냥 둘로 쪼개면 각변을 2로 표현해야 하는데 dp[2] = 2이므로 (2),(2) (1,1),(1,1)
			dp2[i] %= MOD;
		}
		else
		{
			//이하동문
			dp2[i] += dp1[(i - 1) / 2];
			dp2[i] %= MOD;
			dp2[i] += dp1[(i - 3) / 2];
			dp2[i] %= MOD;
		}
	}

	while (tc--)
	{
		int n;
		cin >> n;
		cout << dp2[n] << '\n';
	}

	return 0;
}

