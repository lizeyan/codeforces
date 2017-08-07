#include <cmath>
#include <cstdio>
int main ()
{
    double ax, ay, bx, by, cx, cy;
    scanf("%lf", &ax);
    scanf("%lf", &ay);
    scanf("%lf", &bx);
    scanf("%lf", &by);
    scanf("%lf", &cx);
    scanf("%lf", &cy);

    double l1 = sqrt((by - ay) * (by - ay) + (bx - ax) * (bx - ax));
    double l2 = sqrt((cy - ay) * (cy - ay) + (cx - ax) * (cx - ax));
    double l3 = sqrt((by - cy) * (by - cy) + (bx - cx) * (bx - cx));
    double s = (l1 + l2 + l3) / 2;
    double a = sqrt(s * (s - l1) * (s - l2) * (s - l3));
    printf("%.6lf\n", a * 2);
    return 0;
}
