#include <bits/stdc++.h>

using namespace std;

int Pr(char c)
{
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	return 0;
}

bool isOp(char c) 
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string exp;
	cin >> exp;
	
	string pfx = "";
	stack<char> op;
	for (char c : exp)
	{
		if (isOp(c))
		{
			while (!op.empty() && Pr(op.top()) >= Pr(c))
			{
				pfx += op.top(); op.pop();
			}
			op.push(c);
		}
		else if (c == '(')
		{
			op.push(c);
		}
		else if( c== ')')
		{
			while (!op.empty() && op.top() != '(')
			{
				pfx += op.top(); op.pop();
			}
			op.pop();
		}
		else
		{
			pfx += c;
		}
	}

	while (!op.empty())
	{
		pfx += op.top(); op.pop();
	}

	cout << pfx;

	return 0;
}
