#include <bits/stdc++.h>

using namespace std;

vector<int> p(205, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void union_(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
}

bool is_same_group(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return true;
	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int input;
			cin >> input;
			if (input)
				union_(i, j);
		}
	}

	vector<int> plan(m);
	for (int i = 0; i < m; i++)
	{
		cin >> plan[i];
	}

	for (int i = 0; i < m-1; i++)
	{
		if (!is_same_group(plan[i], plan[i + 1]))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}