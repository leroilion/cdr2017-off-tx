#include <Arduino.h>
#include <VirtualWire.h>

#define POWER A0
#define DIRECTION A1

void setup()
{
    /// Init serial and send version number
    Serial.begin(115200);
    Serial.print(F("VERSION : "));
    Serial.println(F(VERSION));

    pinMode(POWER, INPUT);
    pinMode(DIRECTION, INPUT);

    vw_setup(2000);
}

void loop()
{
    uint16_t power = analogRead(POWER);
    uint16_t direction = analogRead(DIRECTION);
    uint32_t powerDirection = power;
    powerDirection = powerDirection << 16;
    powerDirection += direction;
    vw_send((uint8_t *)(&powerDirection), 4);
    vw_wait_tx();
    delay(100);
}
