#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		vector<int> score(10001, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int num;
				cin >> num;
				score[num]++;
			}
		}

		vector<int> tmp;
		tmp = score;
		nth_element(tmp.begin(), tmp.begin() + 1, tmp.end(), [](int a, int b)
			{
				return a > b;
			});
		int second = tmp[1];

		for (int i = 1; i <= 10000; i++)
		{
			if (second == score[i])
			{
				cout << i << ' ';
			}
		}

		cout << '\n';
	}

	return 0;
}