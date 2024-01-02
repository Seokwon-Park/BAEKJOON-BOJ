#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<long long> tree;
	for (int i = 0; i < n; i++)
	{
		long long input;
		cin >> input;
		tree.push_back(input);
	}
	int st = 0;
	int en = *max_element(tree.begin(), tree.end());

	while (st < en)
	{
		long long mid = (st + en+1) / 2;
		long long sum = 0;
		for (auto t : tree)
		{
			sum += t - mid < 0? 0 : t-mid;
		}
		if (sum >= m)
			st = mid;
		else
			en = mid - 1;
	}
	
	cout << st;

	return 0;
}