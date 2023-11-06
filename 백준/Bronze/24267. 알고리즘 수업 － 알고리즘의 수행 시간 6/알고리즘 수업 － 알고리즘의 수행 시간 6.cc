#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin >> n;
	
	long long sum = 0;
	for (int i = 1; i <= n - 2; i++)
	{
		sum += (n - i - 1) * (n - i) / 2;
	}
	
	cout << sum << '\n' << 3;
			
	return 0;
}

//n = 7
//i = 1 1+2+3+4+5 15
//i = 2 1+2+3+4
//1+2+3
//1+2
//1
////i 1
////j 2
////k 34567
//5
//
////j 3
////k 4567
//4
//
////j 4
////k 567
//3
//
////j 5
////k 67
//2
//
////j 6
////k 7
//1
//
////i 2
////j 3
////k 4567
//4