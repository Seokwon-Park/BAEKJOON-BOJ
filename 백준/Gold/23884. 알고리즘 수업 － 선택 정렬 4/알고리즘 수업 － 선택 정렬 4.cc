#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	map<int,int> ix;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		ix[v[i]] = i;
	}
	
	vector<int> vsort = v;
	sort(vsort.begin(), vsort.end());

	int swapped = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (vsort[i] != v[i])
		{
			int value = v[i];
			int tmp = ix[vsort[i]];
			swap(v[i], v[ix[vsort[i]]]);
			ix[value] = tmp;
			swapped++;
		}
		if (swapped == k)
		{
			for (auto i : v)
			{
				cout << i << ' ';
			}
			return 0;
		}
	}
	cout << -1;


	
	return 0;
}
