#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Point {
  private:
    int x, y;

  public:    
    Point () {
        x = 0, y = 0;
    }
    Point (int a, int b) {
        x = a, y = b;
    }

    void set_point (int a, int b) {
        x = a, y = b;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

class Polygon {
  private:
    vector<Point> points;

  public:
    Polygon (char *filename) {
        ifstream input;
        input.open (filename);

        int a, b;
        Point temp;
        while (input >> a >> b) {
            temp.set_point (a, b);
            points.push_back (temp);
        }
        if (points.size() > 0) points.push_back (points[0]);
    }
    double calcArea() {
        int rl = 0, lr = 0;
        for (size_t i = 0; i+1 < points.size(); i++) {
            lr += points[i].getX() * points[i+1].getY();
            lr -= points[i].getY() * points[i+1].getX();
        }

        if (lr < 0) lr = -lr;

        return 1.0 * lr/2;
    }
};

int main(int argc, char **argv) {
    Polygon pol(argv[1]);
    cout << pol.calcArea() << '\n';
    return 0;
}

