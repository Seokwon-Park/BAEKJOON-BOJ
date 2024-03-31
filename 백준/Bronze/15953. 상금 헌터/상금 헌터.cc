#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		int prize = 0;
		if (a > 21) a = 0;
		if (b > 31)b = 0;
		if (a != 0)
		{
			if (a <= 1) prize += 5000000;
			else if (a <= 3)prize += 3000000;
			else if (a <= 6)prize += 2000000;
			else if (a <= 10)prize += 500000;
			else if (a <= 15)prize += 300000;
			else prize += 100000;
		}
		if (b != 0)
		{
			if (b <= 1) prize += 5120000;
			else if (b <= 3)prize += 2560000;
			else if (b <= 7)prize += 1280000;
			else if (b <= 15)prize += 640000;
			else prize += 320000;
		}
		cout << prize << '\n';
	}

	return 0;
}