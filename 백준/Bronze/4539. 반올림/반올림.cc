#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		int zeros = 0;
		while (x / 10)
		{
			int tmp = x % 10;
			x /= 10;
			zeros++;
			if (tmp >= 5)
			{
				x++;
			}
		}
		cout << x;
		while (zeros--) cout << 0;
		cout << '\n';


	}



	return 0;
}