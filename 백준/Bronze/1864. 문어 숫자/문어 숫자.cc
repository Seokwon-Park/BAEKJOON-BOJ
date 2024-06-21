#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int v[256];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	v['-'] = 0;
	v['\\'] = 1;
	v['('] = 2;
	v['@'] = 3;
	v['?'] = 4;
	v['>'] = 5;
	v['&'] = 6;
	v['%'] = 7;
	v['/'] = -1;


	while (1)
	{
		string s;
		cin >> s;
		if (s == "#")
			break;

		int oct = 1;
		for (int i = 0; i < s.size()-1; i++)
		{
			oct *= 8;
		}

		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			res += v[s[i]] * oct;
			oct/=8;
		}

		cout << res << '\n';
	}

	return 0;
}