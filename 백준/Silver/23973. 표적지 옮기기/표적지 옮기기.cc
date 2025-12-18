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

int n, m;
bool b[2505][2505];
int score[19][19];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			b[i][j] = c - '0';
			if (b[i][j])
			{
				v.push_back({ j,i });
			}
		}
	}

	for (int i = 0; i <= 18; i++)
	{
		for (int j = 0; j <= 18; j++)
		{
			int x = 10 - abs(i - 9);
			int y = 10 - abs(j - 9);
			score[i][j] = min(x, y);

		}
	}

	int ansx = -1, ansy = -1;
	for (int i = 0; i < v.size(); i++)
	{
		auto [x, y] = v[i];
		vector<int> cnt(11);
		for (int r = y - 9; r <= y + 9; r++)
		{
			for (int c = x - 9; c <= x + 9; c++)
			{
				if (r < 0 || c < 0 || r >= n || c >= m)continue;
				if (b[r][c] == 1)
				{
					cnt[score[r - y + 9][c - x + 9]]++;
				}
			}
		}
		if (count(cnt.begin(), cnt.end(), 1) == 10)
		{
			ansx = x;
			ansy = y;
			break;
		}
	}

	if (ansx == -1 && ansy == -1)
		cout << -1;
	else
		cout << ansy << ' ' << ansx;



	return 0;
}