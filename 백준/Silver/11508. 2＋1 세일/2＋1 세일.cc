#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int& i : v)
		cin >> i;
	while (v.size() % 3 != 0)
		v.push_back(0);
	sort(v.begin(), v.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < n; i += 3)
	{
		ans += v[i] + v[i + 1];
	}

	cout << ans;
	
	return 0;
}