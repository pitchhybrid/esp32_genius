#include "button.hpp"

void Button::iniciar(){
    pinMode(pin, PULLUP);
    estado = digitalRead(pin);
}

bool Button::liberado(){
    if (digitalRead(pin) == LOW)
    {
        estado = true;
    }
    if (digitalRead(pin) == HIGH && estado)
    {
        estado = false;
    }
    return !estado;
}
