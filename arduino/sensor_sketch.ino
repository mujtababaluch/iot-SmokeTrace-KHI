#include <DHT.h>

#define DHTPIN 4          // DHT22 Data Pin
#define DHTTYPE DHT11   // Change to DHT11 if using DHT11
#define MQ2_PIN A0        // MQ2 Analog Output

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  Serial.println("=================================");
  Serial.println("Karachi Air Monitoring System");
  Serial.println("=================================");
}

void loop() {

  // Wait before reading sensor
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  int gasValue = analogRead(MQ2_PIN);

  // Check if reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT22!");
    return;
  }

  Serial.println("-------------------------------");

  Serial.print("Temperature : ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  Serial.print("Humidity    : ");
  Serial.print(humidity, 1);
  Serial.println(" %");

  Serial.print("Gas Value   : ");
  Serial.println(gasValue);

  Serial.print("Air Quality : ");

  if (gasValue < 300) {
    Serial.println("GOOD");
  }
  else if (gasValue < 600) {
    Serial.println("MODERATE");
  }
  else {
    Serial.println("HIGH POLLUTION");
  }

  Serial.println("-------------------------------");
}
