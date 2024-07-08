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

	int n;
	cin >> n;

	while (n--)
	{
		string s;
		string p;
		cin >> s >> p;

		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == p[0])
			{
				bool isFind = true;
				for (int j = 0; j < p.size(); j++)
				{
					if (s[i + j] != p[j])
					{
						isFind = false;
						break;
					}
				}
				if (isFind)
				{
					i += p.size() - 1;
					ans++;
				}
				else
				{
					ans++;
				}
			}
			else
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}



	return 0;
}