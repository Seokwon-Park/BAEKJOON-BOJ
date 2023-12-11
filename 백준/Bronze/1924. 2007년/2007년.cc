#include <bits/stdc++.h>

using namespace std;

int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	cin >> x >> y;
	

	int daysum = 0;
	for (int i = 0; i < x-1; i++)
	{
		daysum += months[i];
	}
	daysum = daysum + y - 1;

	cout << days[daysum % 7];

	return 0;
}