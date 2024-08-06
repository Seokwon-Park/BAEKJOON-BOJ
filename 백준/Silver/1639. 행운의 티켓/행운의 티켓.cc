#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int ans = 0;
	for (int n = 1; n <= s.size() / 2; n++)
	{
		bool findAns = false;
		for (int i = 0; i < s.size() - n * 2 + 1; i++)
		{
			string tmp = s.substr(i, n * 2);
			int l = 0;
			int r = 0;
			for (int j = 0; j < n; j++)
			{
				l += tmp[j] - '0';
				r += tmp[n + j] - '0';
			}
			bool isLucky = l == r;
			if (isLucky)
			{
				findAns = true;
				break;
			}
		}
		if (findAns)
		{
			ans = max(ans, n);
		}
	}
	cout << ans*2;

	return 0;
}