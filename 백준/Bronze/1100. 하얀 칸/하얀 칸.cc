#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string chess[8];

	for (int i = 0; i < 8; i++)
	{
		cin >> chess[i];
	}

	int answer = 0;

	for (int i = 0; i < 64; i++)
	{		
		int x = i % 8;
		int y = i / 8;
		if (y % 2 == 0)
		{
			if (x % 2 == 0 && chess[y][x] == 'F')
				answer++;
		}
		else
		{	
			if (x % 2 == 1 && chess[y][x] == 'F')
				answer++;
		}
	}

	cout << answer;
		
	return 0;
}