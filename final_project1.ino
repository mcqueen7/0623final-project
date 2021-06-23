//設定各接腳

int latchPin = 10;
int clockPin = 12;
int dataPin = 11;
#define P 0
//#define A2 110
//#define B2 123
#define C3 131
//#define C3s 139
#define D3 147
//#define D3s 156
#define E3 165
#define F3 175
//#define F3s 185
#define G3 196
//#define G3s 208
#define AA3 220
//#define A3s 233
#define B3 247
#define C4 262
//#define D4 294
//#define E4 330

int led[5]={A0,A1,A2,A3,A4};
int Mdemoone[]={
  C3,P,C3,P,G3,P,G3,P,AA3,P,AA3,P,G3,G3,P,
  F3,P,F3,P,E3,P,E3,P,D3,P,D3,P,C3,C3,P
};
int Ldemoone[]={
 128,0,128,0,8,0,8,0,4,0,4,0,8,8,0,
  16,0,16,0,32,0,32,0,64,0,64,0,128,128,0
  
};


byte scan[8] = {
   B11111110,
   B11111101,
   B11111011,
   B11110111,
   B11101111,
   B11011111,
   B10111111,
   B01111111
}; //掃描
//int L=0 ;//Which picture
byte show[8] = {  //開機圖案
   B00100000,
   B01101110,
   B11001110,
   B10000000,
   B10000000,
   B11001110,
   B01101110,
   B00100000 
  

}; //圖案




byte pb1=0, bs1=0; 
byte pb2=0, bs2=0; 
byte pb3=0, bs3=0; 
byte pb4=0, bs4=0; 
byte pb5=0, bs5=0; 
byte pb6=0, bs6=0; 
byte pb7=0, bs7=0; 
byte pb8=0, bs8=0; 

void push(){ // 所以格子向右推進一格
  for(int i=7;i>0;i--){
   show[i]=show[i-1];
  }
  show[0]=0;
}
int di=0;
void demo(){  // 播放內建範例音樂
  if(di==30)di=0;
     push(); 
     tone(13,Mdemoone[di],300);
  show[0]=Ldemoone[di];
    di++;

}
void practice(){  //練習模式 不隨時間捲動
    bs1 = digitalRead(2);
    bs2 = digitalRead(3);
    bs3 = digitalRead(4);
    bs4 = digitalRead(5);
    bs5 = digitalRead(6);
    bs6 = digitalRead(7);
    bs7 = digitalRead(8);
    bs8 = digitalRead(9);
  if(bs1==0){
         push(); 
      tone(13,C3,300);
      show[0]=128;
    
   // delay(201);
  
    
      }
 
    else  if(bs2==0){
      push();
     tone(13,D3,300); 
      show[0]=64;
     
    //  delay(201);
      
      }
       
     
      else if(bs3==0){
        push();
     tone(13,E3,300); 
        show[0]=32;
       
      //  delay(202);
       
      }  
      else  if(bs4==0){
       push();
     tone(13,F3,300); 
        show[0]=16;
       
      //  delay(201);
      
      } 
     
      else  if(bs5==0){
       push();
     tone(13,G3,300); 
        show[0]=8;
       
    //    delay(201);
      
      }  
      
      else if(bs6==0){
       push();
     tone(13,AA3,300); 
        show[0]=4;
         
       // delay(201);
       
      }  
     else if(bs7==0){
       push();
     tone(13,B3,300);
        show[0]=2;
         
     //  delay(201);
      }  
  	else  if(bs8==0){
       push();
   	  tone(13,C4,300);
       show[0]=1;
         
     // delay(200);
      
      }  
  

}
void play(){      //演奏模式 隨時間捲動
    bs1 = digitalRead(2);
    bs2 = digitalRead(3);
    bs3 = digitalRead(4);
    bs4 = digitalRead(5);
    bs5 = digitalRead(6);
    bs6 = digitalRead(7);
    bs7 = digitalRead(8);
    bs8 = digitalRead(9);
  if(bs1==0){
         push(); 
      tone(13,C3,300);
      show[0]=128;
    
   // delay(201);
  
    
      }
 
    else  if(bs2==0){
      push();
     tone(13,D3,300); 
      show[0]=64;
     
    //  delay(201);
      
      }
       
     
      else if(bs3==0){
        push();
     tone(13,E3,300); 
        show[0]=32;
       
      //  delay(202);
       
      }  
      else  if(bs4==0){
       push();
     tone(13,F3,300); 
        show[0]=16;
       
      //  delay(201);
      
      } 
     
      else  if(bs5==0){
       push();
     tone(13,G3,300); 
        show[0]=8;
       
    //    delay(201);
      
      }  
      
      else if(bs6==0){
       push();
     tone(13,AA3,300); 
        show[0]=4;
         
       // delay(201);
       
      }  
     else if(bs7==0){
       push();
     tone(13,B3,300);
        show[0]=2;
         
     //  delay(201);
      }  
  	else  if(bs8==0){
       push();
   	  tone(13,C4,300);
       show[0]=1;
         
     // delay(200);
      
      }  
   	else {
 	 tone(13,P,300); 
      push();
     // delay(201);
      
 	 }

}


long ntime=0,ptime=0;
byte ms=0,mp=0;
byte nowmode=0;
int Mrecorder[60]={0};    // 錄製彈奏音樂空間
int Lrecorder[60]={0};    // 錄製彈奏圖片空間
byte rt=0;
void record(){    //錄製模式 可錄製18秒 
    bs1 = digitalRead(2);
    bs2 = digitalRead(3);
    bs3 = digitalRead(4);
    bs4 = digitalRead(5);
    bs5 = digitalRead(6);
    bs6 = digitalRead(7);
    bs7 = digitalRead(8);
    bs8 = digitalRead(9);
  if(bs1==0){
         push(); 
      tone(13,C3,300);
      show[0]=128;
     Mrecorder[rt]=C3;
     Lrecorder[rt]=128;
   // delay(201);
      }
 
    else  if(bs2==0){
      push();
     tone(13,D3,300); 
      show[0]=64;
       Mrecorder[rt]=D3;
       Lrecorder[rt]=64;
    //  delay(201);
      
      }
       
     
      else if(bs3==0){
        push();
     tone(13,E3,300); 
        show[0]=32;
         Mrecorder[rt]=E3;
       Lrecorder[rt]=32;
      //  delay(202);
       
      }  
      else  if(bs4==0){
       push();
       tone(13,F3,300); 
       show[0]=16;
       Mrecorder[rt]=F3;
       Lrecorder[rt]=16;
       
      //  delay(201);
      
      } 
     
      else  if(bs5==0){
       push();
     tone(13,G3,300); 
        show[0]=8;
         Mrecorder[rt]=G3;
     Lrecorder[rt]=8;
    //    delay(201);
      
      }  
      
      else if(bs6==0){
       push();
     tone(13,AA3,300); 
        show[0]=4;
           Mrecorder[rt]=AA3;
     Lrecorder[rt]=4;
       // delay(201);
       
      }  
     else if(bs7==0){
       push();
     tone(13,B3,300);
        show[0]=2;
         Mrecorder[rt]=B3;
     Lrecorder[rt]=2;
         
     //  delay(201);
      }  
  	else  if(bs8==0){
       push();
   	  tone(13,C4,300);
       show[0]=1;
           Mrecorder[rt]=C4;
     Lrecorder[rt]=1;
     // delay(200);
      
      }  
   	else {
 	 tone(13,P,300); 
      push();
     // delay(201);
       Mrecorder[rt]=P;
     Lrecorder[rt]=0;
 	 }


 rt++;
  if(rt==60){   // 超過18秒自動切換為撥放模式
  nowmode++;
    rt=0;
    digitalWrite(led[3],LOW);
    digitalWrite(led[4],HIGH);
   
  }

}

byte ri=0;
void playrecord(){    //播放模式 循環播放
if(ri==60)ri=0;  
     push(); 
     tone(13,Mrecorder[ri],300);
  show[0]=Lrecorder[ri];
    ri++;


}
void  check(){  //檢查時間是否到達蜂鳴器必要delay time 
  ms = digitalRead(A5);
  if(ms==0&&mp==1){    //模式按鈕
   nowmode++;
    ri=0;  //playrecord mode reset
    rt=0;  //record mode reset
    di=0;  //medo mode reset
    if(nowmode==5)nowmode=0;
    mp=0;
    digitalWrite(led[((nowmode+4)%5)],LOW);
    digitalWrite(led[nowmode],HIGH);
  }
  if(ms==1)mp=1;
  
ntime=millis();

  if(ntime-ptime>=310){     //依當前模式執行
    switch(nowmode){
     case 0: practice(); break;//不會捲動
     case 1: play(); break;		//會捲動
     case 2: demo();break;		//撥範例曲
     case 3: record();break;	//錄製
     case 4: playrecord();break;//播放錄製的
    
    }
     ptime=millis();
   
  }
}  

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
   pinMode(2,INPUT_PULLUP);
   pinMode(3,INPUT_PULLUP);
   pinMode(4,INPUT_PULLUP);
   pinMode(5,INPUT_PULLUP);
   pinMode(6,INPUT_PULLUP);
   pinMode(7,INPUT_PULLUP);
   pinMode(8,INPUT_PULLUP);
   pinMode(9,INPUT_PULLUP);
   pinMode(A5,INPUT_PULLUP);
   pinMode(A4,OUTPUT);
   pinMode(A3,OUTPUT);
   pinMode(A2,OUTPUT);
   pinMode(A1,OUTPUT);
   pinMode(A0,OUTPUT);
  digitalWrite(A0,HIGH);

}

void loop() {

   for(int i = 0; i < 8 ; i++){
     
     check();
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, scan[i]);
    shiftOut(dataPin, clockPin, LSBFIRST, show[i]);
    digitalWrite(latchPin,HIGH);
     
   delay(3);
  }

delay(300); //解決模擬器延遲問題測試用

}