#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

bool visited[6][6];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int sx, sy;
	int px = -1;
	int py = -1;
	int cx, cy;
	bool isValid = true;
	for (int i = 0; i < 36; i++)
	{
		string loc;
		cin >> loc;
		if (px == -1 && py == -1)
		{
			px = loc[0] - 'A';
			py = loc[1] - '0';
			sx = px;
			sy = py;
			visited[px][py] = true;
			continue;
		}
		cx = loc[0] - 'A';
		cy = loc[1] - '0';
		if (visited[cx][cy])
		{
			isValid = false;
		}
		if ((abs(px - cx) == 2 && abs(py - cy) == 1) || (abs(px - cx) == 1 && abs(py - cy) == 2))
		{
			visited[cx][cy] = true;
			px = cx;
			py = cy;
		}
		else
		{
			isValid = false;
		}
	}
	
	if (!((abs(px - sx) == 2 && abs(py - sy) == 1) || (abs(px - sx) == 1 && abs(py - sy) == 2)))
		isValid = false;



	if (isValid)
		cout << "Valid";
	else
		cout << "Invalid";


	return 0;
}