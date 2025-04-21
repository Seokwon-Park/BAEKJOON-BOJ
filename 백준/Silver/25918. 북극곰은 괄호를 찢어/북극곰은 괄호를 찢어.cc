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

	int n;
	cin >> n;
	string s;
	cin >> s;
	stack<char> st;
	int res = 0;
	for (auto c : s)
	{
		if (st.empty())
		{
			st.push(c);
		}
		else
		{
			if (st.top() == '(')
			{
				if (c == '(')
				{
					st.push(c);
				}
				else
				{
					st.pop();
				}
			}
			else
			{
				if (c == '(')
				{
					st.pop();
				}
				else
				{
					st.push(c);
				}
			}
		}
		res = max(res, (int)st.size());
	}
	if (!st.empty())
	{
		cout << -1;
	}
	else
	{
		cout << res;
	}

	
	return 0;
}