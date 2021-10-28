#include <bits/stdc++.h>

using namespace std;

int len[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
int ans[10][4] = {
	{0},
	{1},
	{6, 2, 4, 8},
	{1, 3, 9, 7},
	{6, 4},
	{5},
	{6},
	{1, 7, 9, 3},
	{6, 8, 4, 2},
	{1, 9},
};

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;

		a %= 10;
	
		if (a == 0)
			cout << 0 << '\n';
		else if (b == 0 || a == 1)
			cout << 1 << '\n';
		else {
			cout << ans[a][b % len[a]] << '\n';
		}
	}
	return 0;
}
