#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double x1, y1, r1;
	double x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (d < r1 + r2)
		cout << "YES";
	else
		cout << "NO";

	return 0; 
}
