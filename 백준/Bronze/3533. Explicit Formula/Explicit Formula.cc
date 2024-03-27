#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v(10);
	for (int& i : v)
	{
		cin >> i;
	}

	bool res = false;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			res ^= (v[i] | v[j]);
			for (int k = j + 1; k < 10; k++)
			{
				res ^= (v[i] | v[j] | v[k]);
			}
		}
	}

	cout << res;

	return 0;
}
