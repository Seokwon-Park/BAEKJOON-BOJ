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

	int t, x, n;
	cin >> t >> x >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		bool isAttend = false;
		for (int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			if (a == x)
			{
				isAttend = true;
			}
		}
		if (!isAttend)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}