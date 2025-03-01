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

	while (true)
	{
		int n, p;
		cin >> n;
		if (n == 0) break;
		cin >> p;
		set<int> result;
		if (p <= n / 2)
		{
			int rev = n - (p - 1) / 2 * 2;
			if (p % 2 == 1)
			{
				result.insert(p + 1);
			}
			else
			{
				result.insert(p-1);
			}
			result.insert(rev - 1);
			result.insert(rev);
		}
		else
		{
			int rev = ((n - p) / 2 +1)* 2;
			if (p % 2 == 1)
			{
				result.insert(p + 1);
			}
			else
			{
				result.insert(p - 1);
			}
			result.insert(rev - 1);
			result.insert(rev);
		}
		for (auto i : result)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}


	return 0;
}