#include "definition.h"
#include "command.h"
#include <Wire.h>
#include <SoftwareSerial.h>

#define SLAVE_ADDR 10

#define SLAVE_ADDR2 11

#define ANSWRSIZE 5

int actiune = 0;

SoftwareSerial FP_Serial(FP_RX, FP_TX); 

void setup() 
{    
  Wire.begin(SLAVE_ADDR);
  Wire.onReceive(receiveEvent);
  
   //UART coummunication 
   Serial.begin(9600);     
   FP_Serial.begin(9600); 
     
   //intial fingerprint module of protocol
   FP_OPEN();
   if(return_ack != ACK)
     {
      Serial.println("Fingerprint-UART error...");
      while(1);
     }
}

void receiveEvent() {
  unsigned char choose_function;
  choose_function = Wire.read();
  Serial.print(choose_function);
}

void loop() 
{
    unsigned char choose_function;   
    unsigned int loop_time;  
  
//    Serial.print("------------------------------------\n"); 
//    Serial.print("**Modify date:20190115 by ADH-tech**\n"); 
//    Serial.print("Please choose functions:\n");
//    Serial.print("1.Enrollment\n");
//    Serial.print("2.Identify\n");
//    Serial.print("3.Delete All\n");
//    Serial.print("4.Get User Count\n");
//    Serial.print("------------------------------------\n"); 
     
    while(Serial.available()){Serial.read();}  
    while(1)  //waiting for user choise
       {        
       if (Serial.available() > 0)
          {
           choose_function=(char)Serial.read();  
           break;
           }            
       }    
           
    if(choose_function>='1' && choose_function<='4')  
       {
       if(choose_function=='1')   //Enrollment
         {
         unsigned char enroll_time;
         unsigned int capture_success;
        
         Serial.print("--Enrollment processing--\n");
         Serial.print("***Plase press your fingers***\n");
         FP_LED_open();
         if(return_ack != ACK)
            {
            Serial.print("LED_open:No ack\n");
            FP_LED_close();
            return;
           }
                                                                                                                    
         FP_EnrollStart(0); 
         if(return_ack != ACK && return_para==0x1005)  //change another IDs if default ID=0 is occupied
           {
            for(loop_time=1;loop_time<=199;loop_time++)  //found another IDs
              {
               FP_EnrollStart(loop_time);
               if(return_ack == ACK)
                 break;
              }  
           }
        
        for(enroll_time=1;enroll_time<=3;enroll_time++)
          {
           Serial.print("Please press "),Serial.print(enroll_time),Serial.print(" time\n");  
           loop_time=1; 
           capture_success=0;
           while(1)     //waiting for time out
             {
              FP_CAPTUREFINGER(1);
              if(return_ack == ACK)
                 capture_success++;
        
              if(capture_success==2)  
                 break;
                      
              if(loop_time==40)
                {
                 Serial.print("Enroll:time out\n");
                 FP_LED_close();
                 return;
                }
              loop_time++; 
             }   
           
           if(enroll_time<3)
             {       
              FP_Enroll(enroll_time);
              if(return_ack != ACK)
                {
                 Serial.print("Enroll "),Serial.print(enroll_time),Serial.print(":fail!\n");
                 FP_LED_close();
                 return;
                }
             
              Serial.print("Take off finger\n");                
              while(1)   //waiting for taking off the finger
                {
                 FP_IsPressFinger();
                 if(return_para == 0x1012)   //finger is not pressed
                   break;
                }                    
             }
           else
              FP_Enroll(enroll_time);
          }
        
        if(return_ack == ACK)   //decide whether enroll ok or fail
          {
           Serial.print("Enroll Finish!\n");
           FP_LED_close();
          } 
        else 
          {
           if(return_para>=0 && return_para<=199)
             Serial.print("Duplicated Finger and enroll fail!\n");
           else 
             Serial.print("Enroll fail!\n");
           FP_LED_close();
          }           
       } //exit of enrollment
    
       if(choose_function=='2')   //Identify
         {
          actiune = 222;
      Wire.beginTransmission(SLAVE_ADDR2);
      Wire.write(actiune);
      Wire.endTransmission();
       Serial.print("--Identify processing--\n");  
       Serial.print("***Plase press your fingers***\n");
        FP_LED_open();
        if(return_ack != ACK)
         {
         Serial.print("LED_open:No ack and finish\n");
          FP_LED_close();
          return;  
         }
            
        loop_time=1;
        while(1)     //waiting timeout
         {
          delay(100);
          FP_CAPTUREFINGER(0);
          if(return_ack == ACK)
             break;
             
          if(loop_time==50)
            {
             Serial.print("Identify:time out and finish!\n");
             FP_LED_close();
             delay(500);
             return;
            }
          loop_time++;  
         }
         
        FP_Identify(); 
        if(return_ack == ACK)
         {
      actiune = 2;
      Wire.beginTransmission(SLAVE_ADDR2);
      Wire.write(actiune);
      Wire.endTransmission();
          Serial.print("Identify:OK,ID="),Serial.print(return_para),Serial.print("\n");
          FP_LED_close(); 
          delay(200);
         }
       else
         {
          Serial.print("Identify:Fail\n");
          FP_LED_close();
          delay(200);
         }  
       } // exit of identify

       if(choose_function=='3')   //Delete All
         {      
        Serial.print("--Delete All processing--\n");
        FP_DeleteAll();  //delete enrolled IDs  
        if(return_ack == ACK)
          Serial.print("DeleteAll:OK\n");
        else
          Serial.print("No template!\n");
       } //exit of Delete all
       if(choose_function=='4')   //Get user count
         {
          Serial.print("--Get User Count processing--\n");
          FP_GetEnrollCount();
          Serial.print("Enrolled user="),Serial.print(return_para),Serial.print("\n");
         }
      } //exit of input range
    else  //error handle of input error range
      Serial.print("Input error range!\n");   
} 
