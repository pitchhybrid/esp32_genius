#include <Arduino.h>

class Button{
    private:
        bool estado;
        int pin;
    public:
        Button(int _pin) : pin(_pin){};
        void iniciar();
        bool liberado();
};