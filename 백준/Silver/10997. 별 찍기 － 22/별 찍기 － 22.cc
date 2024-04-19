#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

vector<string> b(4*100 - 1, string(4*100-3, ' '));

void func(int x, int y, int n)
{

	int w = 4 * n - 3;
	int h = 4 * n - 1;

	for (int i = x; i < x+w; i++)
	{
		b[y][i] = '*';
	}

	for (int i = y; i < y + h; i++)
	{
		b[i][x] = '*';
	}
	for (int i = x; i < x + w; i++)
	{
		b[y+h-1][i] = '*';
	}
	for (int i = y+2; i < y + h; i++)
	{
		b[i][x+w-1] = '*';
	}

	if (n == 1)
	{
		return;
	}
	b[y + 2][x + w - 2] = '*';

	func(x + 2, y + 2, n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << '*';
		return 0;
	}

	int w = 4 * n - 3;
	int h = 4 * n - 1;
		
	func(0, 0, n);
	
	for (int i = 0; i < h; i++)
	{
		while (b[i].back() == ' ')
			b[i].pop_back();
		cout << b[i];
		cout << '\n';
	}


	return 0;
}