#include <bits/stdc++.h>

using namespace std;

int func(int n, int r, int c)
{
	if (n == 0)return 2*r+c;
	int half = (1 << n);
  	//1 번째 구역
	if (r < half && c < half) return func(n - 1, r, c);
	//2 번째 구역
	else if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
  	//3 번째 구역
	else if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
  	//4 번째 구역
	else return 3 * half * half + func(n - 1, r - half, c - half);

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);

	return 0;
}

//Z문제
