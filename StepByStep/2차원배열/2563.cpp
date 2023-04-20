#include <bits/stdc++.h>

using namespace std;

int paper[101][101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int answer = 0;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		for(int i = y; i<y+10; i++)
			for(int j = x; j< x+10; j++)
			{ 
				if (paper[i][j] == 0)
					answer++;
				paper[i][j] = 1;
				
			}

	}

	cout << answer;

	return 0;
}
