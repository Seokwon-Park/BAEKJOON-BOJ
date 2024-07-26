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

	int n;
	cin >> n;

	int step = 0;
	int res = n;
	while (res >= 10)
	{
		int tmp = 1;
		while (res)
		{
			tmp *= res % 10;
			res /= 10;
		}
		res = tmp;
		step++;
	}
	cout << step;


	return 0;
}