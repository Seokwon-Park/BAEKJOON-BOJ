#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	vector<int> arr;
	string answer;
	int n;
	cin >> n;
	bool chk = true;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);

	}
	s.push(-1);
	int idx = 0;
	int x = 1;
	for (int i = 1; i <= n * 2; i++) 
	{	
		if (i > 1)
			if (s.top() == arr[idx])
				{
					s.pop();
					answer.push_back('-');
					idx++;
				}				
			else
			{
				if (x == n + 1)
				{
					chk = false; 
					break;
				}
				s.push(x++);
				answer.push_back('+');
			}
		else
		{
			s.push(x++);
			answer.push_back('+');
		}
	}
	if (chk)
		for (auto c : answer) cout << c << '\n';
	else
		cout << "NO";

	return 0;
}


