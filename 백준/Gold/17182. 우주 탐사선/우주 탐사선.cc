#include <bits/stdc++.h>

using namespace std;

int d[15][15];
bool is_explore[15];
int n, k;
int t; // 걸린 시간
int cnt = 0; // 탐색한 행성 수 (처음에 위치하는 행성 +1)
int min_val = INT_MAX;


void func(int planet) // 현재 위치한 행성
{
	if (cnt == n) // 모든행성 탐색함?
	{
		min_val = min(min_val, t); // 최소시간일시 갱신
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!is_explore[i]) // 탐색안한 행성에 대해서만
		{
			is_explore[i] = true;
			t += d[planet][i]; // 현재 위치에서 다음 행성으로 가는데 걸리는 시간.
			cnt++;
			func(i); // 다음행성 ㄱ
			cnt--;
			t -= d[planet][i]; 
			is_explore[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> d[i][j];
		}
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}

	func(k);
	cout << min_val;

	return 0;
}