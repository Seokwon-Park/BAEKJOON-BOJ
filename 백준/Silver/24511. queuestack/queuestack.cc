#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	deque<int> dq;

	int n, m;
	cin >> n;

	vector<int> A(n), B;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (A[i] == 0)
			B.push_back(input);
	}


	for (auto itr = B.rbegin(); itr != B.rend(); itr++)
	{
		q.push(*itr);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		q.push(input);
	}

	for (int i = 0; i < m; i++)
	{
		cout << q.front() << ' ';
		q.pop();
	}

	return 0;
}
