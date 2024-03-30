#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w, n;
	cin >> h >> w >> n;
	vector<int> bricks(n);
	for (int i = 0; i < n; i++)
	{
		cin >> bricks[i];
	}

	int	curw = 0;
	int curh = 0;
	for (int i : bricks)
	{
		curw += i;
		if (curw >= w)
		{
			if (curw % w == 0)
			{
				curw = 0;
				curh++;
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		if (curw == 0 && curh == h)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}