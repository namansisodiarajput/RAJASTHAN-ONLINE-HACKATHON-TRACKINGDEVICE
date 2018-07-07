# RAJASTHAN-ONLINE-HACKATHON-TRACKINGDEVICE
In today’s trend, we are continuously worried about the security of our child, daughter, wife, and mother and of course complete family. 
If they go somewhere we are continuously thinking about them and we don’t know if any problem suddenly comes up with them so in that case, we are unable to do any kind of action on it.safety is the major issue facing by the woman all around the world.

we have developed a system (prototype) comprises of software and hardware that can help user to send alert message to nearby police station and the emergency contact number.
 
we have made two separate project -:
1. hardware that send coordinates to the server 
2. android application(complementary project)


# hardware that send coordinates to the server

we are using ESP32 in our project having inbuilt Bluetooth and wifi module.
![bazaar549177_1](https://user-images.githubusercontent.com/19189211/42413423-3ced7df4-823d-11e8-90f8-30e8c851253b.jpg)
ESP32 is a series of low cost, low power system on a chip microcontroller with integrated Wi-Fi and dual-mode Bluetooth. The ESP32 series employs a Tensilica Xtensa LX6 microprocessor in both dual-core and single-core variations and includes inbuilt antenna switches, RF balun, power amplifier, low-noise receive amplifier, filters, and power management modules. 

function of ESP32 in  project is to connect to available Bluetooth device(mobile) of the user or available wifi of the environment and send geolocation data to the server. if the user pressed the reset button in an emergency.  server sends an alert message to the emergency number provided by the user and find nearby police station for reporting.

#### things required for the project
1. ESP32 module
2. arduino ide with esp32 board and library installed

ESP32 can post geolocation data to any server by using user mobile network access.we have used two services to see the power of ESP32 
1. ESP32 posting coordinates to FIREBASE
2. ESP32 sending an alert message with coordinates through IFTTT service


#### ESP32 posting coordinates to firebase



 
 
