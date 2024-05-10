#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(k);
	for (int i = 1; i <= k; i++)
	{
		int tmp = n * i;
		int res = 0;
		while (tmp)
		{
			res = res * 10 + tmp % 10;
			tmp /= 10;
		}
		v.push_back(res);
	}

	cout << *max_element(v.begin(), v.end());


	return 0;
}