#define BLINKER_PRINT Serial
#define BLINKER_MQTT
#define BLINKER_ESP_SMARTCONFIG

#include <Blinker.h>

char auth[] = "Your MQTT Secret Key";

void setup()
{
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    
    Blinker.begin(auth);
}

void loop()
{
    Blinker.run();

    if (Blinker.available()) {
        BLINKER_LOG2("Blinker.readString(): ", Blinker.readString());

        uint32_t BlinkerTime = millis();

        Blinker.beginFormat();
        Blinker.vibrate();        
        Blinker.print("millis", BlinkerTime);
        Blinker.endFormat();

        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
}