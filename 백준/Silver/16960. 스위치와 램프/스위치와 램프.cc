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

int lampCnt[2005];
vector<int> swch[2005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	bool ans = 0;
	for (int i =0 ;i < n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
		{
			int y;
			cin >> y;
			swch[i].push_back(y);
			lampCnt[y]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < swch[i].size(); j++)
		{
			lampCnt[swch[i][j]]--;
		}
		int res = count_if(lampCnt + 1, lampCnt + m + 1, [](const int& a) {return a > 0; });
		if (res == m)
		{
			ans = 1;
			break;
		}
		for (int j = 0; j < swch[i].size(); j++)
		{
			lampCnt[swch[i][j]]++;
		}
	}
	cout << ans;

	return 0;
}