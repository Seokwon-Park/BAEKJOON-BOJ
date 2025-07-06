#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int rsp(char me, char guile)
{
	if (me == guile) return 0;
	if (me == 'R' && guile == 'S' ||
		me == 'S' && guile == 'P' ||
		me == 'P' && guile == 'R') return 1;
	else
	{
		return -1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string me, guile;
	cin >> me >> guile;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += rsp(me[i], guile[i]);
	}

	cout << (result > 0 ? "victory" : "defeat");

	return 0;
}