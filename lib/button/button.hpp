#include <Arduino.h>

class Button{
    private:
        int pin;
        bool estado;

        const long DEBOUNCE_DELAY = 50;

        int lastState = HIGH;
        int lastDebounceTime;

    public:
        Button(int _pin) : pin(_pin){};
        void iniciar();
        bool pressionado();
        bool liberado();
        bool debouce(int state);
};