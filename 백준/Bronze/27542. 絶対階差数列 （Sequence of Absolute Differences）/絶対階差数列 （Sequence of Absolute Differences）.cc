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

	while (v.size() > 1)
	{
		vector<int> tmp;
		for (int i = 0; i < v.size()-1; i++)
		{
			tmp.push_back(abs(v[i] - v[i + 1]));
		}
		v = tmp;
	}
	cout << v[0];

	return 0;
}