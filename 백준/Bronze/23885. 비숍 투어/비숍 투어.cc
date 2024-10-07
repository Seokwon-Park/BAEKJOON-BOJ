#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	if (n == 1 || m == 1)
	{
		if (sx != ex || sy != ey)
			cout << "NO";
		else
			cout << "YES";
		return 0;
	}
	if (abs(sx - ex) % 2  == abs(sy - ey) % 2)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}

