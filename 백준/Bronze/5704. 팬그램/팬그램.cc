#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int a[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		fill(a, a + 26, 0);
		string s;
		getline(cin, s);
		if (s == "*") break;
		for (auto& c : s)
		{
			if (isalpha(c))
				a[c - 'a']++;
		}
		int res = count_if(a, a + 26, [](const auto& i) {return i > 0; });
		if (res == 26) cout << 'Y';
		else cout << 'N';
		cout << '\n';
	}

	return 0;
}