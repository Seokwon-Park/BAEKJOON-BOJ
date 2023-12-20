#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	long long sum = 0;
	cin >> n >> k;

	vector<pair<int, int>> jewel;
	vector<int> bag;
	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		int weight, value;
		cin >> weight >> value;
		jewel.push_back({ weight, value });
	}

	for (int j = 0; j < k; j++)
	{
		int weight;
		cin >> weight;
		bag.push_back(weight);
	}

	sort(bag.begin(), bag.end());
	sort(jewel.begin(), jewel.end());

	int ix = 0;
	for (auto b : bag)
	{
		while (ix < n && jewel[ix].first <= b)
		{
			pq.push(jewel[ix].second);
			ix++;
		}

		if (pq.empty())
		{
			continue;
		}

		sum += pq.top();
		pq.pop();
	}
	cout << sum;
 
	return 0;
}
