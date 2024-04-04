#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		set<int> st;
		string s;
		cin >> s;

		for (auto c : s)
		{
			st.insert(c - '0');
		}

		cout << st.size() << '\n';
	}

	return 0;
}