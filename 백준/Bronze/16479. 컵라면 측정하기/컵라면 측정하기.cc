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

	double k, d1, d2;
	cin >> k >> d1 >> d2;

	double d = (d1 - d2)/2;
	
	cout << fixed << setprecision(6);
	cout << k * k - d * d;


	return 0;
}
