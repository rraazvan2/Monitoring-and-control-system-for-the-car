//Includem libraria pentru i2c
#include <Wire.h>
#include <Keypad.h>
#include <DHT.h>
#include <SPI.h>
#include <RFID.h>
#include <SoftwareSerial.h>

SoftwareSerial sim(19, 18);

int _timeout;
String buffer;
String number = "0770919244"

//Includem libraria pentru lcdul prin i2c
#include <LiquidCrystal_I2C.h>

// Definim adresa 27 pentru lcd de 16 caractere pe 2 randuri prin i2c
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Includem libraria pentru receptorul de semnal al telecomenzi
#include <rm4.h>

//Definirea pinilor de imput receptor, fiecarui i se atribuite un buton de pe telecomanda(Pinnr0rm4 = A, Pinnr1rm4 = B, Pinnr2rm4 = C, Pinnr3rm4 = D)
static const int Pinnr0rm4 = 9;
static const int Pinnr1rm4 = 10;
static const int Pinnr2rm4 = 11;
static const int Pinnr3rm4 = 12;

// Initalizam modul rm4 pentru citire
RM4 remote(Pinnr0rm4, Pinnr1rm4, Pinnr2rm4, Pinnr3rm4);

//Definire adresa de slave pentru placuta cu nr. 2
#define SLAVE_ADDR 9

// Definire adresa de slave pentru placuta cu nr. 3
#define SLAVE_ADDR2 10

#define SLAVE_ADDR3 11

//Definim marimea raspunsului al placutei cu nr.2
#define ANSWRSIZE 5

//Definirea butoanelor pentru geamurile stanga si dreapta
#define BGD1 6 // Buton Geam deschidere dreapta
#define BGI1 7 // Buton Geam inchidere dreapta
#define BGD2 5 // Buton Geam deschidere stanga
#define BGI2 4 // Buton Geam inchidere stanga

//Constante schimbatoare, se folosesc pentru a seta pinul
#define USFS 32 // Usa soferului
#define UDFP 33 // Usa pasagerului
#define USSP 34 // Usa din spate a pasagerului stanga
#define UDSP 35 // Usa din spate a pasagerului dreapta

// Variabile care se vor schimba in timpul rulari programului
int VCBGD1 = 0; // Variabila pentru citirea butonului de la deschiderea geamului dreapta
int VCBGI1 = 0; // Variabila pentru citirea butonului de la inchiderea geamului dreapta
int VCBGD2 = 0; // Variabila pentru citirea butonului de la deschiderea geamului stanga
int VCBGI2 = 0; // Variabila pentru citirea butonului de la inchiderea geamului stanga

int VCUSFS = 0; // Variabila pentru citirea butonului de la usa soferului
int VCUDFP = 0; // Variabila pentru citirea butonului de la usa pasagerului
int VCUSSP = 0; // Variabila pentru citirea butonului de la usa spate stanga a pasagerului
int VCUDSP = 0; // Variabila pentruu citirea butonului de la usa spate dreapta a pasagerului


int actiune = 0; // Variabila care se va schimba in timpul rulari programului si se va transmite prin i2c la placuta nr. 2
int actiune2 = 0;
int val_bluetooth;
String str;
int alarmaon;
int autentificareok;
int ASVPloaie = 0;
int ASPA = 0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'a', 'b', 'c', 'd'},
  {'e', 'f', 'g', 'h'},
  {'i', 'j', 'k', 'l'},
  {'m', 'n', 'o', 'p'}
};
byte rowPins[ROWS] = {23, 22, 24, 25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {27, 28, 29, 30}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define Sploaie A8
#define DHTPIN 37
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define SS_PIN 53
#define RST_PIN 49
RFID rfid(SS_PIN, RST_PIN);
String rfidCard;
int valoare_analogica;


//--Counter for button A--//
int buttonPushCounterA = 0;
int buttonStateA = 0;
int lastButtonStateA = 0;

//--Counter for button B--//
int buttonPushCounterB = 0;
int buttonStateB = 0;
int lastButtonStateB = 0;

//--Counter for button C--//
int buttonPushCounterC = 0;
int buttonStateC = 0;
int lastButtonStateC = 0;

//--Counter for button D--//
int buttonPushCounterD = 0;
int buttonStateD = 0;
int lastButtonStateD = 0;
float h;
float t;
float f;
float hif;
float hic;
void setup() {

  Wire.begin(SLAVE_ADDR3);
  Wire.onReceive(receiveEvent);

  Serial.begin(9600); // Initializare port serial pentru comunicare cu placuta
  Serial1.begin(9600); // Initializare port serial pentru comunicarea cu modulul GSM
  Serial2.begin(9600); // Initializare port serial pentru comunicarea cu modulul Bluetooth

  pinMode(BGD1, INPUT);
  pinMode(BGI1, INPUT);
  pinMode(BGD2, INPUT);
  pinMode(BGI2, INPUT);

  pinMode(USFS, INPUT);
  pinMode(UDFP, INPUT);
  pinMode(USSP, INPUT);
  pinMode(UDSP, INPUT);
  pinMode(Sploaie, INPUT);

  dht.begin();
  SPI.begin();
  rfid.init();
  lcd.init();

}

void receiveEvent() {
  actiune2 = Wire.read();
}

void loop() {

    h = dht.readHumidity();
    t = dht.readTemperature();
    f = dht.readTemperature(true);
    hif = dht.computeHeatIndex(f, h);
    hic = dht.computeHeatIndex(t, h, false);

  if (val_bluetooth == 12) {

    ASVPloaie = 1;

  }
  if (val_bluetooth == 13) {

    ASVPloaie = 0;

  }
  if (val_bluetooth == 14) {

    ASPA = 1;

  }
  if (val_bluetooth == 15) {

    ASPA = 0;

  }

  bluetooth();
  geam();
}



void bluetooth() {
  while (Serial2.available()) {
    str = Serial2.readStringUntil('\n'); // variabila str stocheaza valorile primite de la aplicatia de pe mobil
    }
  val_bluetooth = (str.toInt()); // convertim variabila str -> int
   Serial.println(val_bluetooth);
}
