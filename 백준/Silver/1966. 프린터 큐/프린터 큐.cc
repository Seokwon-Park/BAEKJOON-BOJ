#include <bits/stdc++.h>

using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);




	int tc = 0;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		queue<pair<int, int>> q;
		vector<int> priority;
		int size, loc;
		cin >> size >> loc;
		for (int j = 0; j < size; j++)
		{
			int input;
			cin >> input;
			q.push({ input, j });
			priority.push_back(input);
		}
		sort(priority.begin(), priority.end());
		int count = 0;
		while (1)
		{
			if (q.front().first != priority.back())
			{
				auto tmp = q.front();
				q.pop();
				q.push(tmp);
			}
			else
			{
				int ix = q.front().second;
				priority.pop_back();
				q.pop();
				count++;
				if (ix == loc)
				{
					break;
				}				
			}
		}
		cout << count << '\n';
	}

	return 0;
}