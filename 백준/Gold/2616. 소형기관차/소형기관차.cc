// 풀이를 떠올릴 수 없어서 다른 풀이를 보고 작성한 코드 입니다.
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int dp[4][50005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> pfsum(n+1);
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		pfsum[i] = pfsum[i - 1] + k;
	}
	int m;
	cin >> m;
	for(int i = 1; i<= 3; i++) // i번 차량에 대해서 조사
	{
		for (int j = i*m; j <= n; j++) // i*m번째 객차부터 - 1~m번째 차량부터 가능하기 때문에 그리고 2번째 자량은 m+1 ~ 2*m객차부터 
		{
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + pfsum[j] - pfsum[j - m]);
		}
	}

	cout << dp[3][n];


	return 0;
}