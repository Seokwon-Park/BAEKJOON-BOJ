#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n;
char b[6][6];
char bcp[6][6];
bool canSee[6][6];
vector<pii> tpos;
vector<pii> spos;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void reset()
{
	for (int i = 0; i < 6; i++)
	{
		fill(canSee[i], canSee[i] + 6, false);
	}
}

int check() // 현재 상태에서 선생님에게 들킨 학생의 수
{
	reset();
	for (int i = 0; i < tpos.size(); i++)
	{
		auto [x, y] = tpos[i];
		for (int j = 0; j < 4; j++)
		{
			int tx = x + dx[j];
			int ty = y + dy[j];
			while (tx >= 0 && ty >= 0 && tx < n && ty < n && bcp[ty][tx] != 'O')
			{
				canSee[ty][tx] = true;
				tx += dx[j];
				ty += dy[j];
			}
		}
	}

	int st = 0;
	for (int i = 0; i < spos.size(); i++)
	{
		auto [x, y] = spos[i];
		if (canSee[y][x])
			st++;
	}

	return st;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	// 가능한 좌표중에 3개를 뽑는 조합만들기
	vector<int> pick(n * n, 0); 
	fill(pick.end() - 3, pick.end(), 1);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'T')
			{
				tpos.push_back({ j,i });
			}
			if (b[i][j] == 'S')
			{
				spos.push_back({ j,i });
			}
		}
	}
	
	bool flag = false;
	do
	{
		// 장애물 놓기 위한 용도로 copy
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				bcp[i][j] = b[i][j];
			}
		}

		for (int i = 0; i < n*n; i++)
		{
			if (pick[i]) // 선택된 위치 발견시 장애물 설치함
			{
				int x = i % n;
				int y = i / n;
				if (bcp[y][x] != 'X')break;
				bcp[y][x] = 'O';
			}
		}
		int res = check();
		if (res == 0)
		{
			//for (int i = 0; i < n; i++)
			//{
			//	for (int j = 0; j < n; j++)
			//	{
			//		cout << bcp[i][j] << ' ';
			//	}
			//	cout << '\n';
			//}

			flag = true;
			break;
		}
	} while (next_permutation(pick.begin(), pick.end()));

	if (flag)
		cout << "YES";
	else
		cout << "NO";



	return 0;
}
