#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int n, m;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
char b[20][20];
char v[20][20][20][20];

bool isout(int x, int y)
{
	return x < 0 || y < 0 || x >= m || y >= n;
}

bool iswall(int x, int y)
{
	return b[y][x] == '#';
}



int bfs(vector<int> st)
{
	queue<tuple<int, int, int, int>> q;
	q.push({st[0],st[1],st[2],st[3]});
	v[st[0]][st[1]][st[2]][st[3]] = 1;
	int d = 1;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x1, y1, x2, y2] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) // simul
			{
				int tx1 = x1 + dx[j];
				int ty1 = y1 + dy[j];
				bool isout1 = isout(tx1, ty1);

				int tx2 = x2 + dx[j];
				int ty2 = y2 + dy[j];
				bool isout2 = isout(tx2, ty2);

				if (isout1 && isout2) continue; // 둘다 나갔으면 다른경우
				if (isout1 || isout2) return d; // 하나가 나갔으면 누른 횟수 리턴
				if (iswall(tx1, ty1)) // 벽인경우 다음 위치를 재정의함
				{
					tx1 = x1;
					ty1 = y1;
				}
				if (iswall(tx2, ty2)) // 벽인경우 다음 위치를 재정의함
				{
					tx2 = x2;
					ty2 = y2;
				}

				if ((tx1 == tx2 && ty1 == ty2) || v[tx1][ty1][tx2][ty2]) continue; //둘이 겹치거나 이미 가본 경우
				q.push({ tx1,ty1,tx2,ty2 });
				v[tx1][ty1][tx2][ty2] = 1;
			}
		}
		d++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	vector<int> st;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == 'o')
			{
				st.push_back(j);
				st.push_back(i);
			}
			else
			{
				b[i][j] = c;
			}
		}
	}

	cout << bfs(st);




	return 0;
}