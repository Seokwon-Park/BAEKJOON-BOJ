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
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		cin >> s;
		int a = 0;
		int b = 0;
		for (auto c : s)
		{
			if (c == 'a')
				a++;
			else
				b++;
		}
		cout << min(a, b) << '\n';
	}

	return 0;
}