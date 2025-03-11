#include <bits/stdc++.h>

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
	
	int n;
	cin >> n;
	int x, s;
	cin >> x >> s;
	bool chk = false;
	for (int i = 0; i < n; i++)
	{
		int c, p;
		cin >> c >> p;
		if (c <= x && p > s)
		{
			chk = true;
		}
	}
	cout << (chk ? "YES" : "NO");



	return 0;
}