#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int getIX(int s, int y)
{
	if (y <= 2) return 0;
	else if (y <= 4)
	{
		if (s == 0) return 1;
		else return 2;
	}
	else
	{
		if (s == 0) return 3;
		else return 4;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(5);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int s, y;
		cin >> s >> y;
		int ix = getIX(s, y);
		if (v[ix] == 0)ans++;
		v[ix]++;
		if (v[ix] == k)
			v[ix] = 0;
	}
	cout << ans;


	return 0;
}