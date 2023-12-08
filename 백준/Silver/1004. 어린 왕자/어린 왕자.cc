#include <bits/stdc++.h>

using namespace std;

// 출발점과 도착점이 원내부에 있을 경우 나가야 되는 횟수를 추가해준다.
// (x-a)^2 + (y-b)^2 < r^2
bool IsInsideCircle(int x, int y, int a, int b, int r)
{
	int x2 = (x - a) * (x - a);
	int y2 = (y - b) * (y - b);
	int r2 = r*r;

	return x2 + y2 < r2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x1, y1, x2, y2, cx, cy, r;
	int tc, n;

	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> cx >> cy >> r;
			
			bool res1 = IsInsideCircle(x1, y1, cx, cy, r);
			bool res2 = IsInsideCircle(x2, y2, cx, cy, r);
			// 같은 원 내부에 있지 않을때만 count 증가
			if (res1 != res2) cnt++;


		}
		cout << cnt << '\n';
	}

	return 0;
}