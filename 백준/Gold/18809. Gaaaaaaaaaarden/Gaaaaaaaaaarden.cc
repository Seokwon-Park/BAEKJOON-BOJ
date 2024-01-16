#include <bits/stdc++.h>

using namespace std;

int graph[55][55];
int gcopy[55][55];
int n, m, g, r;
int max_f = INT_MIN;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> g >> r;
	vector<int> ground;
	// 씨앗을 심을 수 있는 땅의 위치를 저장한다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 2)
			{
				ground.push_back(i * m + j);
			}
		}
	}

	// 이건 심을 수 있는 땅 중에서 red 개 + green개 만큼 조합을 뽑는다.
	vector<int> seed(ground.size() - g - r, 0);
	seed.insert(seed.end(), g, 3);
	seed.insert(seed.end(), r, 4);

	do {
		vector<vector<int>> dist(n, vector<int>(m, 0));
		queue<pair<int, int>> q;
		int flower = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				gcopy[i][j] = graph[i][j];
			}
		}

		for (int i = 0; i < seed.size(); i++)
		{
			if (seed[i] != 0)
			{
				int x = ground[i] % m;
				int y = ground[i] / m;
				gcopy[y][x] = seed[i];
				q.push({ x,y });
			}
		}
		// red 3 green 4 flower 5
		while (!q.empty())
		{
			auto [x, y] = q.front(); 
			q.pop();
			if (gcopy[y][x] == 5) continue; 
			// 이 경우는 만약 green이 이 위치에 배양하고 지나갔는데
			//  red가 같은 시간에 도착해서 꽃을 피운 경우 
			// 이미 green은 q에 들어가 있는 상태이므로 
			// q에서 꺼냈을때 꽃이 핀 상태라면 더이상 진행하지 못하도록 한다.
			for (int i = 0; i < 4; i++)
			{
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
				if(gcopy[ty][tx] == 0 || gcopy[ty][tx] == 5) continue; // 꽃이 피었거나 호수면 더이상 진행하지 않는다.
				if (gcopy[ty][tx] == 1 || gcopy[ty][tx] == 2) // 다음 위치가 전파 될 수 있는 땅이면(2 이면 씨앗을 안심었다는 소리)
				{
					gcopy[ty][tx] = gcopy[y][x]; //전파시킨다.
					dist[ty][tx] = dist[y][x] + 1; 
					q.push({ tx,ty });
				}
				else // 아닌경우
				{

					if (gcopy[y][x] == gcopy[ty][tx]) continue;
					// 0,1,2,5 걸렀다 3이나 4에 대해서 처리해준다. 그러면 다른 배양액이 이미 도달한 위치에 대해서
					// 내 배양액의 종류가 다르고(if) 도달할 시간이 이녀석과 같으면 꽃을 피운다.
					// 더 늦은 경우에는 진행할 수 없음, 더 빨리 도착했으면 BFS특성상 이 분기에 진입할 수 없다.
					if (dist[y][x] + 1 == dist[ty][tx])
					{
						gcopy[ty][tx] = 5;
						flower++;
					}
					continue;
				}
			}
		}
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << gcopy[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
		//cout << flower;
		//cout << '\n';

		max_f = max(max_f, flower);
	} while (next_permutation(seed.begin(), seed.end()));

	cout << max_f;

	return 0;
}