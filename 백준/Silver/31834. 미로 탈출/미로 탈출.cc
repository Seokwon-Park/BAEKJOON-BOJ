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
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, s, e;
		cin >> n >> s >> e;
		int res1 = (s == 1 || s == n);
		int res2 = (e == 1 || e == n);
		if (res1)
		{
			if (res2)
			{
				cout << 0;
			}
			else
			{
				cout << 1;
			}
		}
		else if (res2)
		{
			if (res1)
			{
				cout << 0;
			}
			else
			{
				if(abs(s-e) == 1)
				{
					cout << 1;
				}
				else
				{
					cout << 2;
				}
			}
		}
		else
		{
			if (abs(s - e) == 1)
			{
				cout << 1;
			}
			else
			{
				cout << 2;
			}
		}
		cout << '\n';
	}
	

	return 0;
}