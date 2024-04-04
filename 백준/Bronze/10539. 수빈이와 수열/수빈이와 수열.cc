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
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<int> ans(n);
	ans[0] = v[0];
	for (int i = 1; i < n; i++)
	{
		ans[i] = v[i] * (i + 1) - v[i - 1] * i;
	}

	for (int i : ans)
		cout << i << ' ';


	return 0;
}