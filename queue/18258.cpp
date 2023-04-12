#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
			
	int n = 0;
	cin >> n;
	queue<int> q;
	string instr;
	int val;

	for (int i = 0; i < n; i++)
	{		
		cin >> instr;
		if (instr.compare("push") == 0)
		{
			cin >> val;
			q.push(val);
		}
		else if (instr.compare("pop") == 0)
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.front()<< '\n';
				q.pop();
			}
		}
		else if (instr.compare("size") == 0)
		{
			cout << q.size() <<'\n';
		}
		else if (instr.compare("empty") == 0)
		{
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (instr.compare("front") == 0)
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << '\n';
			
		}
		else
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << '\n';					
	}


	return 0;
}
