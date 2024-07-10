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

	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<string> v1(n);
		vector<string> v2(n);
		for (int i = 0; i < n; i++)
			cin >> v1[i];
		sort(v1.begin(), v1.end());
		for (int i = 0; i < n; i++)
			cin >> v2[i];
		sort(v2.begin(), v2.end());
		if (v1 == v2)
			cout << "NOT CHEATER";
		else
			cout << "CHEATER";
		cout << '\n';

	}

	return 0;
}
