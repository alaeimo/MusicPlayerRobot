#include "Servo.h"

Servo Left_shoulder,Right_shoulder,Left_elbow,Right_elbow;
//1-Taab Taab:
int music1[] = {10, -1, 9, -1, 8, 8, 9, -1, 10, 9, 10, 9, 8, 8, 9, -1, -1, 3, -1, 2, -1, 1, 1, 2, -1, 3, 2, 3, 2,1,1, 2};   
//2-Khoneye MaadarBozorge:
int music2[] = {6, 6, 9, 9, -1, 6, 6, 9, 9, -1, 10, 9, 8, 10, -1, 9, 9, 9, -1, -1, 6, 6, 9, 9, -1, 6, 6, 9, 9, -1, 9, 10, 11, 12, -1, 13, 13, 13, -1, -1};
//3-Tavalodet Mobarak Shad:
int music3[] = {12, 12, 10, 11, -1, -1, 12, 12, 10, 11, -1, -1, 12, 12, 10, 12, 12, 10, 12, 12, 10, 11, -1, -1, 11, 11, 9, 10, -1, -1, 11, 11, 9, 10, -1, -1, 11, 11, 9, 11, 11, 9, 11, 11, 9, 10, -1, -1};
//4-Barf:
int music4[] = {10, 13, 10, 13, -1, 10, 10, 13, -1, 10, 11, 12, 13, -1, 14, 13, 12, -1, 10, 13, 10, 13, -1, 10, 10, 13, -1, 10, 11,12, 13, -1, 14, 14, 14,-1,-1}; 
//5-Khoshhal o Shad o Khandan:
int music5[] = {9,-1,-1,11,-1,-1,10,-1,11,10,-1,-1,9,-1,-1,11,-1,-1,10,-1,9,-1,-1,11,-1,-1,10,-1,-1,9,10,-1,-1,11,-1,-1,12,-1,-1,13,-1,-1};
//6-Tavalodet Mobarak:
int music6[] = {10,10,7,-1,10,10,7,-1,10,10,7,7,8,9,8,-1,10,10,8,-1,10,10,8,-1,10,10,9,9,8,8,7,-1,-1};
char angle[] = {53,60,67,73,83,93,103,45,55,64,72,82,93,103,112};
int *music;

void setup() 
{ 
  Left_shoulder.attach(3);
  Right_shoulder.attach(5);
  Left_elbow.attach(6);
  Right_elbow.attach(9);
  Left_shoulder.write(63);
  Right_shoulder.write(107);
  Left_elbow.write(90);
  Right_elbow.write(90);
  Serial.begin(9600);

} 

void loop() {
    int musicId = Read_Serial();
    int note_size ;
    if(musicId !=-1){
      if(musicId == 1){
        note_size = sizeof(music1)/sizeof(music1[0]);
        music = music1;
      }
      else if(musicId == 2){
        note_size = sizeof(music2)/sizeof(music2[0]);
        music = music2;
      }
      else if(musicId == 3){
        note_size = sizeof(music3)/sizeof(music3[0]);
        music = music3;
      }
      else if(musicId == 4){
        note_size = sizeof(music4)/sizeof(music4[0]);
        music = music4;
      }
      else if(musicId == 5){
        note_size = sizeof(music5)/sizeof(music5[0]);
        music = music5;
      }
      else if(musicId == 6){
        note_size = sizeof(music6)/sizeof(music6[0]);
        music = music6;
      }
      
      for(int i = 0;i<note_size;i++){
          int musicId = Read_Serial();
          Serial.println(musicId);
          if(musicId !=-1)
            break;
          else{
              if(music[i] == -1){
                delay(300);
              }else if(music[i]<7){
                 Left_shoulder.write(angle[music[i]]);
                 Serial.println(Left_shoulder.read());
                 delay(120);
                Left_elbow_shake();
             }else if(music[i]>=7){
                 Right_shoulder.write(angle[music[i]]);
                 Serial.println(Right_shoulder.read());
                 delay(120);
                 Right_elbow_shake();
              }
         }
      }
    }  
 }
 
int Read_Serial(){
   if (Serial.available() > 0) {
     String incomingString = Serial.readString();
     if(incomingString == "1")
        return 1;
     else if(incomingString == "2")
        return 2;
     else if(incomingString == "3")
        return 3;
     else if(incomingString == "4")
        return 4;
     else if(incomingString == "5")
        return 5;
     else if(incomingString == "6")
        return 6;
     else
        return 0;
   }
   else
      return -1;
 }
void Left_elbow_shake(){
  delay(60);
  Left_elbow.write(120); //down
  delay(60);
  Left_elbow.write(70); //up
  delay(60);
}
void Right_elbow_shake(){
  delay(60);
  Right_elbow.write(60); //down
  delay(60);
  Right_elbow.write(100); //up
  delay(60);
}

