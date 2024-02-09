#include <bits/stdc++.h>

using namespace std;

int n, m, h;

int ladder[15][35]; // 
int vert;
int ans = INT_MAX;
vector<pair<int, int>> canput;

bool simul()
{
	for (int i = 1; i <= n; i++)
	{
		int cur = i;
		for (int j = 1; j <= h; j++)
		{
			if (ladder[cur][j] != 0)
			{
				cur += ladder[cur][j];
			}
		}
		if (cur != i) return false;
	}
	return true;
}

void func(int n)
{
	if (vert > 3) return; // 3보다 더 추가해야 하면 리턴시킨다.
	if (n == canput.size())
	{
		if (simul())
			ans = min(ans, vert);
		return;
	}
	auto [i, j] = canput[n];
	if (ladder[i][j] == 0 && ladder[i + 1][j] == 0) // 사다리를 놓을 수 있는 경우이면
	{
		ladder[i][j] = 1;
		ladder[i + 1][j] = -1;
		vert++;
		func(n + 1);
		vert--;
		ladder[i][j] = 0;
		ladder[i + 1][j] = 0;
	}
	// 사다리를 안놓는 경우.
	func(n + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> h;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder[b][a] = 1;
		ladder[b + 1][a] = -1;
	}

	for (int j = 1; j <= h; j++)
		for (int i = 1; i < n; i++)
		{
			if (ladder[i][j] == 0 && ladder[i + 1][j] == 0)
				canput.push_back({ i,j }); // line, height
		}

	func(0);

	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans;

	return 0;
}
