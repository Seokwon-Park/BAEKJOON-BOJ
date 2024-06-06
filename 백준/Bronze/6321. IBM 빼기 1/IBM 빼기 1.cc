#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		string s;
		cin >> s;
		for (auto& c : s)
		{
			c = 'A' + (c - 'A' + 1) % 26;
		}
		cout << "String #" << i << '\n';
		cout << s << "\n\n";

	}

	return 0;
}