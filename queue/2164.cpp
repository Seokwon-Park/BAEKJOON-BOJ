#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
			
	int n = 0;
	cin >> n;
	queue<int> q;

	for (int i = 0; i < n; i++)
		q.push(i + 1);

	while (!q.empty())
	{
		if (q.size() == 1) break;
		q.pop();
		int j = q.front();
		q.pop();
		q.push(j);
	}

	cout << q.front();


	return 0;
}
