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

	int n, l;
	cin >> n >> l;

	int ans = 0;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		char prev= '\0';
		int line = 0;
		for (char cur : s)
		{
			if (cur != prev)
			{
				if (cur == '1')
				{
					line++;
				}
				prev = cur;
			}
		}
		if (ans < line)
		{
			ans = line;
			num = 1;
		}
		else if (ans == line)
		{
			num++;
		}
	}
	cout << ans << ' ' << num;

	return 0;
}