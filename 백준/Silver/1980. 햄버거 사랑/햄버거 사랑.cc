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

	int n, m, t;
	cin >> n >> m >> t;
	if (n > m)
		swap(n, m);


	// 생각해보면 먹은 버거 개수를 최대로 하면서 나머지가 n이상일 수 없다.
	int bg= INF;
	for (int i = 0; i < n; i++)
	{
		int tmp = t - i;
		for (int j = 0; j <= t / m; j++)
		{
			int tmp2 = tmp - m * j;
			if (tmp2 % n == 0)
			{
				cout << j+tmp2/n << ' ' << i << '\n';
				return 0;
			}
		}
	}

	return 0;
}