#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int a[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int mx = n;
		while (n != 1)
		{
			mx = max(mx, n);
			if (n % 2)
				n = n * 3 + 1;
			else
				n /= 2;
		}
		cout << mx << '\n';
	}

	return 0;
}