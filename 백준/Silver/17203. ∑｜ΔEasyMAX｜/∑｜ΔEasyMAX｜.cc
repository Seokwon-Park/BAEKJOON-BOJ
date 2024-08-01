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

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < q; i++)
	{
		int st, en;
		cin >> st >> en;
		st--;
		en--;
		int res = 0;
		if (en - 1 < st)
			cout << 0;
		else
		{
			for (int j = st; j <= en - 1; j++)
			{
				res += abs(a[j + 1] - a[j]);
			}
			cout << res;
		}
		cout << '\n';
	}

	return 0;
}