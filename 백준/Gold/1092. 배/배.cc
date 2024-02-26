#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> cr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cr[i];
	}
	sort(cr.begin(), cr.end(), greater<int>());
	int m;
	cin >> m;
	vector<int> boxes;
	vector<bool> isused(m, false);
	int carried = 0;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		boxes.push_back(input);
	}

	sort(boxes.begin(), boxes.end(), greater<int>());

	if (boxes[0] > cr[0])
	{
		cout << -1;
		return 0;
	}
	int t = 0;
	while (carried != m)
	{
		int ix = 0;
		t++;
		for (int i = 0; i < m; i++)
		{
			if (isused[i])continue;
			if (boxes[i] <= cr[ix])
			{
				carried++;
				isused[i] = true;
				ix++;
			}
			if (ix == n) break;
		}
	}

	cout << t;

	return 0;
}

