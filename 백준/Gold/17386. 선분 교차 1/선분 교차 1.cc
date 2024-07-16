#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int ccw(vector<ll> v1, vector<ll> v2)
{
	ll z = v1[0] * v2[1] - v2[0] * v1[1];
	if (z == 0)
		return 0;
	else if (z < 0)
		return -1;
	else
		return 1;

}

int ccw(vector<ll> p1, vector<ll> p2, vector<ll> p3)
{
	ll vx1 = p2[0] - p1[0];
	ll vy1 = p2[1] - p1[1];
	ll vx2 = p3[0] - p2[0];
	ll vy2 = p3[1] - p2[1];

	return ccw({ vx1,vy1 }, { vx2, vy2 });
}

bool intersect(vector<ll> p1, vector<ll> p2, vector<ll> p3, vector<ll> p4)
{
	ll res1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	ll res2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (res1 == 0 && res2 == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);
		return p3 <= p2 && p1 <= p4;
	}
	return res1 <= 0 && res2 <= 0;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<ll> xy[4];
	for (int i = 0; i < 4; i++)
	{
		int x, y;
		cin >> x >> y;
		xy[i].push_back(x);
		xy[i].push_back(y);
	}

	cout << intersect(xy[0], xy[1], xy[2], xy[3]);

	return 0;
}