#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

bool v[105];
int p[105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int cur = 1;
	vector<pii> ans;
	v[1] = 1; // 1번노드서 시작
	while (ans.size() < n-1) // 트리의 개수는 노드 수 - 1
	{
		cout << "maze" << endl;
		int nxt;
		cin >> nxt; // nxt를 방문
		if (!v[nxt]) // 방문 안한곳이면
		{
			ans.push_back({ cur, nxt }); // 새로운 간선으로 추가
			p[nxt] = cur; // nxt의 부모노드는 cur
			v[nxt] = 1; // nxt는 방문함
			cur = nxt;
		}
		else // 이미 방문 한곳이면 현재 cur노드에서 더 갈 곳이 없다는게 확정 -> 부모로 돌아가야함
		{ 
			if (nxt == p[cur]) // 만약 중복으로 방문한 정점이 cur의 부모노드면 그냥 부모노드로 이동한거라서 끝
			{
				cur = nxt;
			}
			else // 아니라면 본인의 자식노드를 재방문 한 것이기 때문에 다시 자기자리로 돌아가서 자기 부모로 가야함
			{
				cout << "gaji " << cur << endl;
				cin >> nxt;
				cout << "gaji " << p[cur] << endl;
				cin >> cur; // 자기부모는 아직 확정된게 아니므로 다시 maze로 반복
			}
		}
	}

	cout << "answer" << endl;
	for (auto [u,v] : ans)
	{
		cout << u << ' ' << v << endl;
	}

	return 0;
}