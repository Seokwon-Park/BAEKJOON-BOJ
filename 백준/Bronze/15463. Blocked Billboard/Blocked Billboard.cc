#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

bool b[2005][2005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x1, y1, p1, q1;
	cin >> x1 >> y1 >> p1 >> q1;
	int x2, y2, p2, q2;
	cin >> x2 >> y2 >> p2 >> q2;
	int x3, y3, p3, q3;
	cin >> x3 >> y3 >> p3 >> q3;

	int total = 0;

	for (int i = x1 + 1000; i < p1 + 1000; i++)
	{
		for (int j = y1 + 1000; j < q1 + 1000; j++)
		{
			total++;
			b[i][j] = true;
		}
	}

	for (int i = x2 + 1000; i < p2 + 1000; i++)
	{
		for (int j = y2 + 1000; j < q2 + 1000; j++)
		{
			if (!b[i][j])
			{
				total++;
				b[i][j] = true;
			}
		}
	}

	for (int i = x3 + 1000; i < p3 + 1000; i++)
	{
		for (int j = y3 + 1000; j < q3 + 1000; j++)
		{
			if (b[i][j])
			{
				total--;
			}
		}
	}


	cout << total;

	return 0;
}