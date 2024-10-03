#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

map<vector<int>, bool> v;
map<ll, int> coord;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> plan(m);
	vector<int> uni(m);
	for (int i = 0; i < m; i++)
	{
		cin >> plan[i];
		uni[i] = plan[i];
	}
	string dir;
	cin >> dir;

	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	
	for (int i = 0; i < uni.size(); i++)
	{
		coord[uni[i]] = i;
	}

	vector<int> key(uni.size(), 0);
	v[key] = true;
	for (int i = 0; i < m; i++)
	{
		int cur = coord[plan[i]];
		if (dir[i] == '+')
			key[cur]++;
		else
			key[cur]--;
		if (v[key])
		{
			cout << 0;
			return 0;
		}
		v[key] = true;
	}
	cout << 1;

	return 0;
}
