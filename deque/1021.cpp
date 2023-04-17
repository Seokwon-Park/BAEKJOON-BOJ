#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<int> d;
	//n <= 50, m <= n
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		d.push_back(i+1);

	
	while (m--)
	{
		int num;
		cin >> num;
		int ix = find(d.begin(), d.end(), num) - d.begin();
		while (num != d.front())
		{
			if (ix <= d.size() / 2)
			{
				d.push_back(d.front());
				d.pop_front();
				cnt++;
			}
			else
			{
				d.push_front(d.back());
				d.pop_back();
				cnt++;
			}
		}
		d.pop_front();
	}

	cout << cnt;
	
	return 0;
}

