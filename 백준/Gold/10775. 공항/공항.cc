#include <bits/stdc++.h>

using namespace std;

vector<int> p(100005, -1);

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

bool land(int a)
{
	a = find(a);
	if (a == 0) return false;
	return true;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int g, pl;
	cin >> g >> pl;

	int answer = 0;
	for (int i = 0; i < pl; i++)
	{
		int gi;
		cin >> gi;
		
		int dock = find(gi);
		if (dock != 0)
		{
			union_(dock, dock - 1);
			answer++;
		}
		else
		{
			break;
		}
	}

	
	cout << answer;

	return 0;
}