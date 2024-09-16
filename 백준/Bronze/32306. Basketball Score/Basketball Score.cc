#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int team1 = a + b * 2 + c * 3;
	cin >> a >> b >> c;
	int team2 = a + b * 2 + c * 3;
	if (team1 == team2)cout << 0;
	else if (team1 > team2) cout << 1;
	else cout << 2;


	return 0;
}
