#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	double b, c, a1, a2;
	cin >> b >> c >> a1 >> a2;
	cout << fixed << setprecision(6) << (b + sqrt(b * b + 4 * c)) / 2;

	return 0;
}