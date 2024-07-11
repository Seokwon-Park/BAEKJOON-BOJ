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

	int tc;
	cin >> tc;
	const ll sec = 1e8;
	for (int i = 0; i < tc; i++)
	{
		string s;
		ull n, t, l;
		cin >> s >> n >> t >> l;
		ull res = 0;
		ull limit = sec * l;
		bool isPass = true;
		if (s == "O(N)")
		{
			res = n * t;
			if (res > limit)
				isPass = false;
		}
		else if (s == "O(2^N)")
		{
			res = 1;
			for (int i = 0; i <= n; i++)
			{
				ull tmp = res << i;
				if (tmp * t > limit)
				{
					isPass = false;
					break;
				}
			}
		}
		else if (s == "O(N^2)")
		{
			res = n * n * t;
			if (res > limit)
				isPass = false;
		}
		else if (s == "O(N^3)")
		{
			res = n * n * n * t;
			if (res > limit)
				isPass = false;
		}
		else
		{
			res = 1;
			for (int i = 1; i <= n; i++)
			{
				res *= i;
				if (res * t > limit)
				{
					isPass = false;
					break;
				}
			}

		}
		if (isPass)
			cout << "May Pass.";
		else
			cout << "TLE!";
		cout << '\n';
	}

	return 0;
}