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

int checkbox(int st, int en, vector<int>& box)
{
	int ret = 0;
	for (int i = st; i <= en; i++)
	{
		box[i]++;
		ret += box[i];
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int k = 0;
	while ((k + 1) * (k + 1) <= n) k++;
	vector<int> cup(n / k + (n % k != 0));
	vector<vector<int>> box(n / k, vector<int>(k, 0));
	if (n % k != 0)
	{
		box.push_back(vector<int>(n % k));
	}

	for (int i = 0; i < m; i++)
	{
		int res = 0;
		int s, a;
		cin >> s >> a;
		a--; // 0-indexed
		int st = a;
		int en = a + s - 1;

		int stgroup = st / k;
		int engroup = en / k;

		if (stgroup == engroup)
		{
			if (st % k != 0 || en % k != box[stgroup].size() - 1)
			{
				res += checkbox(st % k, en % k, box[stgroup]);
			}
			else
			{
				cup[stgroup]++;
				res += cup[stgroup];
			}
		}
		else
		{
			if (st % k != 0)
			{
				res += checkbox(st % k, k - 1, box[stgroup]);
				stgroup++;
			}
			if (en % k != box[engroup].size() - 1)
			{
				res += checkbox(0, en % k, box[engroup]);
				engroup--;
			}
			for (int block = stgroup; block <= engroup; block++)
			{
				cup[block]++;
				res += cup[block];
			}
		}

		cout << res << '\n';

	}


	return 0;
}