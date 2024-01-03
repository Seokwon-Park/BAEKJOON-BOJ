#include <bits/stdc++.h>

using namespace std;

int n, k;
bool visited[200005];
int moved[200005];
int answer;

int shortest = -1;

//나는 바보다. 나는 바보다. 나는 바보다. 나는 바보다. 나는 바보다. 나는 바보다. 나는 바보다. 나는 바보다. 나는 바보다. 나는 바보다. 
// 풀이 방향 보고 코드 작성.
void bfs(int n)
{
	queue<int> q;
	q.push(n);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == k) // 처음 만난 시간 기록 // 만약 둘의 위치가 같다면 continue로 인해 가짓수 1인 상태로 bfs 종료함
		{
			shortest = moved[cur];
			answer++;
			continue;
		}
		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (nxt < 0 || nxt >200000) continue;
			if (moved[nxt] == 0 || moved[nxt] == moved[cur] + 1) // 만약 0이면 방문하지 않았다는 것이므로 push (시작 위치와 도착 위치가 같은 경우는 위에서 처리됨.)
				// 또는 만약 다음에 방문할 곳이 이미 방문한 곳인데 지금 위치에서 이동해도 걸리는 시간이 같으면 q에 push함.
				// BFS이기 때문에 이미 값이 기록되어 있다면 그 값은 해당 위치로 이동하는 최단시간임을 보장.
			{
				moved[nxt] = moved[cur] + 1;
				q.push(nxt);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	bfs(n);

	cout << shortest << '\n';
	cout << answer;

	return 0;
}