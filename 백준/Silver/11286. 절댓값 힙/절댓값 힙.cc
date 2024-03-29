
#include <bits/stdc++.h>

using namespace std;

class cmp
{
public:
	bool operator() (int a, int b)
	{
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		return a > 0 && b < 0;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	priority_queue<int, vector<int>, cmp> pq;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input != 0)
		{
			pq.push(input);
		}
		else
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}