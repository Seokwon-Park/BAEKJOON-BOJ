#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int ans = 5000;
	while (cin >> n)
	{
		switch (n)
		{
		case 1:
			ans -= 500;
			break;
		case 2:
			ans -= 800;
			break;
		case 3:
			ans -= 1000;
			break;
		default:
			break;
		}
	}
	cout << ans;
	

	return 0;
}