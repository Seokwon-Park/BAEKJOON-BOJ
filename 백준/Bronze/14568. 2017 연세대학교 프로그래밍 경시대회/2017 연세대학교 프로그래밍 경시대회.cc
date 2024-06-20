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

	int ans = 0;
	for (int a = 1; a <= n; a++)
	{
		if (a % 2) continue;
		for (int b = 1; b <= n; b++)
		{
			for(int c = 1; c<= n; c++)
			{
				if (c < b+2) continue;
				if (a + b + c == n)
					ans++;
			}
		}
	}
	cout << ans;

	return 0;
}