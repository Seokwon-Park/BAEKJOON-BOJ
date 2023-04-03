//BOJ4949 수식의 괄호 쌍
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> s;
	
	string input;
	bool chk;

	while (true)
	{		
		chk = true;
		getline(cin, input);
		if (input == ".") break;
		for (auto c : input)
		{
			if (c == '(' || c == '[')s.push(c);
			else if (c == ')' || c == ']')
			{
				char temp;
				if (s.empty())
				{
					chk = !chk;
					break;
				}
				else {
					temp = s.top();
					if (temp == '(' && c != ')')
					{
						chk = !chk;
						break;
					}
					else if (temp == '[' && c != ']')
					{
						chk = !chk;
						break;
					}
					else s.pop();
				}

			}
		}
		if (!s.empty())
		{
			chk = false;
			s = stack<char>();
		}		
		if (chk)
			cout << "yes\n";
		else
			cout << "no\n";
		

	}
	return 0;
}
