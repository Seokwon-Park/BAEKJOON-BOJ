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
	while (1)
	{
		cin >> s;
		if (s == "*") break;
		int n = s.size();
		bool isSup = true;
		for (int i = 0; i <= n - 2; i++)
		{
			int sup = (n - i -1);
			set<string> st;
			for (int j = 0; j + i + 1 < n; j++)
			{
				string tmp = "";
				tmp += s[j];
				tmp += s[j + i + 1];
				st.insert(tmp);
			}
			if (st.size() != sup)
			{
				isSup = false;
				break;
			}
		}

		if (isSup)
			cout << s << " is surprising.";
		else
			cout << s << " is NOT surprising.";
		cout << '\n';
	}

	return 0;
}