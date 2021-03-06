#include "Wire.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

//Only for 128x32 OLED Displays (Will push a dynamic code in future)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define LOGO_HEIGHT   4
#define LOGO_WIDTH    4
 

int frame_delay =800;

 const int NUMFLAKES = 1000;
 int8_t f=0; 
 int8_t icons[NUMFLAKES][3];
 int rad=0;
 int a, b, c, d;
int rnd = random(17, 110);

  // We Wish You a Merry Christmas
  // Score available at https://musescore.com/user/6208766/scores/1497501

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0



#define XPOS   0 // Indexes into the 'icons' array in function below
#define YPOS   1


// change this to make the song slower or faster
int tempo = 140;

// change this to whichever pin you want to use
int buzzer = 4;

int melody[] = {


  
  NOTE_C5,4, //1
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,

  NOTE_F5,2, NOTE_C5,4, //8 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,

  NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,//17
  NOTE_E5,2, NOTE_E5,4,
  NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
  NOTE_C5,2, NOTE_A5,4,
  NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
  NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4, 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, //27
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,
  NOTE_F5,4, NOTE_F5,4, NOTE_F5,4,
  NOTE_E5,2, NOTE_E5,4,
  NOTE_F5,4, NOTE_E5,4, NOTE_D5,4,
  
  NOTE_C5,2, NOTE_A5,4,//36
  NOTE_AS5,4, NOTE_A5,4, NOTE_G5,4,
  NOTE_C6,4, NOTE_C5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4, 
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8, 
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,//45
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, //53
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, REST,4
};

 static unsigned long notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
 static unsigned long wholenote = (60000 * 4) / tempo;

 static unsigned long divider = 0;
 static unsigned long noteDuration = 0;

// 'blackBG(old)1', 128x32px
const unsigned char epd_bitmap_blackBG_old_1 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 
  0x00, 0xe0, 0x19, 0x9e, 0x79, 0xf3, 0x61, 0xec, 0xdf, 0x3c, 0xf7, 0xd9, 0x8e, 0x3c, 0x0e, 0x00, 
  0x00, 0x60, 0x19, 0x9e, 0x79, 0xf3, 0x63, 0xec, 0xdf, 0x3d, 0xf7, 0xdd, 0x9f, 0x7c, 0x06, 0x00, 
  0x00, 0x00, 0x1f, 0x98, 0x79, 0xb3, 0x63, 0x8c, 0xdb, 0x19, 0xc1, 0x9f, 0x9f, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x1f, 0x9e, 0x79, 0xf3, 0x63, 0x8f, 0xdf, 0x19, 0xf1, 0x9f, 0x9b, 0x7c, 0x00, 0x00, 
  0x00, 0x60, 0x1f, 0x9e, 0x7d, 0xfb, 0xc3, 0x8f, 0xdf, 0x98, 0xf1, 0x9f, 0x9f, 0x3c, 0x06, 0x00, 
  0x00, 0xa0, 0x19, 0x98, 0x6d, 0x99, 0xc3, 0x8c, 0xd9, 0x98, 0x31, 0x99, 0x9f, 0x0c, 0x0a, 0x00, 
  0x01, 0xb0, 0x19, 0x9e, 0x6d, 0x99, 0x83, 0xec, 0xd9, 0xbd, 0xf1, 0x99, 0x9b, 0x7c, 0x1b, 0x00, 
  0x03, 0xf8, 0x19, 0x9e, 0x6d, 0x99, 0x81, 0xec, 0xd9, 0xbd, 0xf1, 0x99, 0x9b, 0x7c, 0x3f, 0x80, 
  0x01, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x00, 
  0x01, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x00, 
  0x03, 0xe8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x80, 
  0x06, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0xc0, 
  0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf0, 
  0x03, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0xc0, 
  0x03, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xc0, 
  0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xe0, 
  0x0c, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xce, 0x70, 
  0x3c, 0xf7, 0x80, 0x00, 0x00, 0x01, 0xdc, 0x62, 0x43, 0x24, 0xc0, 0x00, 0x00, 0x03, 0xcf, 0x78, 
  0x3f, 0xff, 0x80, 0x00, 0x00, 0x03, 0xde, 0xf7, 0xc7, 0xbd, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xf8, 
  0x01, 0x98, 0x00, 0x00, 0x00, 0x03, 0x16, 0xd7, 0xc7, 0xbc, 0xc0, 0x00, 0x00, 0x00, 0x19, 0x80, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x9e, 0xd7, 0xc7, 0xbc, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x60, 0x00, 0x00, 0x00, 0x03, 0x16, 0xf6, 0x47, 0xb5, 0xe0, 0x00, 0x00, 0x00, 0x06, 0x00, 
  0x00, 0x60, 0x00, 0x00, 0x00, 0x03, 0x16, 0xf6, 0x46, 0xb5, 0xe0, 0x00, 0x00, 0x00, 0x06, 0x00, 
  0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 6864)


void setup() {
  Serial.begin(9600);
 // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
 if(!display.begin(SSD1306_SWITCHCAPVCC)) {
   Serial.println(F("SSD1306 allocation failed"));
   for(;;); 
 }

 display.display();
 delay(2000); 
 //testdrawbitmap();
 display.display();
 delay(2000); 
 //testdrawbitmap();
 display.clearDisplay();

 display.clearDisplay();  
          display.drawBitmap(0,0,epd_bitmap_blackBG_old_1, 128, 32, 0);
          display.display();
          
          display.drawBitmap(0,0,epd_bitmap_blackBG_old_1, 128, 32, 1);
          display.display();



 int n=0;
        for (static unsigned long thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {


               //------------------------ R E S E T ---------------------------
               
                rst();
               display.display();
               
              //------------------------S N O W F L A K E S---------------------------
                
                 snowflakes();
                 display.display();
               
              //----------------------------------------------------------- 
               
   
                // calculates the duration of each note
                divider = melody[thisNote + 1];
                if (divider > 0) {
                  // regular note, just proceed
                  noteDuration = (wholenote) / divider;
                } else if (divider < 0) {
                  // dotted notes are represented with negative durations!!
                  noteDuration = (wholenote) / abs(divider);
                  noteDuration *= 1.5; // increases the duration in half for dotted notes
                }
            
                // we only play the note for 90% of the duration, leaving 10% as a pause
                tone(buzzer, melody[thisNote], noteDuration * 0.9);
            
                // Wait for the specief duration before playing the next note.
                delay(noteDuration);
            
                // stop the waveform generation before the next note.
                noTone(buzzer);
        }
}

void loop() {
  // no need to repeat the melody.
}

void rst(){
                 display.fillCircle(15, 12, 2, 0);          
               display.fillCircle(15, 5, 2, 0);
               display.fillCircle(15, 28, 2, 0);

               display.fillCircle(rnd, 17, 2, 0);
               
               display.fillCircle(25, 20, 2, 0);

               display.fillCircle(50, 17, 2, 0);
               display.fillCircle(50, 30, 2, 0);
               
               display.fillCircle(75, 15, 2, 0);
               
               display.fillCircle(90, 15, 2, 0);
               display.fillCircle(90, 28, 2, 0);
               
               display.fillCircle(110, 5, 2, 0);
               display.fillCircle(110, 28, 2, 0);
               
               display.fillCircle(125, 8, 2, 0);
               display.fillCircle(125, 29, 2, 0);
  }

void snowflakes(){
   display.fillCircle(15, 12, random(0,3) , random(-2,2));
                 display.fillCircle(15, 5, random(0,2) , random(-2,2));
                 display.fillCircle(15, 28, random(0,2) , random(-2,2));
                 
                 display.fillCircle(rnd , 17, random(0,2) , random(-2,2));
                 
                 display.fillCircle(25, 20, random(0,2) ,random(-2,2));

                 display.fillCircle(50, 17, random(0,2) ,random(-2,2));
                 display.fillCircle(50, 30, random(0,2) ,random(-2,2));
                 
                 display.fillCircle(75, 15, random(0,2), random(-2,2));
                 
                 
                 display.fillCircle(90, 15, random(0,2), random(-2,2));
                 display.fillCircle(90, 28, random(0,2), random(-2,2));

                 display.fillCircle(110, 5, random(0,2), random(-2,2));
                 display.fillCircle(110, 28, random(0,2), random(-2,2));

                 display.fillCircle(125, 8, random(0,2), random(-2,2));
                 display.fillCircle(125, 29, random(0,2), random(-2,2));
  
  }
