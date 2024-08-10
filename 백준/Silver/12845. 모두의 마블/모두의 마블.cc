#include <bits/stdc++.h>
#include <regex>

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
	vector<int> v(n);
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		total += v[i];
	}

	int mx = *max_element(v.begin(), v.end());
	cout << total - mx + mx * (n - 1);




	return 0;
}