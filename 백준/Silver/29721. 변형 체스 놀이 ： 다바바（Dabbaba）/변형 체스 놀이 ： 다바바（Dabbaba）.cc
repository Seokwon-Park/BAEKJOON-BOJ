#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	set<pii> s;
	set<pii> stpoint;
	vector<pii> v;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
		stpoint.insert({ x,y });
	}
	for (int i = 0; i < k; i++)
	{
		auto [x, y] = v[i];
		//s.insert(make_pair(x, y));
		for (int j = 0; j < 4; j++)
		{
			int tx = x + dx[j] * 2;
			int ty = y + dy[j] * 2;
			if (tx <= 0 || ty <=0 || tx > n || ty>n)continue;
			if(stpoint.find(make_pair(tx,ty)) == stpoint.end())
				s.insert({ tx, ty });
		}
	}

	cout << s.size();

	return 0;
}