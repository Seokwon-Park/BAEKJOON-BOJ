#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc = 1;
	while (1)
	{
		
		string s;
		cin >> s;
		if (s[0] == '-')break;
		cout << tc << ". ";
		stack<char> st;
		int ans = 0; 
		for (auto c : s)
		{
			if (c == '{')
			{
				st.push(c);
			}
			else
			{
				if (st.empty())
				{
					ans++;
					st.push('{');
				}
				else
				{
					st.pop();
				}
			}
		}
		if (!st.empty())
		{
			ans += st.size() / 2;
		}


		cout << ans << '\n';
		tc++;
	}

	return 0;
}