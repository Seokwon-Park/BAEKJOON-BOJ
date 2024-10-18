#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int v[600005];
int pfsum[600005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> tmp(n);
	set<int> zip;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		tmp[i] = {a, b};
		zip.insert(a);
		zip.insert(b);
	}

	int ix = 1; // 좌표 압축
	map<int, int> zipMap;
	for (int i : zip)
	{
		zipMap[i] = ix;
		ix++;
	}

	for (int i = 0; i < n; i++)
	{
		auto[a, b] = tmp[i];
		tmp[i] = { zipMap[a], zipMap[b] };
		v[zipMap[a]] += 1;
		v[zipMap[b]+1] -= 1;
	}

	for (int i = 1; i <= ix; i++)
	{
		pfsum[i] = pfsum[i - 1] + v[i];
	}

	int x = max_element(pfsum, pfsum + ix) - pfsum;
	
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		auto [s, e] = tmp[i];
		if (x >= s && x <= e)
		{
			ans.push_back(i+1);
		}
	}
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';

	return 0;
}