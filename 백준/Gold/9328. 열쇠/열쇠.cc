#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

char board[105][105];
bool visited[105][105];
int h, w;
bool hasKey[26];
bool isOpen[105][105];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int doc;
int ans;

void resetv()
{
	for (int i = 0; i < h; i++)
	{
		fill(visited[i], visited[i] + w, false);
	}
}
vector<pair<int, int>> find_in()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (isOpen[i][j]) continue;
			if (board[i][j] >= 'A' && board[i][j] <= 'Z') // 만약 테두리가 문일 경우
			{
				if (hasKey[board[i][j] - 'A'])
					isOpen[i][j] = true;
			}
		}
	}
	vector<pair<int, int>> in;
	for (int i = 0; i < h; i++)
	{
		if (isOpen[i][0])
			in.push_back({ 0, i });
		if (isOpen[i][w - 1])
			in.push_back({ w - 1, i });
		if (board[i][0] >= 'a' && board[i][0] <= 'z') // 테두리 열쇠 처리
			hasKey[board[i][0] - 'a'] = true;
		if (board[i][w-1] >= 'a' && board[i][w-1] <= 'z') // 테두리 열쇠 처리
			hasKey[board[i][w - 1] - 'a'] = true;
	}
	for (int i = 0; i < w; i++)
	{
		if (isOpen[0][i])
			in.push_back({ i, 0 });
		if (isOpen[h - 1][i])
			in.push_back({ i, h - 1 });
		if (board[0][i] >= 'a' && board[0][i] <= 'z') // 테두리 열쇠 처리
			hasKey[board[0][i] - 'a'] = true;
		if (board[h-1][i] >= 'a' && board[h-1][i] <= 'z') // 테두리 열쇠 처리
			hasKey[board[h-1][i] - 'a'] = true;
	}
	return in;
}

int bfs()
{
	resetv();
	doc = 0;
	auto coords = find_in();
	queue<pair<int, int>> q;
	int area = 0; // 총 탐색한 구역의 수.
	for (auto [x, y] : coords)
	{
		if (visited[y][x]) continue;
		q.push({ x, y });
		visited[y][x] = true;
		if (board[y][x] == '$')
			doc++;
		area++;
	}
	while (!q.empty())
	{
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (tx < 0 || ty < 0 || tx >= w || ty >= h) continue;
			if (visited[ty][tx] || board[ty][tx] == '*') continue;
			if (board[ty][tx] >= 'A' && board[ty][tx] <= 'Z') // 만약 다음 지역이 문이라면?
			{
				if (!isOpen[ty][tx]) // 문이 닫혀있을때
				{
					if (hasKey[board[ty][tx] - 'A']) // 열쇠가 있음
					{
						isOpen[ty][tx] = true; // 열어 
					}
					else // 못열면 더 못감.
					{
						continue;
					}
				}
			}
			else if (board[ty][tx] >= 'a' && board[ty][tx] <= 'z') // 열쇠가 있는 방이면?
			{
				hasKey[board[ty][tx] - 'a'] = true; // 열쇠 습득하기
			}
			else if (board[ty][tx] == '$') // 서류가 있는 칸이면 서류 줍기
			{
				doc++;
			}

			q.push({ tx,ty });
			area++;
			visited[ty][tx] = true;
		}
	}
	//for (int i = 0; i < h; i++)
	//{
	//	for (int j = 0; j < w; j++)
	//	{
	//		cout << visited[i][j];
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';


	ans = max(ans, doc);

	return area;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		ans = INT_MIN;
		for (int i = 0; i < h; i++)
		{
			fill(isOpen[i], isOpen[i] + w, false);
		}
		fill(hasKey, hasKey+26, false);

		cin >> h >> w;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '.')
					isOpen[i][j] = true;
				if (board[i][j] >= 'a' && board[i][j] <= 'z')
					isOpen[i][j] = true;
			}
		}

		string str;
		cin >> str;
		if (str != "0")
			for (char c : str)
			{
				hasKey[c - 'a'] = true;
			}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (board[i][j] >= 'A' && board[i][j] <= 'Z') // 만약 테두리가 문일 경우
				{
					if (hasKey[board[i][j] - 'A'])
						isOpen[i][j] = true;
				}
				if (board[i][j] == '$') // 만약 테두리가 문일 경우
				{

					isOpen[i][j] = true;
				}
			}
		}

		int prev = 0;
		int res = bfs();
		while (prev != res) // 이전하고 탐색한 지역의 수에 변화가 없으면 더이상 열 수 있는 문이 없다는 뜻이겠죠??
		{
			prev = res;
			res = bfs();
		}
		cout << ans << '\n';
	}

	return 0;
}