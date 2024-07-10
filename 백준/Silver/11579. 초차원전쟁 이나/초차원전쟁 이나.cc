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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<vector<int>> b(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> b[i][j];
			}
		}

		vector<int> target(n);
		for (int i = 0; i < n; i++)
		{
			cin >> target[i];
		}

		vector<int> v(n, 0);
		int moved = 0;
		bool hasAnswer = true;
		for (int i = 0; i < n; i++)
		{
			int needToMove = target[i] - v[i];
			if (needToMove < 0)
			{
				hasAnswer = false;
				break;
			}
			for (int j = 0; j < n; j++)
			{
				v[j] += b[i][j] * needToMove;
			}
			moved += needToMove;
		}
		if (v != target)hasAnswer = false;
		cout << hasAnswer;
		if (hasAnswer)
		{
			cout << ' ' << moved;
		}
		cout << '\n';
	}


	return 0;
}