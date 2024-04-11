#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack<char>st;
	string s;
	cin >> s;
	int cnt = 0;
	for (char c : s)
	{
		if (c == '(')
			st.push(c);
		else
		{
			if (st.empty())
				cnt++;
			else
				st.pop();
		}
	}
	if (!st.empty())
	{
		cnt += st.size();
	}
	cout << cnt;

	return 0;
}