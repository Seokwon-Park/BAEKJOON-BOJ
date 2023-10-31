#include <bits/stdc++.h>

using namespace std;

void convDQ(string& arr, deque<int>& dq)
{
	int cur = 0;
	for (int i = 1; i < arr.length(); i++)
	{
		if (arr[i] == ',' || arr[i] == ']')
		{
			if (cur == 0) break;
			dq.push_back(cur);
			cur = 0;
		}
		else
		{
			cur = cur * 10 + (arr[i] - '0');
		}
	}
}

bool AC(string& p, deque<int>& dq)
{	
	bool rev = false;
	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == 'R')
		{
			rev = !rev;
		}
		else
		{			
			if (dq.empty())
				return false;
			else
			{
				if (!rev)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}
	}
	if (rev)
	{
		reverse(dq.begin(), dq.end());
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	bool chk;
	cin >> tc;

	deque<int> dq;

	for (int i = 0; i < tc; i++)
	{
		string p;
		int n;
		string arr;
		cin >> p >> n >> arr;
		convDQ(arr, dq);
		chk = AC(p, dq);
		if (chk)
		{
			cout << '[';
			for (auto a = dq.begin(); a!=dq.end(); a++)
				if (a != (dq.end() - 1))
					cout << *a << ',';
				else
					cout << *a;

			cout << "]\n";
		}
		else
		{
			cout << "error\n";
		}
		dq.clear();
	}

	return 0;
}
