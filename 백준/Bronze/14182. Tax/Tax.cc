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

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		if (n <= 1'000'000)
		{
			cout << n;
		}
		else if (n <= 5'000'000)
		{
			cout << n * 9 / 10;
		}
		else
		{
			cout << n * 4 / 5;
		}
		cout << '\n';
	}

	return 0;
}