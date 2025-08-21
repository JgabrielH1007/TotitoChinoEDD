#ifndef PUNTO_H
#define PUNTO_H
class Punto {
private:
    char const caracter = '.';
    int x;
    int y;
public:
    Punto(int x = 0, int y = 0) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int newX) {
        x = newX;
    }

    void setY(int newY) {
        y = newY;
    }
    
    char getCaracter() const {
        return caracter;
    }
};

#endif 