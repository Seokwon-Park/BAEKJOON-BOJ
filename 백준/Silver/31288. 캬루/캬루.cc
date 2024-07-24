#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[1005][1005];
int rows[1005];
int cols[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		string p;
		cin >> n >> p;

		if (n == 1)
		{
			cout << 4 << ' ' << 2 << '\n';
			continue;
		}

		int total = 0;
		for (int i = 0; i < n; i++)
		{
			total += p[i] - '0';
		}

		int mod = total % 3;
		for (int i = 0; i < n; i++)
		{
			string str = p;
			int nth = str[i] - '0';
			if (nth - mod > 0)
			{
				str[i] = (str[i] - mod);
			}
			else
			{
				str[i] = (str[i] + (3 - mod));
			}
			cout << str << ' ' << 3 << '\n';
		}
	}

	return 0;
}