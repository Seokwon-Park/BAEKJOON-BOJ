#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

vector<int> hasUpdate[10005]; // 가격업데이트가 있는 로봇의 목록

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	double a;
	cin >> n >> a >> t;
	vector<double> percent(n);
	for (int i = 0; i < n; i++)
	{
		int s, itv;
		cin >> s >> itv >> percent[i];
		hasUpdate[s].push_back(i);
		int tmp = s;
		while (tmp + itv < t) // 업데이트 일정을 미리 넣어놓는다.
		{
			tmp += itv;
			hasUpdate[tmp].push_back(i);
		}
	}
	vector<double> price(n, 0.0);

	for (int d = 0; d < t; d++)
	{
		if (!hasUpdate[d].empty()) // 업데이트 하는 날인경우
		{
			vector<pii> update;
			for (int i : hasUpdate[d])
			{
				// i번 로봇의 값을 업데이트 하기 위해 평균 계산
				double sum = 0.0;
				int cnt = 0;
				for (int j = 0; j < n; j++)
				{
					if (price[j] == 0.0) continue;
					sum += price[j];
					cnt++;
				}
				if (cnt == 0)
				{
					update.push_back({ i,static_cast<int>((a + 0.005) * 100.0) });
				}
				else
				{
					update.push_back({ i, static_cast<int>(((sum / cnt) * (1.0 + percent[i]) + 0.005) * 100.0) });
				}
			}
			for (auto [ix, db] : update)
			{
				price[ix] = db / 100.0;
			}
			int breakpoint = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << fixed << setprecision(2) << price[i] << '\n';
	}

	return 0;
}

