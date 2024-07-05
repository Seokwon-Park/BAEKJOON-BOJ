#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

// RPS 0, 1, 2
int score[55][3];
// score[i][j] : i번째 라운드에서 j(가위 바위 보) 중에서 하나를 냈을때 얻을 수 있는 점수량

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r;
	cin >> r;
	string sk;
	cin >> sk;
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		for (int j = 0; j < r; j++)
		{
			if (v[i][j] == 'R')
			{
				score[j][0] += 1;
				score[j][1] += 2;
			}
			if (v[i][j] == 'P')
			{
				score[j][1] += 1;
				score[j][2] += 2;
			}
			if (v[i][j] == 'S')
			{
				score[j][2] += 1;
				score[j][0] += 2;
			}
		}
	}

	int ans = 0;
	int mx = 0;
	for (int i = 0; i<r ;i++)
	{
		mx += *max_element(score[i], score[i] + 3);
		if (sk[i] == 'R')
		{
			ans += score[i][0];
		}
		else if (sk[i] == 'P')
		{
			ans += score[i][1];
		}
		else if (sk[i] == 'S')
		{
			ans += score[i][2];
		}
	}
	cout << ans << '\n' << mx;


	return 0;
}