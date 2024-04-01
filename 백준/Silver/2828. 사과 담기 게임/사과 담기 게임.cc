#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int st = 1;
	int ed = m;
	int j;
	cin >> j;
	int moved = 0;
	for (int i = 0; i < j; i++)
	{
		int pos;
		cin >> pos;
		while (pos > ed)
		{
			st++;
			ed++;
			moved++;
		}
		while (pos < st)
		{
			st--;
			ed--;
			moved++;
		}
	}
	cout << moved;


	return 0;
}