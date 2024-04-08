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
	string s;
	cin >> s;
	vector<double> v(n);
	for (double& i : v)
		cin >> i;
	stack<double> st;
	for (auto c : s)
	{
		if (isalpha(c))
		{
			st.push(v[c - 'A']);
		}
		else
		{
			double b = st.top(); st.pop();
			double a = st.top(); st.pop();
			double res = 0;
			if (c == '+')
				res = a + b;
			else if (c == '-')
				res = a - b;
			else if (c == '*')
				res = a * b;
			else
				res = a / b;
			st.push(res);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top();
	return 0;
}