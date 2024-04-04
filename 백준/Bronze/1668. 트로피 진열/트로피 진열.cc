#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	stack<int> sleft;
	int left = 0;
	stack<int> sright;
	int right = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if (sleft.empty())
		{
			left++;
			sleft.push(m);
		}
		else if (sleft.top() < m)
		{
			left++;
			sleft.push(m);
		}
		v.push_back(m);
	}
	for (auto itr = v.rbegin(); itr != v.rend(); itr++)
	{
		if (sright.empty())
		{
			right++;
			sright.push(*itr);
		}
		else if (sright.top() < *itr)
		{
			right++;
			sright.push(*itr);
		}
	}

	cout << left << '\n' << right;


	return 0;
}