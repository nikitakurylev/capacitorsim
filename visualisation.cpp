#include <SFML/Graphics.hpp>
#include <iostream>
#define Q -1.6e-19
#define M 9.1e-31;
#define DELTA 0.000001;
#define W 800
#define H 600

using namespace std;

int main()
{
    double u, r, d, l, eps;
    double vx, vy = 0, ay;
    cin >> u >> r >> d >> l >> eps >> vx;
    double x = 0, y = r - d / 2;

    sf::RenderWindow window(sf::VideoMode(W, H), "Capacitor sim");

    sf::CircleShape electron(2.f);

    // set the shape color to green
    electron.setFillColor(sf::Color(100, 250, 50));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (x <= l && y <= r && y >= r - d) {
            ay = Q * u / (y * log(r / (r - d))) / M;
            vy += ay * DELTA;
            x += vx * DELTA;
            y += vy * DELTA;
            cout << "x: " << x << " y: " << y << "\nVelocity: " << sqrt(vx * vx + vy * vy) << "\nAcceleration: " << ay << "\n\n";
        }

        electron.setPosition(float(x / l * W), float((y - r + d) / d * H));

        //window.clear();

        window.draw(electron);

        window.display();

        //Delay
        sf::sleep(sf::milliseconds(1));
    }

    return 0;
}

/*sample input
0.01
700
100
200
1
30000
*/