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
	
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];

	int curbook = 0;
	int curw = 0;
	int curbox = 0;
	int ans = 0;
	while (curbook < m)
	{
		if (curw + b[curbook] <= v[curbox])
		{
			curw += b[curbook];
			curbook++;
		}
		else
		{
			ans += v[curbox] - curw;
			curw = 0;
			curbox++;
		}
	}

	ans += v[curbox] - curw;
	curw = 0;
	curbox++;

	for (int i = curbox; i < n; i++)
	{
		ans += v[i];
	}

	cout << ans;


	return 0;
}
