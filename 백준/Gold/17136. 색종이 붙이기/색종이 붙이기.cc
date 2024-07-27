#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[10][10];
bool isUsed[10][10];
vector<int> paper(6, 5);
int n;
int ans = INF;
int usedPaper;

bool tryToPaste(int x, int y, int sz)
{
	for (int r = 0; r < sz; r++)
	{
		for (int c = 0; c < sz; c++)
		{
			if (b[y + r][x + c] == 0 || isUsed[y + r][x + c]) return false;
		}
	}


	return true;
}

void func(int startToSearch, int k)
{
	if (ans < usedPaper)return;
	if (k == n)
	{
		ans = min(ans, usedPaper);
		return;
	}
	for (int x = startToSearch; x < 100; x++)
	{
		int i = x / 10;
		int j = x % 10;
		if (b[i][j] == 1 && !isUsed[i][j])
		{
			for (int sz = 5; sz >= 1; sz--)
			{
				if (paper[sz] <= 0 || i + sz > 10 || j + sz > 10) continue;
				if (tryToPaste(j, i, sz))
				{
					usedPaper++;
					paper[sz]--;
					for (int r = 0; r < sz; r++)
					{
						for (int c = 0; c < sz; c++)
						{
							isUsed[i + r][j + c] = true;
						}
					}
					func(x+1, k + sz * sz);
					usedPaper--;
					paper[sz]++;
					for (int r = 0; r < sz; r++)
					{
						for (int c = 0; c < sz; c++)
						{
							isUsed[i + r][j + c] = false;
						}
					}
				}
			}
			return; // 여기를 안써서 시간 초과남. 일단 붙일 곳을 찾았다면 더이상 이 재귀에서는 2중 for문을 탐색하면 안된다.
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> b[i][j];
			n += b[i][j];
		}
	}

	func(0, 0);

	cout << (ans == INF? -1 : ans);

	return 0;
}