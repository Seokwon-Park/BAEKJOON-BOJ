#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	int n;
	cin >> n;

	vector<int> v(50001, 0);
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v[m]++;
	}

	cout << *max_element(v.begin() + 1, v.end());

	return 0;
}