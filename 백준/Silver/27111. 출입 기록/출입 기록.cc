#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<bool> isIn(200005, false);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		if (b == 1)
		{
			if (!isIn[a])
				isIn[a] = true;
			else
				ans++;
		}
		else
		{
			if (!isIn[a])
				ans++;
			else
				isIn[a] = false;
		}
	}
	ans += count(isIn.begin(), isIn.end(), true);

	cout << ans;
	return 0;
}