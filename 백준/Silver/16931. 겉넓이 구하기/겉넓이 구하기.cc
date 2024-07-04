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
int b[105][105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for(int j = 1; j<=m ;j++)
		{
			cin >> b[i][j];
		}
	}

	int ans = m * n * 2; // 밑바닥이랑 위에서 봤을때는 어차피 n*m이다.


	// 어떤 좌표에 쌓인 정육면체에 대해
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < 4; k++) 
			{
				int tx = j + dx[k];
				int ty = i + dy[k];

				if (b[i][j] >= b[ty][tx])// 주변높이가 자기 높이보다 낮으면 상하좌우 만약 외곽일경우 0과 비교됨.
					ans += b[i][j] - b[ty][tx]; // 높이 차이만큼 옆면이 보여지게 된다.
			}
		}
	}

	cout << ans;


	return 0;
}
