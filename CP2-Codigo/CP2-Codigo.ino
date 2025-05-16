#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
 
// === PINOS ===
#define DHTPIN 2
#define DHTTYPE DHT22
#define LDR_PIN A3
#define verde 11
#define amarelo 12
#define vermelho 13
#define BUZZER 9
 
// === OBJETOS ===
DHT_Unified dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
// === VARIÁVEIS DE MÉDIA ===
int leituraContador = 0;
float somaTemp = 0, somaUmid = 0, somaLuz = 0;
 
void setup() {
  Serial.begin(9600);
  dht.begin();
 
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(BUZZER, OUTPUT);
 
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistema Iniciado");
 
  Serial.println("Sistema Iniciado");
  Serial.println("-------------------------");
}
 
void loop() {
  sensors_event_t tempEvent, umidEvent;
  dht.temperature().getEvent(&tempEvent);
  dht.humidity().getEvent(&umidEvent);
 
  int valorLDR = analogRead(LDR_PIN);
  float luz = map(valorLDR, 0, 1023, 100, 0); // Agora: 0% = escuro, 100% = muito claro
 
  float temp = tempEvent.temperature;
  float umid = umidEvent.relative_humidity;
 
  if (!isnan(temp) && !isnan(umid)) {
    somaTemp += temp;
    somaUmid += umid;
    somaLuz += luz;
    leituraContador++;
 
    Serial.println("Leitura feita");
    Serial.print(leituraContador);
    Serial.println("° Contagem");
    Serial.print("Temp: ");
    Serial.println(temp);
    Serial.print("Umid: ");
    Serial.println(umid);
    Serial.print("Luz: ");
    Serial.println(luz);
  } else {
    Serial.println("Erro ao ler sensor DHT.");
    return;
  }
 
  if (leituraContador >= 5) {
    float tempMedia = somaTemp / leituraContador;
    float umidMedia = somaUmid / leituraContador;
    float luzMedia = somaLuz / leituraContador;
 
    Serial.println("==== MÉDIAS CALCULADAS ====");
    Serial.print("Temp Média: ");
    Serial.println(tempMedia);
    Serial.print("Umid Média: ");
    Serial.println(umidMedia);
    Serial.print("Luz Média: ");
    Serial.println(luzMedia);
    Serial.println("-------------------------");
 
    // Reset para próxima média
    leituraContador = 0;
    somaTemp = somaUmid = somaLuz = 0;
 
    // Limpa LEDs e buzzer
    digitalWrite(verde, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, LOW);
    noTone(BUZZER);
 
    // === EXIBE LUZ ===
    lcd.clear();
    if (luzMedia <= 30) {
      digitalWrite(verde, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("Ambiente Escuro");
    } else if (luzMedia <= 70) {
      digitalWrite(amarelo, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("Meia luz");
    } else {
      digitalWrite(vermelho, HIGH);
      tone(BUZZER, 1000);
      lcd.setCursor(0, 0);
      lcd.print("Muito Claro");
    }
    lcd.setCursor(0, 1);
    lcd.print("Luz: ");
    lcd.print(luzMedia, 1);
    lcd.print("%");
    delay(2000);
 
    // === EXIBE TEMPERATURA ===
    lcd.clear();
    lcd.setCursor(0, 0);
    if (tempMedia > 15) {
      digitalWrite(amarelo, HIGH);
      tone(BUZZER, 1000);
      lcd.print("Temp. Alta");
    } else if (tempMedia < 10) {
      digitalWrite(amarelo, HIGH);
      tone(BUZZER, 1000);
      lcd.print("Temp. Baixa");
    } else {
      lcd.print("Temp. OK");
    }
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(tempMedia, 1);
    lcd.print(" C");
    delay(2000);
 
    // === EXIBE UMIDADE ===
    lcd.clear();
    lcd.setCursor(0, 0);
    if (umidMedia < 50) {
      digitalWrite(vermelho, HIGH);
      tone(BUZZER, 1000);
      lcd.print("Umidade Baixa");
    } else if (umidMedia > 70) {
      digitalWrite(vermelho, HIGH);
      tone(BUZZER, 1000);
      lcd.print("Umidade Alta");
    } else {
      lcd.print("Umidade OK");
    }
    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(umidMedia, 1);
    lcd.print(" %");
    delay(2000);
 
    // Desliga buzzer no final do ciclo
    noTone(BUZZER);
  }
 
  delay(1000); // Aguarda entre as leituras
}