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

	int a, b;
	cin >> a >> b;
	int st = (a + b - 1) % 4+1;
	int c, d;
	cin >> c >> d;
	st += (c + d - 1) % 4;
	st = (st-1)%4+1;
	cout << st;

	return 0;
}