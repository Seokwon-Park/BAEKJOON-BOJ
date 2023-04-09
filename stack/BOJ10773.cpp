#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	stack<int> s;
	for (int i = 0; i < k; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
			s.pop();
		else
			s.push(input);		
	}
	k = 0;
	while (!s.empty())
	{
		k += s.top();
		s.pop();
	}

	cout << k;

	return 0;
}
