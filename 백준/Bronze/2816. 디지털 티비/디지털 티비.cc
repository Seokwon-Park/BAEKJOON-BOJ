#include <bits/stdc++.h>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> ch(n);
	int kbs1 = 0, kbs2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> ch[i];
		if (ch[i] == "KBS1")
			kbs1 = i;
		if (ch[i] == "KBS2")
			kbs2 = i;
	}

	int cur = 0;
	while (cur != kbs1)
	{
		cout << 1;
		cur++;
	}
	while (cur != 0)
	{
		cout << 4;
		if (cur - 1 == kbs2)
		{
			swap(kbs2, cur);
		}
		else
			cur--;
	}

	while (cur != kbs2)
	{
		cout << 1;
		cur++;
	}
	while (cur != 1)
	{
		cout << 4;
		cur--;
	}

	return 0;
}