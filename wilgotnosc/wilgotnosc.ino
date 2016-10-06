/*
 Name:		wilgotnosc.ino
 Created:	10/5/2016 10:43:40 PM
 Author:	phobos
*/

int dioda = 13;			// notyfikacja, kiedy wilgotno
int czujnik = 3;		// czujnik wilgotnosci
int wilgotnosc = 0;		// liczba / 0.0049V =~ napiecie na wyjsciu czujnika

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(dioda, OUTPUT);
	pinMode(czujnik, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	wilgotnosc = analogRead(czujnik);
	if (wilgotnosc > 700)
	{
		digitalWrite(dioda, HIGH);		// zalaczy sie pompka
	}
	else if (wilgotnosc < 700)
	{
		digitalWrite(dioda, LOW);		// wylaczy sie pompka
	}
	Serial.print("Wilgotnosc = ");
	Serial.print(wilgotnosc);
	Serial.print("\r\n");
	delay(1000);
}
