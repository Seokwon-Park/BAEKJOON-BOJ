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

	string s;
	cin >> s;
	int n;
	cin >> n;
	double gbs = 0;
	string ans;
	while (n--)
	{
		string word;
		int g;
		cin >> word >> g;
		int ix = 0;
		for (auto c : word)
		{
			if (s[ix] == c)
			{
				ix++;
			}
			if (ix == s.size())
			{
				int add = word.size() - s.size();
				if (gbs < (double)g / add)
				{
					gbs = (double)g / add;
					ans = word;
				}
				break;
			}
		}
	}
	if (gbs != 0)
	{
		cout << ans;
	}
	else
	{
		cout << "No Jam";
	}

	
	return 0;
}