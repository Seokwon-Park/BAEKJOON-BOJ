#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (s.empty())
			s.push(input);
		else
		{
			while (!s.empty() && s.top() <= input)
				s.pop();
			s.push(input);
		}
	}
	cout << s.size() << '\n';

	return 0;
}