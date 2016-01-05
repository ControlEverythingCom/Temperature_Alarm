#include "Temperature_Alarm/Temperature_Alarm.h"

SI7020_A20 tempSensor;
I2CBZ buzzer;

float alarmLimit = 0;
bool highLimit = false;
bool lowLimit = false;

int setAlarmLimit(String limitCommand);


/*SI7120 specs
    Temperature range -40 - +125C
    Sensor is 16 bit or 0-65535
*/

double tempF = 0;

void setup() {
    Particle.variable("Office_Temp", tempF);
    if(!buzzer.initialize(0)){
        Serial.println("failed to initialize buzzer");
    }
    Particle.function("AlarmLimit", setAlarmLimit);
}

void loop() {
    tempF = tempSensor.temperatureF();
    
    if(highLimit){
        Serial.println("Evaluating High limit");
        Serial.print("Current Temperature: ");
        Serial.println(tempF);
        Serial.print("Alarm Limit is: ");
        Serial.println(alarmLimit);
        Serial.print("Alarm trigger: ");
        Serial.println(tempF > alarmLimit);
        if (tempF > alarmLimit){
            buzzer.buzzer(1);
            delay(100);
            buzzer.buzzer(0);
        }else{
            buzzer.buzzer(0);
        }
    }
    if(lowLimit){
        Serial.println("Evaluating High limit");
        Serial.print("Current Temperature: ");
        Serial.println(tempF);
        Serial.print("Alarm Limit is: ");
        Serial.println(alarmLimit);
        Serial.print("Alarm trigger: ");
        Serial.println(tempF < alarmLimit);
        if (tempF < alarmLimit){
            buzzer.buzzer(1);
            delay(100);
            buzzer.buzzer(0);
        }else{
            buzzer.buzzer(0);
        }
    }
    
    
    delay(1000);
}

int setAlarmLimit(String limitCommand){
    //limit command format example: high;75.00 or low;32.00
    int splitIndex = limitCommand.indexOf(";");
    String direction = limitCommand.substring(0,splitIndex);
    if(direction.equalsIgnoreCase("high")){
        highLimit = true;
        lowLimit = false;
        alarmLimit = (limitCommand.substring(splitIndex+1)).toFloat();
        Serial.print("High alarm limit set to: ");
        Serial.println(alarmLimit);
        return 1;
    }
    if(direction.equalsIgnoreCase("low")){
        lowLimit = true;
        highLimit = false;
        alarmLimit = (limitCommand.substring(splitIndex+1)).toFloat();
        Serial.print("Low alarm limit set to: ");
        Serial.println(alarmLimit);
        return 1;
    }
    return 0;
}
