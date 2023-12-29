#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> st;

	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	for (char c : str)
	{
		if (st.empty())
		{
			st.push(c-'0');
		}
		else
		{
			int nxt = c - '0';
			while (!st.empty() && st.top() < nxt && k>0)
			{
				k--;
				st.pop();
			}
			st.push(nxt);
		}
	}
	
	while (k > 0)
	{
		st.pop();
		k--;
	}

	vector<int> num;
	while (!st.empty())
	{
		num.push_back(st.top());
		st.pop();
	}

	reverse(num.begin(), num.end());

	for (int n : num)
	{
		cout << n;
	}

	return 0;
}