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

	while (1)
	{
		int n;
		cin >> n;
		if (!n)break;
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;
			if (cur + m <= 300)
				cur += m;
		}
		cout << cur << '\n';
	}

	return 0;
}