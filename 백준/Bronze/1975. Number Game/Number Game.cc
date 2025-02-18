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

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x;
		cin >> x;
		int result = 0;
		int tmp;
		for (int i = 2; i <= x; i++)
		{
			tmp = x;
			while (tmp % i == 0)
			{
				tmp /= i;
				result++;
			}
		}
		cout << result << '\n';
	}

	return 0;
}