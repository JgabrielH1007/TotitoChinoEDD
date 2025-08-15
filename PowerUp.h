#ifndef POWERUP_H
#define POWERUP_H
#include <string>

class PowerUp {
    private:
        std::string nombre;
        
    public:
        PowerUp(const std::string& nombre) : nombre(nombre) {}
        std::string getNombre() const {
            return nombre;
        }
        void setNombre(const std::string& nombre) {
            this->nombre = nombre;
        }
}; 

#endif // POWERUP_H