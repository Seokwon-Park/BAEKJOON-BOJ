#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int dp[32];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	// 스프라그 그런디 풀이 주석
	// if n = 3
	// 1개 남은 상황일때 공격할 차례 = 패배
	// 2 = 승리
	// 3 = 승리
	// 4 = 승리
	// 5 = 패배
	// 6 = 승리
	// ... 남은 돌수 % (n+1) == 1인 경우 무조건 패배함.
	// 그러면 31개인 경우 31 % 4 != 1이므로 31일 때 선공이 이기게 됨. 
	// 따라서 후공인 시온이는 무조건 진다.
	// 그러니 31개인 경우에 31 % (n+1) == 1 인 경우를 모두 찾으면 된다!
	for (int i = 1; i <= n; i++)
	{
		if (31 % (i + 1) == 1)
			cout << i << '\n';
	}

	return 0;
}