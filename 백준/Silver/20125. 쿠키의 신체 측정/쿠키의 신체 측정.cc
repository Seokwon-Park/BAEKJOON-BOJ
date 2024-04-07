#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

char b[1005][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	//find head;
	int headx = 0, heady = 0;
	bool findHead = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] == '*')
			{
				headx = j;
				heady = i;
				findHead = true;
				break;
			}
		}
		if (findHead)break;
	}
	int heartx = headx;
	int hearty = heady + 1;

	int st = -1;
	int en = -1;
	for (int i = 0; i < n; i++)
	{
		if (st == -1 && b[hearty][i] == '*')
		{
			st = i;
		}
		if (st != -1 && b[hearty][i] == '_')
		{
			en = i;
			break;
		}
	}
	if (en == -1)
		en = n;
	int lefth = heartx - st;
	int righth = en - heartx - 1;

	int body = 0;
	int legst = 0;
	for (int i = hearty + 1; b[i][heartx] != '_'; i++)
	{
		body++;
		legst = i;
	}
	//left leg
	int leftleg = 0;
	int ix = legst + 1;
	while (ix < n && b[ix++][heartx - 1] != '_')
		leftleg++;

	ix = legst + 1;
	int rightleg = 0;
	while (ix <n && b[ix++][heartx + 1] != '_')
		rightleg++;

	cout << hearty + 1 << ' ' << heartx + 1 << '\n';
	cout << lefth << ' ' << righth << ' ' << body << ' ' << leftleg << ' ' << rightleg;

	return 0;
}