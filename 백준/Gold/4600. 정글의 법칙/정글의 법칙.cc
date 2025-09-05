#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<string> group[105];
Hash<string, ll> price;
Hash<string, ll> stock;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		int b, p;
		cin >> b >> p;
		if (b == 0 && p == 0) break;
		b = -b;
		vector<pii> ct(b);
		for (int i = 0; i < b; i++)
		{
			int c, t;
			cin >> c >> t;
			ct[i] = { c,t };
		}

		int curt = 0;
		int arrived = 0;
		vector<pii> state(b); // i의 현재 상태
		vector<int> waiting(b + 5); // i에 기다리고 있는 사람
		waiting[0] = p;
		while (waiting[b] < p)
		{
			for (int i = b - 1; i >= 0; i--)
			{
				if (state[i].first == 0 && state[i].second == 0)
				{
					if (waiting[i] > 0)
					{
						int tmp = min(waiting[i], ct[i].first);
						waiting[i] -= tmp;
						state[i] = { tmp, ct[i].second };
					}
				}
				
				if (state[i].second > 0)
				{
					state[i].second--;
				}
				if (state[i].first != 0 && state[i].second == 0)
				{
					waiting[i + 1] += state[i].first;
					state[i] = { 0,0 };
				}
			}
			curt++;
		}
		cout << curt << '\n';
	}

	return 0;
}