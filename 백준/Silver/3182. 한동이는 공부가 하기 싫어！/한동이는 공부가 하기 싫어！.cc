#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int nxt[1005];
int v[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> nxt[i];
	}

	int mx = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(v, v + n + 1, false);
		v[i] = true;
		int cnt = 1;
		int cur = nxt[i];
		while(!v[cur] && cur != 0)
		{
			v[cur] = true;
			cnt++;
			cur = nxt[cur];
		}
		if (cnt > mx)
		{
			mx = cnt;
			ans = i;
		}
	}
	cout << ans;


	return 0;
}

