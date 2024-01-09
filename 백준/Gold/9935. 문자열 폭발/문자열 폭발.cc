#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> st;

	string str, bb;
	cin >> str >> bb;

	for (int i = 0; i < str.length(); i++)
	{
		st.push(str[i]);
		if (!st.empty() && st.top() == bb[bb.length() - 1])
		{
			bool is_bomb = true;
			string tmp = "";
			for (int j = bb.length() - 1; j >= 0; j--)
			{
				if (!st.empty())
				{
					if (st.top() == bb[j])
					{
						tmp += st.top();
						st.pop();
					}
					else
					{
						is_bomb = false;
						break;
					}
				}
				else
				{
					is_bomb = false;
					break;
				}
			}
			if (!is_bomb)
			{
				for (int j = tmp.length() - 1; j >= 0; j--)
				{
					st.push(tmp[j]);
				}
			}
		}
	}

	deque<char> ans;
	while (!st.empty())
	{
		ans.push_front(st.top());
		st.pop();
	}

	if (ans.empty())
	{
		cout << "FRULA";
	}
	else
	{
		for (auto i : ans)
		{
			cout << i;
		}
	}

	return 0;
}