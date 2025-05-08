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

	int ans = 0;
	int x;
	cin >> x;
	int a;
	cin >> a;
	if (a)
	{
		ans += x;
	}

	int b;
	cin >> b;
	if (b)
	{
		if (a)
		{
			int c;
			cin >> c;
			if (c)
			{
				ans++;
			}
		}
		else
		{

		for (int i = 0; i < x; i++)
		{
			int c;
			cin >> c;
			if (c)
			{
				ans++;
			}
		}
		}
	}
	cout << ans;



	return 0;
}