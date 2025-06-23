#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

struct point
{
	ll x, y;

	bool operator>(point p)
	{
		if (x == p.x)
		{
			return y > p.y;
		}
		return x > p.x;
	}

	bool operator>=(point p)
	{
		if (x == p.x)
		{
			return y >= p.y;
		}
		return x >= p.x;
	}
};

int ccw(point p1, point p2, point p3)
{
	//2차원 외적은 z만 계산
	//vec1 = p2-p1;
	//vec2 = p3-p2;
	//vec1.x * vec2.y - vec1.y * vec2.x
	//(p2.x-p1.x) * (p3.y-p2.y) - (p2.y -p1.y) * (p3.x - p2.x);
	// p2x *p3y  -p1x*p3y + p1x*p2y - p2y*p3x  +p1y*p3x - p1y*p2x
	//(p1x*p2y + p2x*p3y + p3x*p1y) - (p1x*p3y + p2x*p1y + p3x*p2y)
	ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - (p1.x * p3.y + p2.x * p1.y + p3.x * p2.y);
	if (res < 0)
	{
		return -1;
	}
	else if (res == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool isCross(vector<point> p)
{
	int res1 = ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]);
	int res2 = ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]);
	if (res1 == 0 && res2 == 0)
	{
		if (p[0] > p[1]) swap(p[0], p[1]);
		if (p[2] > p[3]) swap(p[2], p[3]);

		return p[1] >= p[2] && p[3] >= p[0];
	}

	return res1 <= 0 && res2 <= 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<point> p(4);
	for (int i = 0; i < 4; i++)
	{
		ll x, y;
		cin >> p[i].x >> p[i].y;
	}

	cout << isCross(p);

	return 0;
}