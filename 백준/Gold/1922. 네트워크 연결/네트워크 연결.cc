#include <bits/stdc++.h>

using namespace std;

vector<int> p(1005, -1);

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

	vector<tuple<int, int, int>> edge;
	for (int i = 0;i < m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edge.push_back(tie( cost, a, b ));
	}

	sort(edge.begin(), edge.end()); // 간선 비용이 제일 싼거부터

	int cnt = 0; // mst에 연결된 간선 개수 = v - 1 이면 mst 끝
	int answer = 0; // mst 완성된 비용
	for (int i = 0; i < edge.size(); i++)
	{
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		if (is_same_group(a, b)) continue;
		union_(a, b);
		answer += cost;
		cnt++;
		if (cnt == n - 1) break;
	}
	
	cout << answer;

	return 0;
}