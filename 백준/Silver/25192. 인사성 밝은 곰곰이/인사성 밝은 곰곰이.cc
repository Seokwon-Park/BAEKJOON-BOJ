#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	set<string> s;
	int sum = 0;
	int enterCnt = 0;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		if (input == "ENTER")
		{
			if (enterCnt > 0)
			{
				enterCnt--;
				sum += s.size();
			}
			enterCnt++;
			s.clear();
		}
		else
		{
			s.insert(input);
		}
	}
	
	if (enterCnt > 0)
	{
		enterCnt--;
		sum += s.size();
	}

	cout << sum;
	return 0;
}