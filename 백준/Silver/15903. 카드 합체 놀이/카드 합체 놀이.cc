#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < m; i++)
	{
		long long card1 = pq.top();
		pq.pop();
		long long card2 = pq.top();
		pq.pop();
		pq.push(card1 + card2);
		pq.push(card1 + card2);
	}

	long long sum = 0;
	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}

	cout << sum;

	return 0;
}