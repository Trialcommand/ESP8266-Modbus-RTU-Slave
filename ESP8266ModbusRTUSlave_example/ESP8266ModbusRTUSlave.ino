/*
 *  More info      : http://pdacontrolen.com
 *  Mas informacion: http://pdacontroles.com
 *  Channel  Youtube https://www.youtube.com/c/JhonValenciaPDAcontrol/videos   
 *
 *
 *
 *  Modified by Trialcommand
 *   More Tutorials: 
 *   Website http://trialcommand.com
 *	 In English: http://en.trialcommand.com
 *	 En Español: http://en.trialcommand.com  
 *   
 */

#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>
#include <SoftwareSerial.h>  // Modbus RTU pins   D7(13),D8(15)   RX,TX
//SoftwareSerial swSer(13, 15, false, 256);

modbusDevice regBank;
modbusSlave slave;
 
void setup()
{   

//Assign the modbus device ID.  
  regBank.setId(1);


// Holding registers

  regBank.add(40001);  
  regBank.add(40002);  
  regBank.add(40003);  
  regBank.add(40004);  
  regBank.add(40005);  
  regBank.add(40006);  
  regBank.add(40007);  
  regBank.add(40008);  
  regBank.add(40009);  
  regBank.add(40010);  
  
  regBank.add(40011);  
  regBank.add(40012);  
  regBank.add(40013);  
  regBank.add(40014);  
  regBank.add(40015);  
  regBank.add(40016);  
  regBank.add(40017);  
  regBank.add(40018);  
  regBank.add(40019);  
  regBank.add(40020);  

  slave._device = &regBank;  

  Serial.begin(9600);
  delay(100);
// Initialize the serial port for coms at 9600 baud  
  slave.setBaud(9600);
  delay(100);
  Serial.println("Connected "); 
  Serial.println("Modbus RTU Slave Online");  
}

void loop()
{    
  
///////// Holding Register [0] A [9]  =  10 Holding  Registers Lectura
/////     Holding Register [0] A [9]   =  10 Holding Registers Reading  

   
     int Mdelay = 5; // microdelay 

       
     Serial.print("[0] ");
     Serial.print(regBank.get(40000)); 
     delay(Mdelay);
     Serial.print(" [1] ");
     Serial.print(regBank.get(40001));
     delay(Mdelay);
     Serial.print(" [2] ");
     Serial.print(regBank.get(40002));
     delay(Mdelay);
     Serial.print(" [3] ");
     Serial.print(regBank.get(40003));
     delay(Mdelay);
     Serial.print(" [4] ");
     Serial.print(regBank.get(40004));
     delay(Mdelay);
     Serial.print(" [5] ");
     Serial.print(regBank.get(40005));
     delay(Mdelay);
     Serial.print(" [6] ");
     Serial.print(regBank.get(40006));
     delay(Mdelay);
     Serial.print(" [7] ");
     Serial.print(regBank.get(40007));
     delay(Mdelay);
     Serial.print(" [8] ");
     Serial.print(regBank.get(40008));        
     delay(Mdelay);
     Serial.print(" [9] ");
     Serial.println(regBank.get(40009));        
     delay(Mdelay);

   ///////// Holding Register [10] A [19] = 10 Holding Registers Escritura
   ///////// Holding Register [10] A [19] = 10 Holding Registers Writing

    regBank.set(40010,  random(1, 100));        
    regBank.set(40011,  random(1, 100));        
    regBank.set(40012,  random(1, 100));              
    regBank.set(40013,  random(1, 100));              
    regBank.set(40014,  random(1, 100)); 
    regBank.set(40015,  random(1, 100));        
    regBank.set(40016,  random(1, 100));        
    regBank.set(40017,  random(1, 100));              
    regBank.set(40018,  random(1, 100));              
    regBank.set(40019,  random(1, 100)); 
     
   
     slave.run();  

}
