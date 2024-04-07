#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int h = max(v[0], n-v[v.size()-1]); // 맨끝과 맨앞.
	for (int i = 1; i < m; i++)
	{
		int gap = v[i] - v[i - 1];
		if (gap % 2)
			h = max(gap / 2 + 1, h);
		else
			h = max(gap / 2, h);
	}

	cout << h;

	return 0;
}