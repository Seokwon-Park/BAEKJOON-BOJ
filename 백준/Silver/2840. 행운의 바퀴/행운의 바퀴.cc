#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	queue<char> q;
	for (int i = 0; i < k; i++)
	{
		int s;
		char c;
		cin >> s >> c;
		for (int j = 0; j < s-1; j++)
		{
			if (q.size() < n)
			{
				q.push('?');
			}
			else
			{
				char tmp = q.front();
				q.pop();
				q.push(tmp);
			}
		}
		if (q.size() < n)
		{
			q.push(c);
		}
		else
		{
			if (q.front() != c &&q.front() != '?')
			{
				cout << '!';
				return 0;
			}
			else
			{
				q.pop();
				q.push(c);
			}
		}
	}
	
	string ans;
	while (!q.empty())
	{
		ans += q.front();
		q.pop();
	}
	vector<bool> isused(26, false);
	for (auto c : ans)
	{
		if (c == '?')continue;
		else
		{
			if (isused[c - 'A'])
			{
				cout << '!';
				return 0;
			}
			isused[c - 'A'] = true;
		}
	}
	cout << string(ans.rbegin(), ans.rend());
	return 0;
}