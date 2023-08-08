#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100001];

int main()
{
	int min = INT_MAX;//최소값
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
  //값 입력
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);
  //정렬
  
	for (int i = 0; i < n; i++)
	{
    //만약 arr의 최댓값에서 x를 뺀값이 m 이상인경우(답이 존재)
		if ( m <= arr[n - 1] - arr[i])
		{
      //arr[i]+m의 lower_bound를 찾는다
			int cur = arr[lower_bound(arr, arr + n, arr[i] + m) - arr] - arr[i];
			if (cur < min)
			{
				min = cur;
			}
		}
		else
		{
			break;
		}
		
	}
	cout << min;


	return 0;
}
