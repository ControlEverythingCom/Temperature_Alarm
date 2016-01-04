# About

This Library is intended for use with VCNL4010 Proximity and Ambient Light Sensor with Infrared Emitter I²C Mini Module.

The intention of this library is to make use of the VCNL4010 Proximity and Ambient Light Sensor with Infrared Emitter I²C Mini Module with Particle development web IDE as simple as possible for users.
###Developer information
NCD has been designing and manufacturing computer control products since 1995.  We have specialized in hardware design and manufacturing of Relay controllers for 20 years.  We pride ourselves as being the industry leader of computer control relay products.  Our products are proven reliable and we are very excited to support Particle.  For more information on NCD please visit www.controlanything.com

###Requirements
- VCNL4010 Proximity and Ambient Light Sensor with Infrared Emitter I²C Mini Module
- Particle Core/Photon module
- Knowledge base for developing and programming with Particle Core/Photon modules.

### Version
1.0.0

### How to use this library

The libary must be imported into your application.  This can be done through the Particle WEB IDE by selecting Libraries, then select the VCNL4010.  Click Include in App button.  Select the App you want to include the library in.  Finally click Add to this app.  For more information see [Particle's documentation] [sparkIncludeLibrary].

### Example use

Once the Library is included in your applicaiton you should see an include statement at the top like this:
```cpp
//This #include statement was automatically added by the Particle IDE.
#include "VCNL4010/VCNL4010.h"
```

Now you need to instanciate an object of the library for use in your application like this:
```cpp
VCNL4010 sensor;
```

Here is an example use case for the class:
```cpp
// This #include statement was automatically added by the Particle IDE.
#include "VCNL4010/VCNL4010.h"
VCNL4010 sensor;

void setup() {
    Serial.begin(115200);
    sensor.initialize();
}

void loop() {
    Serial.print("Lux: ");
    Serial.println(sensor.ambientLight());
}
```

###Public accessible methods
```cpp
void initialize();
```
>Must be called first before using the object.  This method should also be called any time communication with the controller is lost or broken to recover communication.


```cpp
void ambientLight();
```
>This method returns the ambient light measurement in lux(?).


License
----

GNU
[sparkIncludeLibrary]:https://docs.particle.io/guide/getting-started/build/photon/