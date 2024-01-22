#include <bits/stdc++.h>

using namespace std;

vector<int> p(500005, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_diff(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return false;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	bool is_find = false;
	int first_cycle = 0;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if(!is_find)
			if (!is_diff(a, b)) // 다른 그룹이면 union, 같은 그룹인데 이 값이 들어왔으면 차례를 기록하고 flag를 바꾼다.
			{
				is_find = true;
				first_cycle = i;
			}
	}

	cout << first_cycle;

	return 0;
}