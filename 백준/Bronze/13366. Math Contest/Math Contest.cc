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
		int n = 0;
		for (auto c : s)
		{
			n += c - '0';
		}
		cout << (n % 9 == 0 ? "YES" : "NO");
		cout << '\n';
	}

	return 0;
}
