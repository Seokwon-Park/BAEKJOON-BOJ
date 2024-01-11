#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// value, index
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 

	int n, l;
	cin >> n >> l;

	vector<int> nums(n);
	vector<int> answer;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		pq.push({ num, i });

		while (pq.top().second < i - l + 1)
		{
			pq.pop();
		}
		answer.push_back(pq.top().first);
	}

	for (int i : answer)
	{
		cout << i << ' ';
	}

	return 0;
}