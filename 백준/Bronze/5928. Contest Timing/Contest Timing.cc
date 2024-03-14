
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d, h, m;
	cin >> d >> h >> m;
	
	if (d == 11)
	{
		if (h == 11)
		{
			if (m < 11)
			{
				cout << -1;
				return 0;
			}
		}
		else if (h < 11)
		{
			cout << -1;
			return 0;
		}
	}
	else if (d < 11)
	{
		cout << -1;
		return 0;
	}

	int carry = 0;
	if (m - 11 < 0)
	{
		m = m - 11 + 60;
		carry = 1;
	}
	else
	{
		m = m - 11;
		
	}

	if (h - 11 - carry < 0)
	{
		h = h - 11 - carry + 24;
		carry = 1;
	}
	else
	{
		h = h - 11 - carry;
		carry = 0;
	}

	d = d - 11 - carry;

	cout << d * 24 * 60 + h * 60 + m;

	return 0;
}
