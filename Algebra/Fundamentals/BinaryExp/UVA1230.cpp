#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--) {
		int n, x, y;
		scanf("%d %d %d", &x, &y, &n);
		//while (y >= n)
		//	y -= n;
		int s, a;
		while (x >= n)
			x -= n;
		a = x;
		s = 1;
		while (y) {
			if (y & 1)
				s = (s * a) % n;
			a = (a * a) % n;
			y >>= 1;
		}
		printf("%d\n", s);
	}
	scanf("%d", &t);
	return 0;
}
