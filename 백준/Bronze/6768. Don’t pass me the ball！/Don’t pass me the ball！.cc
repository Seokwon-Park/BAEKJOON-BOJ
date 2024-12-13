#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

//1명 빼고 n-1명중에서 3명 뽑기
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 1;
	for (int i = 0; i < 3; i++)
	{
		ans *= (n - 1 - i);
	}
	cout << ans / 6;

	return 0;
}