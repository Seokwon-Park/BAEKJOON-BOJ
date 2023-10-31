#include <bits/stdc++.h>

using namespace std;
int r[3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		cin >> r[0] >> r[1] >> r[2];
		int sum = r[0] + r[1] + r[2];

		sort(r, r + 3);
		if (sum == 0) break;

		if (r[0]+r[1] <= r[2])
		{
			cout << "Invalid\n";
		}
		else
		{
			if (r[0] == r[1] && r[1] == r[2])
			{
				cout << "Equilateral\n";
			}
			else if (r[0] == r[1] || r[1] == r[2] || r[2] == r[0])
			{
				cout << "Isosceles\n";
			}
			else
			{
				cout << "Scalene\n";
			}
		}
	}

	return 0;
}