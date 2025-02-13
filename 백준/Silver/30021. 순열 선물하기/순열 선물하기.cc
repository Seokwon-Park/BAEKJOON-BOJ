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

	vector<int> ans = {1, 3, 2};
	for (int i = 4; i <= n; i++)
	{
		ans.push_back(i);
	}

	if (n == 2)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES\n";
		if (n == 1) cout << 1;
		else
		{
			for (auto i : ans)
				cout << i << ' ';
		}
	}




	return 0;
}



