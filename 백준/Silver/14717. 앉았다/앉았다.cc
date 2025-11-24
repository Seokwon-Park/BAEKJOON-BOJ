#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	int d = 0;
	int g = 0;

	if (a == b)
	{
		d = a;
	}
	else
	{
		g = (a + b) % 10;
	}

	vector<int> cards(11, 2);
	cards[a]--;
	cards[b]--;
	vector<int> pool;
	for (int i = 1; i <= 10; i++)
	{
		while(cards[i]--)
		{
			pool.push_back(i);
		}
	}

	
	int lose = 0; // 상대가 지는 경우의 수
	for (int i = 0; i < pool.size(); i++)
	{
		for (int j = i+1; j < pool.size(); j++)
		{
			int x = pool[i];
			int y = pool[j];
			if (x == y)
			{
				if (x < d)
				{
					lose++;
				}
			}
			else
			{
				if (d > 0)
				{
					lose++;
				}
				else if ((x + y) % 10 < g)
				{
					lose++;
				}
			}
		}
	}

	double ans = (double)lose / (9 * 17);
	cout << fixed << setprecision(3) << ans;

	return 0;
}