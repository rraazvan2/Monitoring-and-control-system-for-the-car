#define FP_RX               10 // RX(white line)
#define FP_TX               11 // TX(Green line)

#define COMMAND_PACKAGE_LENGTH 12  
#define COMMAND_START_CODE1  0x55
#define COMMAND_START_CODE2  0xAA

#define DEVICE_ID            0x0001

#define OPEN                 0x01  
#define CMOSLED              0x12
#define GETENROLLCOUNT       0x20
#define ENROLLSTART          0x22
#define ENROLL1              0x23
#define ENROLL2              0x24
#define ENROLL3              0x25
#define ISPRESSFINGER        0x26
#define DELETEALL            0x41
#define IDENTIFY             0x51
#define CAPTURE_FINGER       0x60
#define GETTEMPLATE          0x70
#define SETTEMPLATE          0x71
#define ACK                  0x30
#define NACK                 0x31

typedef struct {    
  unsigned char Head1;         
  unsigned char Head2;         
  unsigned short wDevId;        
  unsigned long nParam;          
  unsigned short wCmd;          
  unsigned short wChkSum;       
} COMMAND_PACKAGE_STRUCTURE;

COMMAND_PACKAGE_STRUCTURE command_package; 

unsigned long return_para;   
unsigned short return_ack;    
