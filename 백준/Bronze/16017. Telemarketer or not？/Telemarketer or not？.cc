#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

bool chk(int n)
{
	if (n == 9 || n == 8)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vi v(4);
	for (auto& i : v)
	{
		cin >> i;
	}

	if (chk(v[0]) && chk(v[3]) && v[1] == v[2])
		cout << "ignore";
	else
		cout << "answer";

	return 0;
}