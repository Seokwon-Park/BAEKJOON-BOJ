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

	double m;
	cin >> m;

	cout << fixed << setprecision(1);
	if (m <= 30.0)
	{
		cout << m * 0.5;
	}
	else
	{
		//분침 하나에 1.5분이라고 봐야댐.
		cout << 15.0 + (m - 30.0) * 1.5;
	}

	return 0;
}