#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	queue<int> q;
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
			q.push(x);
		}
		else if (!cmd.compare("pop"))
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (!cmd.compare("size"))
		{
			cout << q.size() << '\n';
		}
		else if (!cmd.compare("empty"))
		{
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (!cmd.compare("front"))
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << '\n';
		}
		else
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << '\n';
		}
	}
}
