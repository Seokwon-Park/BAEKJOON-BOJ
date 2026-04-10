#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int p[9];
bool q[9];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		cin >> q[i] >> p[i];
	}

	int ans = -1;
	for (int i = 0; i < 9; i++)
	{
		q[i] = !q[i];
		vector<int> chk(10, -1);
		bool irony = false;
		for (int j = 0; j < 9; j++)
		{
			if (chk[p[j]] == -1)
			{
				chk[p[j]] = q[j];
			}
			else if (chk[p[j]] != q[j]) // 모순되는 주장이 있으면
			{
				irony = true;
				break;
			}
		}
		q[i] = !q[i];
		if (irony) continue;
		int a = count(chk.begin() + 1, chk.end(), 1);
		int b = count(chk.begin() + 1, chk.end(), 0);
		int c = count(chk.begin() + 1, chk.end(), -1);
		if (a > 1) // 1루수가 1명보다 많으면
		{
			irony = true; // 모순
		}
		else if (a == 0) //1루수가 없어?
		{
			if (c == 0)// 1루수인지 아닌지 결정되지 않은 사람도 없음
			{
				irony = true;// 1루수가 반드시 한명 있어야 한다는 규칙에 모순
			}
			else if (c == 1) // 위의 주장들을 종합했을 때 
				//1루수가 없는데 결정되지 않은 사람이 한명이면 걔가 1루수야
			{
				for (int j = 1; j <= 9; j++)
				{
					if (chk[j] == -1)
					{
						chk[j] = 1;
					}
				}
			}
			else if (c > 1)// 주장에는 모순도 없는데 결정되지 않은 사람이 2명 이상이면
			{
				cout << -1; // 이 시나리오 때문에 결정이 불가능
				return 0;
			}
		}

		if (!irony)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (chk[j] == 1)
				{
					if (ans == -1)
					{
						ans = j;
						break;
					}
					else if (ans != j)
					{
						cout << -1;
						return 0;

					}
				}
			}
		}


	}

	cout << ans;
	return 0;
}