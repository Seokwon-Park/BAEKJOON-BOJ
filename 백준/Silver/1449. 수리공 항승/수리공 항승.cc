#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	vector<int> holes(n);
	for (int i = 0; i < n; i++)
	{
		cin >> holes[i];
	}

	sort(holes.begin(), holes.end());

	int answer = 0;
	int prev_hole = -99999;//L은 최대가 1000이라고 했기때문에 처음 구멍에 대해 무조건 갱신됨.

	//이전 구멍에 대해 L 길이의 테이프를 붙인 값보다 이번 구멍의 길이기 길면 새로운 테이프가 필요함.
	for (int i = 0; i < n; i++)
	{
		if (prev_hole + l <= holes[i])//새로운 테이프가 필요한 경우
		{
			prev_hole = holes[i];//갱신
			answer++;// 테이프 하나 사용
		} // else prev_hole에 붙인 테이프로 현재 구멍까지 막을 수 있기때문에 아무것도 안함.
	}
	cout << answer;


	return 0;
}