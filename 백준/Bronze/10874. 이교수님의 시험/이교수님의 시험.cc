#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int score = 0;
		for (int j = 1; j <= 10; j++)
		{
			int k;
			cin >> k;
			if (k == (j - 1) % 5 + 1)
				score++;
		}
		if (score == 10)
			cout << i << '\n';
	}
	return 0; 
}
