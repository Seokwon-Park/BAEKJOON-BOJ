#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> price;

	for (int i = 0; i < m; i++)
	{
		int pkg, one;
		cin >> pkg >> one;
		price.push_back({ pkg,one });
	}

	sort(price.begin(), price.end());
	int pckg = n / 6;
	int pckg_left = n % 6;
	int pckg_only = price[0].first * ceil(n / 6.0f);
	int pckg_one = price[0].first * pckg;
	sort(price.begin(), price.end(), [](pair<int, int> a, pair<int, int> b) {return a.second < b.second; });
	pckg_one += price[0].second * pckg_left;
	int one_only = price[0].second * n;

	cout << min({pckg_only, pckg_one, one_only});
	
	
 
	return 0;
}
