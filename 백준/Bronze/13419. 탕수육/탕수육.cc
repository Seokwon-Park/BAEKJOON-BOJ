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
		string s;
		cin >> s;
		string a = "";
		string b = "";
		if (s.size() % 2 == 1)
		{
			for (int i = 0; i < s.size()*2; i+=2)
			{
				a += s[i % s.size()];
				b += s[(1 + i) % s.size()];
			}
		}
		else
		{
			for (int i = 0; i < s.size(); i ++)
			{
				if (i % 2 == 0)
					a += s[i];
				else
					b += s[i];
			}
		}
		cout << a << '\n' << b << '\n';
	}



	return 0;
}
