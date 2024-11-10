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

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[x-1] = i;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		vector<int> vc = v;
		sort(vc.begin() + l - 1, vc.begin()+r);
		vector<int> res(n);
		for (int j = 0; j< n ;j++)
		{
			res[vc[j]] = j + 1;
		}
		for (auto j : res)
			cout << j << ' ';
		cout << '\n';
	}


	return 0;
}