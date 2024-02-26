#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int k;
	cin >> k;

	vector<int> ss;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		ss.push_back(input);
	}

	ss.erase(unique(ss.begin(), ss.end()), ss.end());

	sort(ss.begin(), ss.end());

	priority_queue<int> pq;
	for (int i = 1; i < n; i++)
	{
		pq.push(ss[i] - ss[i - 1]);
	}

	for (int i = 0; !pq.empty() && i < k - 1; i++)
	{
		pq.pop();
	}

	int ans = 0;
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}

	cout << ans;

	return 0;
}

