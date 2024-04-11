#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		cin >> v[n - i - 1];
		st.push(n - i);
	}

	deque<int> ans;
	for (int i = 0; i < n; i++)
	{
		int val = st.top();
		st.pop();
		if (v[i] == 1 || ans.empty())
		{
			ans.push_front(val);
		}
		else if (v[i] == 2)
		{
			int tmp = ans.front();
			ans.pop_front();
			ans.push_front(val);
			ans.push_front(tmp);
		}
		else
		{
			ans.push_back(val);
		}
	}
	for (auto i : ans)
		cout << i << ' ';

	return 0;
}
