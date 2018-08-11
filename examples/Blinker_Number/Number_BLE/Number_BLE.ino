#define BLINKER_PRINT Serial
#define BLINKER_BLE

#include <Blinker.h>

#define Number_1 "NUMKey"

BlinkerNumber Number1(Number_1);

void setup()
{
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Blinker.begin();
}

void loop()
{
    Blinker.run();

    if (Blinker.available()) {
        BLINKER_LOG2("Blinker.readString(): ", Blinker.readString());

        Blinker.vibrate();
        
        uint32_t BlinkerTime = millis();
        Blinker.print(BlinkerTime);
        Blinker.print("millis", BlinkerTime);

        Number1.icon("icon_1");
        Number1.color("#FFFFFF");
        Number1.unit("ms");
        Number1.print(BlinkerTime);

        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
}
