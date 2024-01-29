#include <bits/stdc++.h>

using namespace std;

vector<int> p(100005,-1);

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

bool is_connect(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return true;
	else return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> edge;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(tie(c, a, b));
	}

	int f1, f2;
	cin >> f1 >> f2;

	sort(edge.begin(), edge.end(), greater<tuple<int, int, int>>());

	for (int i = 0; i < edge.size(); i++)
	{
		int a, b, c;
		tie(c, a, b) = edge[i];
		union_(a, b);
		if (is_connect(f1, f2))
		{
			cout << c;
			break;
		}
	}



	return 0;
}
