#include <bits/stdc++.h>

using namespace std;

int ext_gcd(int a, int b, int &x, int &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1, d;
	d = ext_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

void shift_solution(int x, int y, int a, int b, int cnt)
{
	x += b * cnt;
	y -= a * cnt;
	return;
}

int find_solutions(int minx, int maxx, int maxy, int miny, int a, int b, int c)
{
	int lx1, rx1;
	int lx2, rx2;
	int signb = (b > 0) ? 1 : -1;
	int signa = (a > 0) ? 1 : -1;
	g = ext_gcd(a, b, x, y);
	a /= g;
	b /= g;


	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution(x, y, a, b, signb);
	if (x > maxx)
		return 0;

	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution(x, y, a, b, signb);
	if (x > maxx)
		return 0;



}

int main(void)
{
	int a, b, c, ;
	int minx, maxx, lx1, rx1;
	int miny, maxy, lx2, rx2;

	scanf("%d %d %d\n%d %d\n %d %d\n", &a, &b, &c, &minx, &maxx, &miny, &maxy);

}
