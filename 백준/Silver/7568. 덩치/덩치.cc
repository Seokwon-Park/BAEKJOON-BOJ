#include <bits/stdc++.h>

using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> w(n);
	vector<int> l(n);
	vector<int> rank(n, 1);
	string str;
	

	for(int i =0; i< n ; i++)
	{
		cin >> w[i];
		cin >> l[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (w[i] < w[j] && l[i] < l[j])
			{
				rank[i]++;
			}
		}
	}

	for (auto r : rank)
	{
		cout << r << ' ';
	}
	

	return 0;
}
