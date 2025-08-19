#ifndef POWERUP_H
#define POWERUP_H
#include <string>

class PowerUp {
    private:
        std::string nombre; 
    public:
        PowerUp(const std::string& nombre) : nombre(nombre) {}
        
}; 

#endif 