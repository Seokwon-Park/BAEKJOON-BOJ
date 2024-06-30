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
	
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)break;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		int ix = unique(v.begin(), v.end()) - v.begin();

		for (int i = 0; i < ix; i++)
			cout << v[i] << ' ';
		cout << "$\n";
	}
	

	return 0;
}