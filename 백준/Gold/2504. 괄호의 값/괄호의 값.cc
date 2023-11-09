#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	stack<char> s;

	int sum = 0;
	int mul = 1;
	for (int i = 0; i< str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[')
		{
			if (str[i] == '(')
				mul *= 2;
			else
				mul *= 3;
			s.push(str[i]);
		}
		else if(!s.empty())
		{
			if (str[i] == ')')
			{
				char c = s.top();
				if (c == '(')
				{
					if (str[i - 1] == ')' || str[i - 1] == ']')
					{
						mul /= 2;
					}
					else
					{
						sum += mul;
						mul /= 2;
					}
				}
				else
				{
					cout << 0;
					return 0;
				}
			}
			if (str[i] == ']')
			{
				char c = s.top();
				if (c == '[')
				{
					if (str[i - 1] == ')' || str[i - 1] == ']')
					{
						mul /= 3;
					}
					else
					{
						sum += mul;
						mul /= 3;
					}
				}
				else
				{
					cout << 0;
					return 0;
				}
			}
			s.pop();
		}
		else
		{
			cout << 0;
			return 0;
		}
	}

	if (s.empty())
	{
		cout << sum;
	}
	else
	{
		cout << 0;
	}

	return 0;
}