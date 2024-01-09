#include <bits/stdc++.h>

using namespace std;

int board[505][505];
int n, m;
int max_val = INT_MIN;
vector<pair<bool, bool>> rotflip;
vector<vector<vector<int>>> tetromino; 
vector<vector<int>> I =
{
	{1,1,1,1}
};
vector<vector<int>> O =
{
	{1, 1},
	{1, 1}
};
vector<vector<int>> L =
{
	{1,0},
	{1,0},
	{1,1} };
vector<vector<int>> S =
{
	{1,0},
	{1,1},
	{0,1}
};
vector<vector<int>> T =
{
	{1,1,1},
	{0,1,0},
};

void chk(vector<vector<int>>& block)
{
	int h, w;
	h = block.size();
	w = block[0].size();
	for (int i = 0; i < n - h + 1; i++)
	{
		for (int j = 0; j < m - w + 1; j++)
		{
			int val = 0;
			for (int y = 0; y < h; y++)
			{
				for (int x = 0; x < w; x++)
				{
					if (block[y][x] == 1)
					{
						val += board[i + y][j + x];
					}
				}
			}
			max_val = max(max_val, val);
		}
	}
}

vector<vector<int>>& rotate(vector<vector<int>>& block)
{
	int h, w;
	h = block.size();
	w = block[0].size();
	vector<vector<int>> new_block(w, vector<int>(h, 0));

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			new_block[j][h - i - 1] = block[i][j];
		}
	}
	block = new_block;
	return block;
}

vector<vector<int>>& flip(vector<vector<int>>& block)
{
	int h, w;
	h = block.size();
	w = block[0].size();
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w/2; j++)
		{
			swap(block[i][j], block[i][w - j - 1]);
		}
	}
	return block;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	tetromino.push_back(I);
	tetromino.push_back(O);
	tetromino.push_back(L);
	tetromino.push_back(S);
	tetromino.push_back(T);
	rotflip.push_back({ true, false });
	rotflip.push_back({ false, false });
	rotflip.push_back({ true, true});
	rotflip.push_back({ true, true });
	rotflip.push_back({ true, false });

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (rotflip[i].first) // 회전 하면 다른모양 나옴?
		{
			if (rotflip[i].second) // 플립 하면 다른모양나옴?
			{
				for (int j = 0; j < 2; j++)// 플립
				{
					flip(tetromino[i]);
					for (int k = 0; k < 4; k++) // 플립 후 회전 4번
					{
						rotate(tetromino[i]);
						chk(tetromino[i]);
					}
				}
			}
			else
			{
				for (int k = 0; k < 4; k++) //걍 회전 4번
				{
					rotate(tetromino[i]);
					chk(tetromino[i]);
				}
			}
		}
		else
		{
			chk(tetromino[i]);
		}
	}
	cout << max_val;

	return 0;
}