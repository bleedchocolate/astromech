#include <bluefruit.h>
#include <ble_gap.h>

// Using Adafruit Feather nRF52 Bluefruit

uint8_t location = 0x01;
SoftwareTimer blinkTimer;

void setup() 
{
  Serial.begin(9600);
  while ( !Serial ) delay(10);
  
  blinkTimer.begin(1000, blink_timer_callback);
  blinkTimer.start();

  if (!Bluefruit.begin())
  {
    Serial.println("Unable to init Bluefruit");
    while(1)
    {
      digitalToggle(LED_RED);
      delay(100);
    }
  }
  else
  {
    Serial.println("Bluefruit initialized (peripheral mode)");
  }

  Bluefruit.setName("Astromech");
  Bluefruit.setTxPower(4);
  startAdvertising(0x01);

}

void loop() 
{
  delay(20000);
  Serial.println("stopping");
  Bluefruit.Advertising.clearData();
  bool stopped = Bluefruit.Advertising.stop();
  delay(20000);
  while ( !stopped ) delay(10);
  startAdvertising(0x02);
}

void startAdvertising(uint8_t location)
{   
  Serial.println("Starting to Advertise");
  Serial.println(location);

  uint8_t msd_payload[8];
  uint16_t msd_cid = 0x0183;
  memset(msd_payload, 0, sizeof(msd_payload));
  memcpy(msd_payload, (uint8_t*)&msd_cid, sizeof(msd_cid));
  
  msd_payload[2] = 0x0A;
  msd_payload[3] = 0x04;
  msd_payload[4] = location;
  msd_payload[5] = 0x02;
  msd_payload[6] = 0xA6;
  msd_payload[7] = 0x01;
  Bluefruit.Advertising.setType(BLE_GAP_ADV_TYPE_NONCONNECTABLE_SCANNABLE_UNDIRECTED);
  Bluefruit.Advertising.addData(BLE_GAP_AD_TYPE_MANUFACTURER_SPECIFIC_DATA, msd_payload, sizeof(msd_payload));
  Bluefruit.ScanResponse.addName();
  Bluefruit.Advertising.restartOnDisconnect(false);
  Bluefruit.Advertising.setInterval(250, 250);
  Bluefruit.Advertising.setFastTimeout(30);
  Bluefruit.Advertising.start(0);
}

void blink_timer_callback(TimerHandle_t xTimerID)
{
  (void) xTimerID;
  digitalToggle(LED_RED);
}
