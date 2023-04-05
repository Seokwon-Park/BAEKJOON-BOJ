#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	int n;
	string cmd;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (!cmd.compare("push"))
		{
			int x;
			cin >> x;
			s.push(x);
		}
		else if (!cmd.compare("pop"))
		{
			if (s.empty())
				cout << "-1\n";
			else
			{
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (!cmd.compare("size"))
		{
			cout << s.size() << '\n';
		}
		else if (!cmd.compare("empty"))
		{
			if (s.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else
		{
			if (s.empty())
				cout << "-1\n";
			else
				cout << s.top() << '\n';
		}
	}
}
