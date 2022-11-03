#include <Arduino.h>
#include <OrderedStateMachine.h>

OrderedStateMachine<2> stateMachine;

void setup()
{
    Serial.begin(115200);
    stateMachine.addState([]{ Serial.println("An"); });
    stateMachine.addState([]{ Serial.println("Aus"); });

    Bla a;
    a.blub();
}

void loop()
{
    static uint32_t prevMillis;
    if(millis() - prevMillis >= 1000)
    {
        stateMachine.transitionNextState();
        prevMillis = millis();
    }
    stateMachine.run();
}