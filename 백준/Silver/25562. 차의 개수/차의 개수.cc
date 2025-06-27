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

	int n;
	cin >> n;
	int x = 1;
	cout << n*(n-1)/2 << '\n';
	for (int i = 1; i <= n; i++)
	{
		cout << x << ' ';
		x *= 2;
	}
	cout << '\n';

	cout << n - 1 << '\n';
	for (int i = 1; i <= n; i++)
	{
		cout << i << ' ';
	}

	return 0;
}
