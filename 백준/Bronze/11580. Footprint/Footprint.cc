#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int dx[256];
int dy[256];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string cmd;
	cin >> cmd;

	map<int, map<int, bool>> v;
	int x = 0;
	int y = 0;
	dx['E'] = 1;
	dy['E'] = 0;
	dx['W'] = -1;
	dy['W'] = 0;
	dx['S'] = 0;
	dy['S'] = -1;
	dx['N'] = 0;
	dy['N'] = 1;

	v[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		x += dx[cmd[i]];
		y += dy[cmd[i]];
		v[x][y] = 1;
	}

	int ans = 0;
	for(auto vv:v)
	{
		ans += vv.second.size();
	}
	cout << ans;

	return 0;
}