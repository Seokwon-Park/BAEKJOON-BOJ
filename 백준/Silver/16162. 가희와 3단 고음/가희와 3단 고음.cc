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

	int n, a, d;
	cin >> n >> a >> d;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int x = 0;
	int cur = 0;
	while (cur < n)
	{
		int res = a + d * x;
		if (v[cur] == res)
			x++;
		cur++;
	}
	cout << x;

	return 0;
}