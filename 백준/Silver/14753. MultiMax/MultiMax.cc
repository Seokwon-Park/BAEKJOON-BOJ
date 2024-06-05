#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int res1 = v[0] * v[1];
	int res2 = v[0] * v[1]* v[n-1];
	int res3 = v[n-1] * v[n-2];
	int res4 = v[n-1] * v[n-2] * v[n-3];

	cout << max({ res1,res2,res3,res4 });

	return 0;
}
