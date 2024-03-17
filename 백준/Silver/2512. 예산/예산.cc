#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int h;

bool func(vi& v,int n)
{
	int cur= 0;
	for (auto i : v)
	{
		if (i <= n)
			cur += i;
		else
			cur += n;
	}
	return cur > h; // 현재 상한가로 받아줬을때 예산을 넘어가는가?

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vi v(n);
	int sum = 0;
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
	}
	cin >> h;

	if (sum <= h)
	{
		cout << *max_element(v.begin(), v.end());
		return 0;
	}

	int st = 1;
	int ed = INT_MAX/2;
	while (st < ed)
	{
		int mid = (st + ed+1) / 2;
		if (func(v, mid)) ed = mid-1; //넘어갔다면상한가를 줄여야댐.
		else st = mid;
	}
	cout << st;

	return 0;
}
