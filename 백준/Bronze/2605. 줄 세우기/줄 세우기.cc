#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		int j;
		cin >> j;
		ans.insert(ans.end()-j, i);
	}
	for (int i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}