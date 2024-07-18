#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


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

	int ix = max_element(v.begin(), v.end()) - v.begin();

	int cur = v[ix];
	int not_move = 1;
	for (int i = ix - 1; i >= 0; i--)
	{
		if (v[i] == cur - 1)
		{
			cur = v[i];
			not_move++;
		}
	}

	cout << n-not_move;

	return 0;
}