#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		double x, y;
		cin >> x >> y;
		if (x == 0 && y == 0)
		{
			cout << "AXIS\n";
			break;
		}
		else if (x == 0 || y == 0)
		{
			cout << "AXIS\n";
		}
		else
		{
			if (x > 0)
			{
				if (y > 0)
					cout << "Q1\n";
				else
					cout << "Q4\n";
			}
			else
			{
				if (y > 0)
					cout << "Q2\n";
				else
					cout << "Q3\n";
			}
		}

	}

	return 0;
}