#include <bits/stdc++.h>

using namespace std;

int n;
int cnt = 0;
bool a_op, b_op;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<char> s;
	string input;
	//n <= 50, m <= n
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (auto ch : input)
		{
			if (!s.empty() && s.top() == ch)
				s.pop();
			else
				s.push(ch);
		}
		if (s.empty())
			cnt++;
		else
			while (!s.empty())
				s.pop();
	}

	cout << cnt;
	
	return 0;
}

