#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int k;
int n;
int swapped;

void selection_sort(vector<int>& A)
{
	for (int i = n - 1; i >= 0; i--)
	{
		int mx = A[i];
		int ix = i;
		for (int j = 0; j < i; j++)
		{
			if (A[j] > mx)
			{
				mx = A[j];
				ix = j;
			}
		}
		if (i != ix)
		{
			swapped++;
			swap(A[i], A[ix]);
			if (swapped == k)
			{
				cout << A[ix] << ' ' << A[i];
				return;
			}
		}
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >>  k;
	vector<int> v(n);
	for (int& i : v)
		cin >> i;
	selection_sort(v);
	if (swapped < k)
		cout << -1;

	return 0;
}