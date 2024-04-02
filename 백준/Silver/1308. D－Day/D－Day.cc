#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int pfm[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
int month[13] = { 0, 31, 28, 31,30,31,30, 31,31, 30,31,30,31 };

bool isYoon(int n)
{
	if (n % 4 == 0)
	{
		if (n % 100 == 0)
		{
			if (n % 400 == 0)
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cy, cm, cd;
	int dy, dm, dd;
	int day = 0;
	cin >> cy >> cm >> cd;
	cin >> dy >> dm >> dd;

	if (cy + 1000 < dy)
	{
		cout << "gg";
		return 0;
	}
	else if (cy + 1000 == dy)
	{
		if (cm < dm)
		{
			cout << "gg";
			return 0;
		}
		else if(cm == dm)
		{
			if (cd <= dd)
			{
				cout << "gg";
				return 0;
			}
		}
	}

	if (cy == dy)
	{
		if (cm == dm)
		{
			day = dd - cd;
		}
		else
		{
			if (isYoon(cy))
			{
				day = pfm[dm] - pfm[cm] + dd - cd;
				if (cm <= 2 && dm  > 2)
					day++;
			}
			else // 윤년이 아닐때
			{
				day = pfm[dm] - pfm[cm] + dd - cd;
			}
		}
		cout << "D-" << day;
		return 0;
	}

	if (isYoon(cy))
	{
		if (cm > 2)
			day += 365 - pfm[cm] - cd;
		else
			day += 366 - pfm[cm] - cd;
	}
	else
		day += 365 - pfm[cm] - cd;
	cy++;


	if (isYoon(dy))
	{
		if (dm > 2)
			day += pfm[dm] + dd+1;
		else
			day += pfm[dm] + dd;
	}
	else
		day += pfm[dm] + dd;

	for (int i = cy; i < dy; i++)
	{
		if (isYoon(i))
			day += 366;
		else
			day += 365;

	}
	cout << "D-" << day;

	return 0;
}