#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<pii> st[300005];

//풀이 메모
//어떤 상인이 마을 k에 파는 가격은
//(i번 상인의 최초가격) + 마을번호 - (i번 상인이 처음 파는 마을)로 정의할 수 있고
// Xi + (k -Li)는 (Xi - Li) + k로 묶을 수 있다.
// 그럼 k의 최댓값은 (Xi- Li)가 최대인 값인 경우가 된다.
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int l, r, x;
		cin >> l >> r >> x;
		//x - l 의 값과 끝나는 마을 r을 시작할 마을의 번호에 저장
		st[l].push_back({ x - l, r });
	}

	priority_queue<pii> pq;
	for (int k = 1; k <= n; k++)
	{
		//우선순위 큐에 k에서 장사를 처음시작하는 상인들의 정보를 입력
		for (int i = 0; i < st[k].size(); i++)
		{
			pq.push(st[k][i]);
		}

		//만약 r값이 k보다 작으면 여기서는 이미 떠난 시점이기 때문에 최대 가격이 될 수 없음
		while (!pq.empty() && pq.top().second < k)
		{
			pq.pop();
		}

		//pq가 비어있으면 상인이 없음
		// 아니면 pq의 top이 최댓값이됨
		if (!pq.empty())
		{
			cout << pq.top().first + k << ' ';
		}
		else
		{
			cout << 0 << ' ';
		}
	}

	return 0;
}