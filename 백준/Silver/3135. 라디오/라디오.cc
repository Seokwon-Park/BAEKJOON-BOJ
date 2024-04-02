#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int freq[10]; // 0~9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n; 
	vector<int> btns(n);
	for (int& i : btns)
		cin >> i;

	int min_gap = abs(a - b);
	bool useBtn = false;
	for (int i : btns)
	{
		int gap = abs(b - i);
		if (gap < min_gap)
		{
			useBtn = true;
			min_gap = gap;
		}
	}

	if (useBtn)
		cout << 1 + min_gap;
	else
		cout << min_gap;


	return 0;
}