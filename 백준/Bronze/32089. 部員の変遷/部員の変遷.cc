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
		if (n == 0) break;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		int st = 0;
		int en = 3;
		int cur = accumulate(v.begin(), v.begin() + 3, 0);
		int ans = cur;
		while (en < n)
		{
			cur -= v[st++];
			cur += v[en++];
			ans = max(cur, ans);
		}
		cout << ans << '\n';
	}

	return 0;
}