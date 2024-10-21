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

	ll n;
	cin >> n;
	bool st;
	cin >> st;
	if (n >= 6)
		cout << "Love is open door";
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			st = !st;
			cout << st << '\n';
		}
	}

	return 0;
}