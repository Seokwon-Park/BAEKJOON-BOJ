#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		vector<int> v(1001, 0);
		int k;
		cin >> k;
		while (k--)
		{
			int s;
			cin >> s;
			v[s]++;
		}
		cout << max_element(v.begin(), v.end()) - v.begin() << '\n';
	}

	return 0;
}