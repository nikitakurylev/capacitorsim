#include <iostream>
#define Q -1.6e-19
#define M 9.1e-31;
#define DELTA 0.001;

using namespace std;

int main()
{
    double u, r, d, l, eps;
    double vx, vy = 0, ay;
    cin >> u >> r >> d >> l >> eps >> vx;
    double x = 0, y = r - d / 2;
    while (x <= l && y <= r) {
        ay = Q * u / (y * log(r / (r - d))) / M;
        vy += ay * DELTA;
        x += vx * DELTA;
        y += vy * DELTA;
        cout << "x: " << x << " y: " << y << "\nVelocity: " << sqrt(vx * vx + vy * vy) << "\nAcceleration: " << ay << "\n\n";
    }
}
