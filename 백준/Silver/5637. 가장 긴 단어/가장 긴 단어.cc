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
	string ans = "";
	while (1)
	{
		getline(cin, s);
		string tmp = "";
		for (auto c : s)
		{
			if (isalpha(c) || c == '-')
				tmp += tolower(c);
			else
			{
				if (!tmp.empty())
				{
					if (tmp.size() > ans.size())
						ans = tmp;
					tmp = "";
				}
			}
		}
		if (tmp == "e-n-d")
		{
			cout << ans;
			return 0;
		}
	}
	
	

	return 0;
}