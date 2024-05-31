#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int scv[3];
int dx[6][3];
bool v[61][61][61];
int dist[61][61][61];

int func()
{
	queue<vector<int>> q;
	q.push({ scv[0], scv[1], scv[2] });
	v[scv[0]][scv[1]][scv[2]] = true;
	dist[scv[0]][scv[1]][scv[2]] = 0;

	while (!q.empty())
	{
		int a = q.front()[0];
		int b = q.front()[1];
		int c = q.front()[2];
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int ta = max(0, a - dx[i][0]);
			int tb = max(0, b - dx[i][1]);
			int tc = max(0, c - dx[i][2]);
			if (v[ta][tb][tc]) continue;
			dist[ta][tb][tc] = dist[a][b][c] + 1;
			if (ta == 0 && tb == 0 && tc == 0)
			{
				return dist[ta][tb][tc];
			}
			v[ta][tb][tc] = true;
			q.push({ ta,tb,tc });
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> scv[i];
	}

	vector<int> v = { 1,3,9 };

	int ix = 0;
	do
	{
		for (int i = 0; i < 3; i++)
		{
			dx[ix][i] = v[i];
		}
		ix++;
	} while (next_permutation(v.begin(), v.end()));

	cout << func();



	return 0;
}