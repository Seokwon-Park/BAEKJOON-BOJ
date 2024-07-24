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

	int a, b, c;
	cin >> a >> b >> c;

	if (a == 0)
		cout << c * c - b;
	else if (b == 0)
		cout << c * c - a;
	else
		cout << (int)sqrt(a + b);


	return 0;
}