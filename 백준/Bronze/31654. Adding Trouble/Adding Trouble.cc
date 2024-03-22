#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int board[1005][6]; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	cout << (a + b == c ? "correct!" : "wrong!");

	return 0;
}