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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		vector<vector<int>> funcs(3);
		for (int i = 0; i < 3; i++)
		{
			int bit;
			cin >> bit;
			vector<int> func(bit);
			for (int j = bit - 1; j >= 0; j--)
			{
				cin >> func[j];
			}
			funcs[i] = func;
		}

		vector<int> result(funcs[0].size() + funcs[1].size());
		for (int i = 0; i < funcs[0].size(); i++)
		{
			for (int j = 0; j < funcs[1].size(); j++)
			{
				result[i + j] += funcs[0][i] * funcs[1][j];
				result[i + j] %= 2;
			}
		}

		while (result.back() == 0 && result.size() > 1) result.pop_back();

		reverse(result.begin(), result.end());
		reverse(funcs[2].begin(), funcs[2].end());

		int tmp = (int)result.size() - (int)funcs[2].size();
		for (int i = 0; i <= tmp; i++)
		{
			if (result[i] == funcs[2][0])
			{
				for (int j = 0; j < funcs[2].size(); j++)
				{
					result[i + j] = result[i + j] - funcs[2][j];
					result[i + j] = (result[i + j] + 2) % 2;
				}
			}
		}

		int st = 0;
		while (st+1 < result.size() && result[st] == 0)st++;
		cout << result.size() - st << ' ';
		for (int i = st; i < result.size(); i++)
		{
			cout << result[i] << ' ';
		}
			
		cout << '\n';
	}
	return 0;
}