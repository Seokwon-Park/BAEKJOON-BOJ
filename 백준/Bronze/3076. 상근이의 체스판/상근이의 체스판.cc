#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int nxt[256];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c;
	int a, b;
	cin >> r >> c >> a >> b;

	nxt['X'] = '.';
	nxt['.'] = 'X';


	char ch = 'X';
	for (int i = 0; i < r; i++)
	{
		for (int y = 0; y < a; y++)
		{
			if (i % 2)ch = '.';
			else ch = 'X';
			for (int j = 0; j < c; j++)
			{
				for (int x = 0; x < b; x++)
				{
					cout << ch;
				}
				ch = nxt[ch];
			}
			cout << '\n';
		}
	}

	return 0;
}