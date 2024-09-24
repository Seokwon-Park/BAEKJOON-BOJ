#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c;
	cin >> n >> c;
	int a = n; // 세로
	int b = n; // 가로
	for (int i = 0; i < c; i++)
	{
		int x, y; // 세로, 가로
		cin >> x >> y;
		if (x >= a || y >= b) continue;
		int cutVert= a * y;
		int cutHori = b * x;
		if (cutVert <= cutHori)
		{
			a = x;
		}
		else if (cutVert > cutHori)
		{
			b = y;
		}
	}
	cout << a * b;

	return 0;
}

