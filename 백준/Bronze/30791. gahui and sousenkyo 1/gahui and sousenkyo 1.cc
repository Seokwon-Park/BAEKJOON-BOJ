#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	priority_queue<int> pq;
	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		pq.push(n);
	}

	int th16 = pq.top();
	pq.pop();

	int answer = 0;
	while (!pq.empty() && th16 - pq.top() <= 1000)
	{
		pq.pop();
		answer++;
	}

	cout << answer;

	return 0;
}
