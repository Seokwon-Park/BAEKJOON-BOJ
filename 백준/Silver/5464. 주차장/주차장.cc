#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int n, m;
int cost[105];
int carw[2005];
int loc[2005]; // i번 차가 주차된 위치;
bool isParked[105]; // 해당 자리 주차된상태인지

int checkEmpty()
{
	for (int i = 0; i < n; i++)
	{
		if (!isParked[i])
			return i;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> carw[i];
	}

	int ans = 0;
	queue<int> q;
	for (int i = 0; i < 2 * m; i++)
	{
		int input;
		cin >> input;
		if (input > 0)
		{
			int ix = checkEmpty();
			if (ix == -1)
			{
				q.push(input);
			}
			else
			{
				isParked[ix] = true;
				ans += cost[ix] * carw[input];
				loc[input] = ix;
			}
		}
		else
		{
			int tmp = -input;
			isParked[loc[tmp]] = false;
			if (!q.empty())
			{
				int x = q.front();
				q.pop();
				isParked[loc[tmp]] = true;
				ans += cost[loc[tmp]] * carw[x];
				loc[x] = loc[tmp];

			}
		}
	}
	cout << ans;

	return 0;
}
