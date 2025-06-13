
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

char b[25][25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int mx = 0;
	for (int i = 0; i < 5; i++)
	{
		int a, b;
		cin >> a >> b;
		mx = max(mx, a + b * 10);
	}

	cout << max(0,mx - (n + m * 10) + 1);

	return 0;
}