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
	vector<int> order(n);
	for (int i = 0; i < n; i++)
	{
		cin >> order[i];
		order[i]--;
	}

	vector<int> cows(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cows[i];
	}

	vector<int> ans(n);

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < n; i++)
		{
			ans[i] = cows[order[i]];	
		}
		ans.swap(cows);
	}

	for (int i = 0; i < n; i++)
	{
		cout << cows[i] << '\n';
	}



	return 0;
}