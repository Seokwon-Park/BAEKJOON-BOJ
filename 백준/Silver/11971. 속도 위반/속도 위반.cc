#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int road[105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		fill(road + cur + 1, road + cur + a + 1, b);
		cur += a;
	}

	int st= 1;
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		for (int i = st; i < st+a; i++)
		{
			if (road[i] < b)
			{
				ans = max(b-road[i], ans);
			}
		}
		st += a;
	}
	cout << ans;



	return 0;
}