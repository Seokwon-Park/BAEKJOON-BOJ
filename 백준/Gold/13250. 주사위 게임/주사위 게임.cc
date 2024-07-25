#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int n;
double dp[1000005];

double func(int k) // k개의 사탕을 받기위해 주사위를 던져야 하는 횟수의 기댓값.
{
	if (k <= 0) return 0.0; // 더이상 받아야할 사탕의 개수가 없으면 주사위를 던질 필요가 없음.
	if (dp[k] > -.5) return dp[k];
	double res = 0.0;

	for (int i = 1; i <= 6; i++)
	{
		res += (func(k - i) + 1) / 6.0; // k-i개의 사탕을 받기위해 주사위를 던져야 하는 횟수의 기댓값을 i=1~6까지 모두 더해준다.
	}

	return dp[k] = res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> n;
	
	fill(dp, dp + n + 1, -1.0);
	cout << fixed;
	cout << setprecision(9);
	cout << func(n);

	return 0;
}