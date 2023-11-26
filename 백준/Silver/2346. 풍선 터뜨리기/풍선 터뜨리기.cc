#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	deque<pair<int, int>> dq;
	int n;
	cin >> n;

	vector<int> seq;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		dq.push_back(make_pair(i + 1, val));
	}


	while (true)
	{		
		int idx = dq.front().first;
		int mov = dq.front().second;
		seq.push_back(idx);
		dq.pop_front();

		if (dq.empty())
		{
			break;
		}

		if (mov > 0)
		{
			for (int j = 0; j < mov-1; j++)
			{
				auto tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
		}
		else if (mov <0)
		{
			for (int j = 0; j < abs(mov); j++)
			{
				auto tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
		}
	}

	for (int idx : seq)
	{
		cout << idx << ' ';
	}

	return 0;
}