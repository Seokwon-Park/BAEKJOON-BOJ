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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}

	sort(v.begin(), v.end(), [](auto& a, auto& b) 
		{
			return count(a.begin(), a.end(), 1) > count(b.begin(), b.end(), 1);
		}
	);

	bool isOK = true;
	for (int i = 0; i < m; i++)
	{
		bool chk = false;
		for (int j = 0; j < n; j++)
		{
			if (v[j][i] == 0) chk = true;
			else
			{
				if (chk) isOK = false;
			}
		}
	}

	cout << (isOK ? "YES" : "NO");


	return 0;
}