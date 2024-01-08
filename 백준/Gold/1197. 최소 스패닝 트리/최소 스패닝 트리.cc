#include <bits/stdc++.h>
using namespace std;

// 1 <= v <= 10000;
vector<int> p(10005, -1);
tuple<int, int, int> edge[100005]; // 가중치, u, v;

//union-find
int find(int x)
{
	if (p[x]<0) return x;
	return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
	u = find(u); v = find(v);
	// u의 root v의 root가 같으면 같은 그룹
	if (u == v) return false;

	// 다른 그룹이면 같은 그룹으로 만들어줘야 한다.
	// 처음에는 모두 -1이기 때문에 u가 -2 v가 -1이 됨.
	// 일단 parent가 없을때 둘다 -1이기 때문에 한쪽을 -2로 만듦?
	if (p[u] == p[v]) p[u]--;
	
	// 만약 v root의 parent가 u root의 parent보다 크면 v의 parent는 u가 된다.
	// 처음에는 u root의 parent가 -2 v root의 parent가 -1일 것이기 때문에 
	// v root의 parent는 = u가 된다..
	if (p[u] < p[v]) p[v] = u;
	// 같거나 작은경우 parent[v root] = u가 된다.
	else p[u] = v;
	// 서로 다른 그룹일때 더 작은쪽이 다른 쪽 root의 parent가 된다.
	return true;
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;
	
	for (int i = 0; i < e; i++)
	{
		int cost, u, v;
		cin >> u >> v >> cost;
		edge[i] = { cost, u, v };
	}
	// 간선 정보 만들고,
	// 가중치 순으로 정렬한다.
	sort(edge, edge + e);

	int answer = 0;
	int cnt = 0; 
	for (int i = 0; i < e; i++)
	{
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		if (!is_diff_group(a, b)) continue; // 다른 그룹이 아니면 = 같은그룹 이미 연결되었으므로 다시간다.
		//다른 그룹이면 해당 간선의 비용을 정답에 추가한다 ( 정렬되어 있으므로 남은 간선중 가장 비용이 작은 간선임이 보장된다)
		answer += cost;
		cnt++; // 연결된 간선의 개수를 추가한다.
		if (cnt == v - 1) break; // 간선 개수가 vertex의 수 - 1 이면 모든 정점이 연결되었으므로 for문을 끝낸다.
	}
	cout << answer;

	return 0;
 }
