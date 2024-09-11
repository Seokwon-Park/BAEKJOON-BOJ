#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int a, b, c, d;
map<int, map<int, bool>> v;

//fill a, b / empty a, b / m a=>b b=>a
int bfs()
{
	queue<pii> q;
	q.push({ 0,0 });
	v[0][0] = true;
	int res = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [cura, curb] = q.front();
			if (cura == c && curb == d)
			{
				return res;
			}
			q.pop();
			//fill
			//fill A
			if (!v[a][curb])
			{
				q.push({ a,curb });
				v[a][curb] = true;
			}
			if (!v[cura][b])
			{
				q.push({ cura,b });
				v[cura][b] = true;
			}

			//Empty
			//Empty A
			if (!v[0][curb])
			{
				q.push({ 0,curb });
				v[0][curb] = true;
			}
			if (!v[cura][0])
			{
				q.push({ cura,0 });
				v[cura][0] = true;
			}

			//Move AtoB
			int tb;
			int ta;
			if (curb + cura > b)
			{
				tb = b;
				ta = curb + cura - b;
			}
			else
			{
				tb = cura + curb;
				ta = 0;
			}
			if (!v[ta][tb])
			{
				q.push({ ta,tb });
				v[ta][tb] = true;
			}
			//Move BtoA
			if (cura + curb > a)
			{
				ta = a;
				tb = curb + cura - a;
			}
			else
			{
				ta = cura + curb;
				tb = 0;
			}
			if (!v[ta][tb])
			{
				q.push({ ta,tb });
				v[ta][tb] = true;
			}
		}
		res++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b >> c >> d;

	cout << bfs();

	return 0;
}

