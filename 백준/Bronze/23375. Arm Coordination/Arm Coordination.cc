#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[4] = { -1,1,1,-1 };
int dy[4] = { 1,1,-1,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;
	cin >> x >> y;
	int r;
	cin >> r;

	for (int i = 0; i < 4; i++)
	{
		cout << x + dx[i] * r << ' ' << y + dy[i] * r << '\n';
	}
	

	return 0;
}