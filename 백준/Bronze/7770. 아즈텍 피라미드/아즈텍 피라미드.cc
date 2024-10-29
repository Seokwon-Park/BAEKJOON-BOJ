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
	cin >> n;
	int cur = 1;
	int sum = 0;
	int height = 1;
	int ans = 0;
	while (true)
	{
		sum += cur + 4 * (height - 1);
		cur += 4 * (height - 1);
		if (sum > n)
		{
			cout << height - 1;
			return 0;
		}
		height++;
	}

	return 0;
}