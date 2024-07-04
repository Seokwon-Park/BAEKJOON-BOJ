#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	// 백기의 조건 : 약수가 홀수여야함 = 완전 제곱수 구하라는 말이다 대충..
	int ans = 0;
	for (int i = 1; i * i <= n; i++)
	{
		ans++;
	}
	cout << ans;

	return 0;
}
