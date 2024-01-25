#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	getline(cin, str);

	stack<char> st;
	bool is_open = false;
	string res = "";
	for (auto c : str)
	{
		if (c == '<')
		{
			is_open = true;
			while (!st.empty())
			{
				res += st.top();
				st.pop();
			}
			res += '<';
		}
		else if (c == '>')
		{
			is_open = false;

			res += '>';
		}
		else if (c == ' ')
		{
			while (!st.empty())
			{
				res += st.top();
				st.pop();
			}
			res += ' ';
		}
		else
		{
			if (is_open)
				res += c;
			else
				st.push(c);
		}
	}
	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}

	cout << res;


	return 0;
}