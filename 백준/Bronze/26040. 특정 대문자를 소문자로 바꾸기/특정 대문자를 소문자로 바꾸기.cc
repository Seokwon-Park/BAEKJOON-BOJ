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
	vector<char> v;
	char ch;
	while (cin >> ch)
	{
		for (auto& c : s)
		{
			if (c >= 'a' && c <= 'z')
			{
				continue;
			}
			else
			{
				if (ch == c)
				{
					c = c - 'A' + 'a';
				}
			}
		}
	}
	cout << s;




	return 0;
}



