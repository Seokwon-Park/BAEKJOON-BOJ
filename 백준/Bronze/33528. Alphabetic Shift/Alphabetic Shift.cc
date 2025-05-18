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
	for (int i = 0; i < 26; i++)
	{
		for (auto c : s)
		{
			int ch = ((c - 'A' - i) + 26) % 26;
			cout << (char)('A' + ch);
		}
		cout << '\n';
	}

	return 0;
}
