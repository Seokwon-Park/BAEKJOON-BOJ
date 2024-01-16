#include <bits/stdc++.h>

using namespace std;

vector<int> p(1005, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_diff_group(int a, int b)
{
	a = find(a); b = find(b);
	if (a == b) return false;
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<tuple<int, int, int>> edge;
	int prev = 0;
	for (int i = 0; i < k; i++)
	{
		int input;
		cin >> input;
		if (i == 0)
		{
			prev = input;
			continue;
		}
		edge.push_back({ 0, prev, input }); // 발전소간의 거리를 0으로 해주면 얘네끼리 알아서 먼저 연결이 되겠죠. 비용에는 영향 X
		prev = input;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edge.push_back(tie(cost, a, b));
	}

	sort(edge.begin(), edge.end()); // cost 기준으로 정렬해준다.

	int cnt = 0; // 간선수
	int answer = 0; 
	for (int i = 0; i < edge.size(); i++)
	{
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		if (!is_diff_group(a, b)) continue; // 같은 집합에 속해있으면 continue;
		answer += cost;
		cnt++;
		if (cnt == n - 1) break;
	}

	cout << answer;

	return 0;
}