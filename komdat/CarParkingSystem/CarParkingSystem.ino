#include <Servo.h> // mengimpor library servo yang digunakan untuk mengontrol motor servo yang menggerakkan pintu parkir
#include <Wire.h> // mengimpor library wire yang digunakan untuk komunikasi I2C
#include <LiquidCrystal_I2C.h> // mengimpor library LiquidCrystal_I2C yang digunakan untuk mengontrol LCD dengan menggunakan komunikasi I2C
LiquidCrystal_I2C lcd(0x27, 20, 4); // membuat objek lcd dari kelas LiquidCrystal_I2C dengan alamat I2C 0x27, dan ukuran 20 kolom dan 4 baris.

Servo myservo; // objek myservo dari kelas servo untuk mengontrol motor servo

#define ir_enter 2 // konstanta ir_enter dengan nilai 2, yang mewakili pin input untuk sensor masuk parkir
#define ir_back 4 // konstanta ir_back dengan nilai 4, yang mewakili pin input untuk sensor keluar parkir

#define ir_car1 5 // mendefinisikan konstanta ir_car1 dengan nilai 5, yang mewakili pin input untuk sensor mobil di slot 1
#define ir_car2 6 // mendefinisikan konstanta ir_car2 dengan nilai 6, yang mewakili pin input untuk sensor mobil di slot 2
#define ir_car3 7 // mendefinisikan konstanta ir_car3 dengan nilai 7, yang mewakili pin input untuk sensor mobil di slot 3
#define ir_car4 8 // mendefinisikan konstanta ir_car4 dengan nilai 8, yang mewakili pin input untuk sensor mobil di slot 4

int S1 = 0, S2 = 0, S3 = 0, S4 = 0; // variabel-variabel ini akan digunakan untuk menyimpan status keberadaan mobil di setiap slot
int flag1 = 0, flag2 = 0; // variabel-variabel ini digunakan sebagai penanda aksi yang sudah dilakukan
int slot = 4; // variabel ini akan menyimpan jumlah slot parkir yang tersedia

void setup() { // fungsi yang dieksekusi hanya sekali pada awal program, dalam fungsi ini dilakukan inisialisasi pin, pengaturan komunikasi serial, dan pengaturan awal LCD dan servo
  Serial.begin(9600);

  pinMode(ir_car1, INPUT);
  pinMode(ir_car2, INPUT);
  pinMode(ir_car3, INPUT);
  pinMode(ir_car4, INPUT);

  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);

  myservo.attach(3);
  myservo.write(90);

  lcd.begin(20, 4);
  lcd.setCursor(0, 1);
  lcd.print("    Car  Parking  ");
  lcd.setCursor(0, 2);
  lcd.print("       System     ");
  delay(500);
  lcd.clear();

  Read_Sensor();

  int total = S1 + S2 + S3 + S4;
  slot = slot - total;
}

void loop() { // fungsi yang dieksekusi secara berulang selama program berjalan, dalam fungsi ini dilakukan pembacaan sensor, pembaruan tampilan LCD, dan pengecekan input dari sensor masuk dan keluar parkir

  Read_Sensor();

  lcd.setCursor(0, 0);
  lcd.print("   Have Slot: ");
  lcd.print(slot);
  lcd.print("    ");

  lcd.setCursor(0, 1);
  if (S1 == 1) {
    lcd.print("S1:Fill ");
  } else {
    lcd.print("S1:Empty");
  }

  lcd.setCursor(10, 1);
  if (S2 == 1) {
    lcd.print("S2:Fill ");
  } else {
    lcd.print("S2:Empty");
  }

  lcd.setCursor(0, 2);
  if (S3 == 1) {
    lcd.print("S3:Fill ");
  } else {
    lcd.print("S3:Empty");
  }

  lcd.setCursor(10, 2);
  if (S4 == 1) {
    lcd.print("S4:Fill ");
  } else {
    lcd.print("S4:Empty");
  }

  if (digitalRead(ir_enter) == 0 && flag1 == 0) {
    if (slot > 0) { 
      flag1 = 1; 
      if (flag2 == 0) {
        myservo.write(180);
        slot = slot - 1;
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print(" Sorry Parking Full ");
      delay(1000);
    }
  }

  if (digitalRead(ir_back) == 0 && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo.write(180);
      slot = slot + 1;
    }
  }

  if (flag1 == 1 && flag2 == 1) {
    delay(1000);
    myservo.write(90);
    flag1 = 0, flag2 = 0;
  }

  delay(1);
}

void Read_Sensor() { // digunakan untuk membaca status sensor mobil di setiap slot parkir dan menyimpannya ke variabel S1, S2, S3, dan S4
  S1 = 0, S2 = 0, S3 = 0, S4 = 0;

  if (digitalRead(ir_car1) == 0) { S1 = 1; }
  if (digitalRead(ir_car2) == 0) { S2 = 1; }
  if (digitalRead(ir_car3) == 0) { S3 = 1; }
  if (digitalRead(ir_car4) == 0) { S4 = 1; }
}