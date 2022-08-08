void geam() {
  VCBGD1 = digitalRead(BGD1);
  VCBGI1 = digitalRead(BGI1);
  VCBGD2 = digitalRead(BGD2);
  VCBGI2 = digitalRead(BGI2);
  VCUSFS = digitalRead(USFS);
  VCUDFP = digitalRead(UDFP);
  VCUSSP = digitalRead(USSP);
  VCUDSP = digitalRead(UDSP);
  char key = keypad.getKey();
  valoare_analogica = analogRead(Sploaie);
  const int button_code = remote.buttonCode();

  /////////////////////////////////////////////////////////////////////////////////
  //-------------------- Counter for button A------------------------------------//
  buttonStateA = (button_code == 8);
  // compare the buttonState or it's previous state
  if (buttonStateA != lastButtonStateA)
  { // if the state has changed, increment the counter
    if (buttonStateA == HIGH)
    {
      buttonPushCounterA++;
    }
    // Delay a little bit to avoid bouncing
    delay(1);
  }
  // save the current state as the last state, for next time throguht the loop
  lastButtonStateA = buttonStateA;
  ///////////////////////////////////////////////////////////////////////////////
  //-------------------- Counter for button B------------------------------------//
  buttonStateB = (button_code == 2);
  // compare the buttonState or it's previous state
  if (buttonStateB != lastButtonStateB)
  { // if the state has changed, increment the counter
    if (buttonStateB == HIGH)
    {
      buttonPushCounterB++;
    }
    // Delay a little bit to avoid bouncing
    delay(1);
  }
  // save the current state as the last state, for next time throguht the loop
  lastButtonStateB = buttonStateB;
  ///////////////////////////////////////////////////////////////////////////////
  //-------------------- Counter for button C------------------------------------//
  buttonStateC = (button_code == 4);
  // compare the buttonState or it's previous state
  if (buttonStateC != lastButtonStateC)
  { // if the state has changed, increment the counter
    if (buttonStateC == HIGH)
    {
      buttonPushCounterC++;
    }
    // Delay a little bit to avoid bouncing
    delay(1);
  }
  // save the current state as the last state, for next time throguht the loop
  lastButtonStateC = buttonStateC;
  ///////////////////////////////////////////////////////////////////////////////
  //-------------------- Counter for button D------------------------------------//
  buttonStateD = (button_code == 1);
  // compare the buttonState or it's previous state
  if (buttonStateD != lastButtonStateD)
  { // if the state has changed, increment the counter
    if (buttonStateD == HIGH)
    {
      buttonPushCounterD++;
    }
    // Delay a little bit to avoid bouncing
    delay(1);
  }
  // save the current state as the last state, for next time throguht the loop
  lastButtonStateD = buttonStateD;
  ///////////////////////////////////////////////////////////////////////////////

  if (VCBGD1 == HIGH || val_bluetooth == 1 || key != NO_KEY && key == 'f') {
    actiune = 6;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Deschidere");
    lcd.setCursor(0, 1);
    lcd.print("Geam 1");
    delay(500);
    actiune = 160;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    

  } else if (VCBGI1 == HIGH || val_bluetooth == 2 || key != NO_KEY && key == 'e') {

    actiune = 5;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Inchidere");
    lcd.setCursor(0, 1);
    lcd.print("Geam 1");
    delay(500);
    actiune = 160;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();

  } else if (VCBGD2 == HIGH || val_bluetooth == 3 || key != NO_KEY && key == 'g') {

    actiune = 8;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Inchidere");
    lcd.setCursor(0, 1);
    lcd.print("Geam 2");
    delay(500);
    actiune = 160;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();

  } else if (VCBGI2 == HIGH || val_bluetooth == 4 || key != NO_KEY && key == 'h') {

    actiune = 7;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Deschidere");
    lcd.setCursor(0, 1);
    lcd.print("Geam 2");
    delay(500);
    actiune = 160;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();

  } else if (VCUSFS == HIGH) {

    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Usa Sofer");
    lcd.setCursor(0, 1);
    lcd.print("Deschisa");

  } else if (VCUDFP == HIGH) {

    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Usa Fata Sofer");
    lcd.setCursor(0, 1);
    lcd.print("Deschisa");

  } else if (VCUSSP == HIGH) {

    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Usa Stanga Spate");
    lcd.setCursor(0, 1);
    lcd.print("Deschisa");

  } else if (VCUDSP == HIGH) {

    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Usa Dreapta Spate");
    lcd.setCursor(0, 1);
    lcd.print("Deschisa");

  } else if (key != NO_KEY && key == 'a' || button_code == 2 || val_bluetooth == 5) {

    actiune = 4;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DESCHIDERE");
    lcd.setCursor(0, 1);
    lcd.print("PORTBAGAJ");

  } else if (key != NO_KEY && key == 'b' || button_code == 4 || val_bluetooth == 6) {

    actiune  = 3;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Inchidere");
    lcd.setCursor(0, 1);
    lcd.print("Portbagaj");


  } else if (key != NO_KEY && key == 'c') {

    actiune = 1;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ALARM IN CAR");
    lcd.setCursor(0, 1);
    lcd.print("ON");

  } else if (key != NO_KEY && key == 'd') {

    actiune = 2;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ALARM IN CAR");
    lcd.setCursor(0, 1);
    lcd.print("OFF");

  } else if (key != NO_KEY && key == 'i' || buttonPushCounterD == 3 || val_bluetooth == 10) {

    actiune = 9;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Inchide");
    lcd.setCursor(0, 1);
    lcd.print("Geam 1 & 2");
    delay(750);
    actiune = 0;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    

  } else if (key != NO_KEY && key == 'j' || buttonPushCounterA == 2 || val_bluetooth == 9) {

    actiune = 10;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Deschide");
    lcd.setCursor(0, 1);
    lcd.print("Geam 1 & 2");
    delay(2000);
    actiune = 0;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    

  } else if (key != NO_KEY && key == 'k' && autentificareok == 1 || val_bluetooth == 19) {

    actiune = 11;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BORD ON");
    delay(750);
    

  } else if (key != NO_KEY && key == 'l' || val_bluetooth == 20 && autentificareok == 0) {

    actiune = 12;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("BORD OFF");
    delay(750);
    

  } else if (key != NO_KEY && key == 'm' || val_bluetooth == 17) {
    actiune = 13;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ON Faruri");
    delay(750);
    

  } else if (key != NO_KEY && key == 'n' || val_bluetooth == 18) {

    actiune = 14;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();   
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OFF Faruri");
    delay(750);
    

  } else if (key != NO_KEY && key == 'p' || val_bluetooth == 16) {

    actiune = 16;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Porneste");
    lcd.setCursor(0, 1);
    lcd.print("Alarma");
    delay(750);
    

  } else if (rfid.isCard()) {

    if (rfid.readCardSerial()) {
      rfidCard = String(rfid.serNum[0]) + " " + String(rfid.serNum[1]) + " " + String(rfid.serNum[2]) + " " + String(rfid.serNum[3]);
      Serial.println(rfidCard);
      if (rfidCard == "101 133 241 33") {

        autentificareok = 1;
        lcd.backlight();
        lcd.display();
        lcd.clear();
        lcd.setCursor(6, 0);
        lcd.print("ACCES");
        lcd.setCursor(7, 1);
        lcd.print("OK");

      } else {

        autentificareok = 0;
        lcd.backlight();
        lcd.display();
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("ACCES");
        lcd.setCursor(4, 1);
        lcd.print("REFUZAT");
        delay(500);

      }
    }
    rfid.halt();
  } else if (valoare_analogica < 1000 && ASVPloaie == 1) {


    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ploua, Inchidere");
    lcd.setCursor(0, 1);
    lcd.print(" automata?");
    delay(500);

  } else if (valoare_analogica < 800 && ASPA == 1) {

    actiune = 2;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    buttonPushCounterD = 0;
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Inchidere");
    lcd.setCursor(0, 1);
    lcd.print(" automata ON");
    delay(500);

  } else if (button_code == 8 || val_bluetooth == 8) { // Buton B

    actiune = 2;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alarma OFF");
    delay(500);

  } else if (button_code == 1 || val_bluetooth == 7) { // Buton A


     actiune = 1;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    buttonPushCounterA = 0;
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alarma ON");
    delay(500);
    lcd.noBacklight();

  }else if (button_code == 2 || val_bluetooth == 7) { // deschide portbagaj

    actiune = 4;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    buttonPushCounterD = 0;
    buttonPushCounterA = 0;
    autentificareok = 0;
    delay(500);
    actiune = 444;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();

  }else if (button_code == 4 || val_bluetooth == 6) { // inchidere portbagaj

    actiune = 3;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    buttonPushCounterA = 0;
    delay(500);
    actiune = 444;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();

  } else if (buttonPushCounterD == 2 || val_bluetooth == 11 || key != NO_KEY && key == 'o') { // Buton C

    actiune = 15;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    lcd.backlight();
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alarma");
    lcd.setCursor(0, 1);
    lcd.print("silentioasa ON");
    delay(500);
    lcd.noBacklight();

  } else if(val_bluetooth == 23){

    Serial2.println(t);
    delay(2000);
    
  } else if(val_bluetooth == 24){

    Serial2.println(h);
    delay(2000);
    
  } else {
     delay(2000);

    actiune = 155;
    Wire.beginTransmission(SLAVE_ADDR);
    Wire.write(actiune);
    Wire.endTransmission();
    
    lcd.display();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("H: ");
    lcd.print(h);
    lcd.setCursor(0, 1);
    lcd.print("T: ");
    lcd.print(t);
    lcd.print(" *C ");

  }

}
