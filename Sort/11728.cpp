#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	vector<int> A(n);
	vector<int> B(m);
	vector<int> C(n+m);

	int i;

	for (i = 0; i < n; i++)
		cin >> A[i];
	
	for (i = 0; i < m; i++)
		cin >> B[i];

	int a_cur = 0;
	int b_cur = 0;
	for (i = 0; i < m + n; i++)
	{
		if (a_cur == A.size())
		{
			C[i] = B[b_cur++];			
			continue;
		}

		else if (b_cur == B.size())
		{
			C[i] = A[a_cur++];
			continue;
		}
		
		if (A[a_cur] < B[b_cur])
		{
			C[i] = A[a_cur++];			
		}
		else
		{
			C[i] = B[b_cur++];
		}
		

	}

	for (auto k : C)
		cout << k << ' ';

	return 0;
}
