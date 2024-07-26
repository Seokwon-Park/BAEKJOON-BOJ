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

	int a, b, c;
	cin >> a >> b >> c;
	int t;
	cin >> t;
	int ans = 0;
	for (int i = 0; i < t; i++)
	{
		int score = 0;
		for (int j = 0; j < 3; j++)
		{
			int aa, bb, cc;
			cin >> aa >> bb >> cc;
			score += a * aa + b * bb + c * cc;
		}
		ans = max(ans, score);
	}
	cout << ans;


	return 0;
}