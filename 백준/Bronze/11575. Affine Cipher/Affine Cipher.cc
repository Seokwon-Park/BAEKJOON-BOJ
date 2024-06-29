#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		for (auto& c : s)
		{
			int ix = c - 'A';
			int res = (a * ix + b) % 26;
			c = 'A' + res;
		}
		cout << s << '\n';
	}
	

	return 0;
}