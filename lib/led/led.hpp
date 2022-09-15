#include <Arduino.h>

class Led
{
private:
    bool estado;
    int pin;

public:
    Led(int _pin) : pin(_pin){};
    void iniciar();
    void acender();
    void acender(int ms);
    void apagar();
    void piscar(int v);
     
};