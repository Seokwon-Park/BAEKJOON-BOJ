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

	int n = 50;
	cout << n << ' ' << n - 1 << '\n';
	for (int i = 0; i < n-1; i++)
	{
		cout << 49-i << ' ' << 50-i<< ' ' << -1 << '\n';
	}


	return 0;
}