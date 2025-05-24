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

	int n, d, a, b ,x0;
	cin >> n >> d >> a >> b >> x0;
	int l = a * x0 + b;
	cout << l << '\n';
	if (a == 0)
	{
		cout << "0 0\n";
	}
	else
	{
		cout << n << ' ' << d * abs(a);
	}

	return 0;
}