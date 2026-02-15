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

vector<ll> segtree;
vector<vector<int>> v;

void update(int node, int st, int en, int ix, int val)
{
	if (st > ix || en < ix)return;
	if (st == en)
	{
		segtree[node] = val;
		return;
	}
	int mid = (st + en) / 2;
	update(node * 2, st, mid, ix, val);
	update(node * 2 + 1, mid + 1, en, ix, val);
	segtree[node] = min(segtree[node * 2], segtree[node * 2 + 1]);
}

int query(int node, int st, int en, int l, int r)
{
	if (st > r || en < l)return INF;
	if (st >= l && en <= r) return segtree[node];
	int mid = (st + en) / 2;
	return min(query(node * 2, st, mid, l, r), query(node * 2 + 1, mid + 1, en, l, r));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	v.resize(n, vector<int>(3));
	segtree.resize(n * 4, INF);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[x-1][0] = i;
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[x-1][1] = i;
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[x-1][2] = i;
	}

	sort(v.begin(), v.end()); // 첫번째 시험 기준 정렬
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		a = v[i][0];
		b = v[i][1];
		c = v[i][2];
		//cout << a << ' ' << b << ' ' << c << '\n';
		int res = query(1, 0, n - 1, 0, b - 1); // 먼저 입력된 학생들은 무조건 첫번째 시험을 나보다 잘봤다(정렬)
		//2번째 시험의 등수 b를 인덱스로 두면 b보다 작은 index에 저장된 학생들은 무조건 두번째 시험을 나보다 잘봤다.
		//2번째 시험을 나보다 잘 본 학생 중 가장 잘 본 학생의 등수를 가져온다.
		//만약 여기서 내가 제일 잘봤으면 나(i번)는 무조건 굉장한 학생이다.
		if (res > c)ans++;
		update(1, 0, n - 1, b, c);
		//내 정보를 세그먼트 트리에 업데이트한다.
	}
	cout << ans;


	return 0;
}