#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	queue<char> q;
	for (auto c : str)
		q.push(c);

	stack<int> s;
	while (!q.empty())
	{
		char c = q.front();
		q.pop();

		if (c == '+')
		{
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();
			s.push(a + b);
		}
		else if (c == '-')
		{
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();
			s.push(a - b);
		}
		else if (c == '*')
		{
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();
			s.push(a * b);
		}
		else if (c == '/')
		{
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();
			s.push(a / b);
		}
		else
		{
			s.push(c - '0');
		}
	}
	cout << s.top();

	return 0;
}