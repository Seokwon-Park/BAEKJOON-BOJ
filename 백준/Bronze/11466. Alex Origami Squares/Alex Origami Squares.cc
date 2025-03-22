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

	double w, h;
	cin >> w >> h;
	
	cout << fixed << setprecision(3);
	cout << max({ min( h, w / 3.0), min( w, h / 3.0), min(w / 2.0, h / 2.0) });

	return 0;
}