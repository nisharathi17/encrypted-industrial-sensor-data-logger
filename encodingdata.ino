#include <Arduino.h>

// ── Fake sensor functions ─────────────────────────────────────────────
// These simulate a DHT22 sensor
// When real hardware arrives, swap these out for dht.readTemperature()

float getFakeTemperature() {
    // Drifts between 24.0 and 26.0 over time
    return 25.0 + (sin(millis() / 5000.0) * 1.0);
}

float getFakeHumidity() {
    // Drifts between 55.0 and 65.0 over time
    return 60.0 + (cos(millis() / 7000.0) * 5.0);
}

// ── Setup ─────────────────────────────────────────────────────────────
void setup() {
    Serial.begin(115200);
    Serial.println("=== Encrypted Data Logger - Phase 1 ===");
    Serial.println("Sensor ready.");
}

// ── Main loop ─────────────────────────────────────────────────────────
void loop() {
    delay(2000);   // read every 2 seconds

    unsigned long timestamp   = millis();
    float         temperature = getFakeTemperature();
    float         humidity    = getFakeHumidity();

    // Check for bad values (good habit even with fake data)
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("ERROR: Bad sensor reading");
        return;
    }

    // Print everything to Serial Monitor
    Serial.println("---");
    Serial.print("Time (ms):   ");
    Serial.println(timestamp);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
    Serial.print("Humidity:    ");
    Serial.print(humidity);
    Serial.println(" %");
}