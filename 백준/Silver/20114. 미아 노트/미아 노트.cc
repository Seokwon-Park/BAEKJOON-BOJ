#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

char b[105][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, h, w;
	cin >> n >> h >> w;
	
	string ans; 
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n*w; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n*w; i+=w)
	{
		char ch = '?';
		for (int r = 0; r < h; r++)
		{
			for (int c = 0; c < w; c++)
			{
				if (b[r][i + c] != '?')
					ch = b[r][i + c];
			}
		}
		ans += ch;
	}
	cout << ans;

	return 0;
}