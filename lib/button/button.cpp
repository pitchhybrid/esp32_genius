#include <Arduino.h>
#include "button.hpp"

void Button::iniciar(){
    pinMode(pin, INPUT_PULLUP);
    estado = HIGH;
}

bool Button::liberado(){
    return debouce(LOW);
}

bool Button::pressionado(){
    int read = digitalRead(pin);
    if (read == HIGH)
    {
        return true;
    }
    return false;
}

boolean Button::debouce(int state)
{
    boolean gotEvent = false;

    int reading = digitalRead(pin);

    if (reading != lastState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY)
    {
        if (reading != estado)
        {
            estado = reading;

            if (estado == state)
            {
                gotEvent = true;
            }
        }
    }

    lastState = reading;

    return gotEvent;
}