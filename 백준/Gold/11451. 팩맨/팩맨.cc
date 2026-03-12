
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, m;
int b[55][55];
int v[55][55][55][55];
int prevdir[55][55][55][55];
tuple<int, int, int, int> pre[55][55][55][55];
int ex, ey;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
string dir = "WNES";

pii validate(int r, int c, int prevr, int prevc) // 벽 또는 맵밖으로 나갔을때 유효한 좌표로 이동시킨다.
{
	if (r < 0)
	{
		r = n - 1;
	}
	else if (r >= n)
	{
		r = 0;
	}
	else if (c < 0)
	{
		c = m - 1;
	}
	else if (c >= m)
	{
		c = 0;
	}
	//맵밖으로 나갔는데 반대편이 벽일수도 있으니까 마지막에
	if (b[r][c] == 1)
	{
		r = prevr;
		c = prevc;
	}
	return { r,c };
}

bool checkGhost(int r1, int c1, int r2, int c2)
{
	return b[r1][c1] == 2 || b[r2][c2] == 2;
}

bool bfs(vector<pii> st)
{
	auto [x1, y1] = st[0];
	auto [x2, y2] = st[1];
	queue<tuple<int, int, int, int>> q;
	q.push({ x1,y1,x2,y2 });
	prevdir[x1][y1][x2][y2] = -1;
	v[x1][y1][x2][y2] = 1;
	while (!q.empty())
	{
		auto [c1, r1, c2, r2] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tc1 = c1 + dx[i];
			int tr1 = r1 + dy[i];
			int tc2 = c2 + dx[i];
			int tr2 = r2 + dy[i];
			tie(tr1, tc1) = validate(tr1, tc1, r1, c1);
			tie(tr2, tc2) = validate(tr2, tc2, r2, c2);
			if (checkGhost(tr1, tc1, tr2, tc2) || v[tc1][tr1][tc2][tr2]) continue; // 귀신이 있거나 이미 방문한 조합이면 안돼
			prevdir[tc1][tr1][tc2][tr2] = i;
			pre[tc1][tr1][tc2][tr2] = { c1, r1, c2, r2 };
			if (tr1 == tr2 && tc1 == tc2)
			{
				ex = tc1;
				ey = tr1;
				return true;
			}
			q.push({ tc1,tr1,tc2,tr2 });
			v[tc1][tr1][tc2][tr2] = 1;
			
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		memset(v, 0, sizeof(v));
		cin >> n >> m;
		vector<pii> st;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char ch;
				cin >> ch;
				switch (ch)
				{
				case '.':
					b[i][j] = 0;
					break;
				case 'X':
					b[i][j] = 1;
					break;
				case 'G':
					b[i][j] = 2;
					break;
				case 'P':
					b[i][j] = 0;
					st.push_back({ j,i });
					break;
				default:
					break;
				}
			}
		}
		bool isPossible = bfs(st);
		if (isPossible)
		{
			int x1 = ex;
			int y1 = ey;
			int x2 = ex;
			int y2 = ey;
			string route;
			while (prevdir[x1][y1][x2][y2] != -1)
			{
				int k = prevdir[x1][y1][x2][y2];
				route.push_back(dir[k]);
				tie(x1, y1, x2, y2) = pre[x1][y1][x2][y2];
			}
			reverse(route.begin(), route.end());
			cout << route.size() << ' ' << route << '\n';
		}
		else
		{
			cout << "IMPOSSIBLE\n";
		}
		

	}

	return 0;
}