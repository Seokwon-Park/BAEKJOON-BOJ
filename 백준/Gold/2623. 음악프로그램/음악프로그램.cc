
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1005];
int deg[1005];
vector<int> answer;
bool chk[1005];


void tpsort(int start)
{
	queue<int> q;
	q.push(start);
	chk[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		answer.push_back(cur);
		q.pop();
		for (int nxt : adj[cur])
		{
			deg[nxt]--;
			if (deg[nxt] == 0)
			{
				q.push(nxt);
				chk[nxt] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int l;
		cin >> l;
		vector<int> ord(l);
		for (int i = 0; i < l; i++)
		{
			cin >> ord[i];
		}
		for (int i = 1; i < l; i++)
		{
			adj[ord[i-1]].push_back(ord[i]);
			deg[ord[i]]++;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0 && !chk[i]) // indegree 0인 값 아무거나 고르고 아직 처리가 안 된 숫자인지 확인
		{
			tpsort(i);
		}
	}
	
	if (answer.size() == n)
		for (int i : answer)
		{
			cout << i << '\n';
		}
	else
		cout << 0;


	return 0;
}
