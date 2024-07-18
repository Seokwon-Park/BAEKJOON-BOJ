#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;

	stack<int> st;

	for (auto c : s)
	{
		if (c == '(')st.push(-1);
		else if (c == 'H') st.push(1);
		else if (c == 'C') st.push(12);
		else if (c == 'O') st.push(16);
		else if (c == ')')
		{
			int tmp = 0;
			while (st.top() != -1)
			{
				tmp += st.top();
				st.pop();
			}
			st.pop();
			st.push(tmp);
		}
		else
		{
			int tmp = st.top();
			st.pop();
			tmp *= c-'0';
			st.push(tmp);
		}
	}

	int ans = 0;
	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	cout << ans;

	return 0;
}
