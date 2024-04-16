// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "032c004a-1354-4e83-b820-24cd05cfd124";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onCropChange();
void onSoilTypeChange();

float humidity;
float soil_Moisture;
float temperature;
int crop;
int soil_Type;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(humidity, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(soil_Moisture, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(temperature, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(crop, READWRITE, ON_CHANGE, onCropChange);
  ArduinoCloud.addProperty(soil_Type, READWRITE, ON_CHANGE, onSoilTypeChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
