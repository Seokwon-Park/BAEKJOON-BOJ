#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using hashmap = unordered_map<key, value>;

char c[10][10];

int dx[4] = { 1, 1, 1, 0 };
int dy[4] = { -1, 0, 1, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> c[i][j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = 0;
				int o = 0;
				bool isValid = true;
				for (int l = 0; l < 5; l++)
				{
					int tx = j + dx[k] * l;
					int ty = i + dy[k] * l;
					if (tx < 0 || ty < 0 || tx >= 10 || ty >= 10)
					{
						isValid = false;
						break;
					}
					if (c[ty][tx] == 'X') x++;
					else if (c[ty][tx] == 'O') o++;
				}
				if (isValid)
				{
					if (o == 0 && x == 4)
					{
						cout << 1;
						return 0;
					}
				}
			}
		}
	}
	cout << 0;


	return 0;
}