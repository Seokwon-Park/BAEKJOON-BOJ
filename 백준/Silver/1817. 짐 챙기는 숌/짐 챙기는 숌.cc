#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	queue<int> books;
	for(int i = 0; i< n; i++)
	{
		int k;
		cin >> k;
		books.push(k);
	}
	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	int box = 1;
	int cur = 0;
	while (!books.empty())
	{
		int b = books.front(); books.pop();
		if (cur + b <= m)
			cur += b;
		else
		{
			box++;
			cur = b;
		}
	}
	cout << box;

	return 0;
}