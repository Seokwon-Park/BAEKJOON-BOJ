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

	int a, b, c;
	cin >> a >> b >> c;
	if (a == c)
	{
		cout << a << b << c;
	}
	else if (b == c)
	{
		cout << a << b << c << a; 
	}
	else
	{
		cout << a << b << c << b << a;
	}

	return 0;
}