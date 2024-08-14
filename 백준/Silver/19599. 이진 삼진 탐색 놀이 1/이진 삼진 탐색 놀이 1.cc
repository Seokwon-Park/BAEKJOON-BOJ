#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int b[500000];
int t[500000];

void binary_search(int l, int r, int lv) {
	int mid = (l + r) / 2;
	b[mid] = lv;
	if (l == r)return;
	if (l <= mid - 1)
		binary_search(l, mid - 1, lv + 1);
	if (mid + 1 <= r)
		binary_search(mid + 1, r, lv + 1);
}

void ternary_search(int l, int r, int lv)
{
	if (l == r)
	{
		t[l] = lv;
		return;
	}
	int lmid = l + ((r - l) / 3);
	int rmid = r - ((r - l) / 3);
	t[lmid] = lv++;
	t[rmid] = lv++;

	if (l <= lmid - 1)
		ternary_search(l, lmid - 1, lv);
	if (lmid + 1 <= rmid - 1)
		ternary_search(lmid + 1, rmid - 1, lv);
	if (rmid + 1 <= r)
		ternary_search(rmid + 1, r, lv);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	binary_search(0, n - 1, 0);
	ternary_search(0, n - 1, 0);

	int bltt = 0;
	int beqt = 0;
	int bgtt = 0;

	for (int i = 0; i < n; i++)
	{
		if (b[i] < t[i])
			bltt++;
		else if (b[i] == t[i])
			beqt++;
		else
			bgtt++;
	}

	cout << bltt << '\n' << beqt << '\n' << bgtt;
	return 0;

}