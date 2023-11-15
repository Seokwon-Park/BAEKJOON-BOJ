#include <bits/stdc++.h>

using namespace std;

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
			cin >> input;
			st.push(input);
			break;
		case 2:
			if (st.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
			break;
		case 3:
			cout << st.size() << '\n';
			break;
		case 4:
			if (st.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
			break;
		case 5:
			if (!st.empty())
				cout << st.top() << '\n';
			else
				cout << -1 << '\n';
			break;
		}
	}

	return 0;
}