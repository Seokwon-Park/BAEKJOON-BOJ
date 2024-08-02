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
	vector<int> v(n);
	set<int> s;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		s.insert(v[i]);
	}

	int ans = 1;
	for (int i : s)
	{
		int prev = 0;
		int cont = 0;
		for (int j = 0; j < n; j++)
		{
			if (v[j] == i)continue;
			if (v[j] != prev)
			{
				cont = 1;
				prev = v[j];
			}
			else
			{
				cont++;
				ans = max(ans, cont);
			}
		}
	}
	cout << ans;

	return 0;
}