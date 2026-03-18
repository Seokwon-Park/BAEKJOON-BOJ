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



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> v(n, vector<int>(k + 1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> v[i][j];
		}
		v[i][k] = i + 1;
	}

	sort(v.begin(), v.end());

	vector<int> prev = v[0];
	vector<int> cur;
	vector<int> ans;
	ans.push_back(v[0][k]);
	for (int i = 1; i < n; i++)
	{
		cur = v[i];
		for (int j = 0; j < k; j++)
		{
			if (prev[j] > cur[j])
			{
				cout << "NO";
				return 0;
			}
		}
		ans.push_back(cur[k]);
		prev.swap(cur);
	}

	cout << "YES\n";
	for (auto i : ans)
	{
		cout << i << ' ';
	}



	return 0;
}
