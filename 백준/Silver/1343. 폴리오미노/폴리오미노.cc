#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string b;
	cin >> b;

	string answer = "";
	
	int xcnt = 0;
	for (int i = 0; i < b.length(); i++)
	{
		if (b[i] == 'X')
		{
			xcnt++;
		}
		else
		{
			if (xcnt == 0)
			{
				answer += b[i];
			}
			else if (xcnt == 2)
			{
				answer += "BB";
				answer += b[i];
				xcnt = 0;
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
		if (xcnt == 4)
		{
			answer += "AAAA";
			xcnt = 0;
		}
	}

	if (xcnt != 0)
	{
		if (xcnt == 2)
		{
			answer += "BB";
			xcnt = 0;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}

	cout << answer;


	return 0;
}