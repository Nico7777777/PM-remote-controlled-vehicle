#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_transmitter;

#define LEFT 2
#define BACK 3
#define RIGHT 4
#define FRONT 5

int i;
inline void sendMessage(const char* msg) {
    rf_transmitter.send((uint8_t *)msg, strlen(msg));
    rf_transmitter.waitPacketSent();
    delay(100);
}
void setup() {
  Serial.begin(9600);
  pinMode(LEFT, INPUT);
  pinMode(BACK, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(FRONT, INPUT);
  if (!rf_transmitter.init())
    Serial.println("init failed");
  else
    Serial.println("successfully initialised");
}

void loop() {
  i = digitalRead(LEFT);
  if (i) {
    Serial.println("LEFT");
    const char *msg = "LEFT\0";
    rf_transmitter.send((uint8_t *)msg, strlen(msg));
    rf_transmitter.waitPacketSent();
//    delay(100);
  }
  
  i = digitalRead(BACK);
  if (i) {
    Serial.println("BACK");
    const char *msg = "BACK\0";
    rf_transmitter.send((uint8_t *)msg, strlen(msg));
    rf_transmitter.waitPacketSent();
//    delay(100);
    
  }

  i = digitalRead(RIGHT);
  if (i) {
    Serial.println("RIGHT");
    const char *msg = "RIGHT\0";
    rf_transmitter.send((uint8_t *)msg, strlen(msg));
    rf_transmitter.waitPacketSent();
//    delay(100);
  }
  
  i = digitalRead(FRONT);
  if (i) {
    Serial.println("FRONT");
    const char *msg = "FRONT\0";
    rf_transmitter.send((uint8_t *)msg, strlen(msg));
    rf_transmitter.waitPacketSent();
//    delay(100);
  }

}
