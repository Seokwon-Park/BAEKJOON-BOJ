#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll dp[105]; // n번 눌렀을 때 dp 크기

// long long 쓰는거 맨날 틀림
// 풀이 기억용 메모 - ctrl a+c+v 하는 데 총 3번이 최소 들어간다. 이후 ctrl + v 를 누르는 횟수는 1회씩
// 이걸 j로 초기 값을 잡아서 i번 눌렀을때 j에 대한 이중 for문으로 ctrl+a+c , ctrl+v(j%3+2)회 에 대해 최댓값을 찾아준다.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	for (int i = 4; i <= n; i++)
	{
		dp[i] = i;
		for (int j = 3; j < i; j++)
		{
			dp[i] = max(dp[i], dp[i-j]*(j%3+2));
		}
	}

	cout << dp[n];
	

	return 0;
}