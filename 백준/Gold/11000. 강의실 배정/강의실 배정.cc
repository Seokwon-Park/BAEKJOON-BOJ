#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;

	vector<pair<int, int>> pv;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int st, ed;
		cin >> st >> ed;
		
		pv.push_back({ st, ed });
	}

	sort(pv.begin(), pv.end());

	for (auto p : pv)
	{
		if (!pq.empty())
		{
			if (pq.top() <= p.first)
				pq.pop();
		}

		pq.push(p.second);
	}


	cout << pq.size();

	
	return 0;
}
