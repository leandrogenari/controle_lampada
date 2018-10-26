//LEANDRO GENARI - leandro@inforgel.com.br
void serialclose(){
  //delay(10);
  Serial.end();
  Serial.begin(9600);
  
}
  
void setup(){
  
pinMode(13,OUTPUT);
pinMode(12,INPUT);
pinMode(11,OUTPUT);
pinMode(10,INPUT);

digitalWrite(10,LOW);
digitalWrite(11,LOW);

Serial.begin(9600);
  
  
}

int i=0;
int j=0;
int z=0;
int tempo=0; 
void loop(){

   //serialclose();
 
if (Serial.available()){
  
  j=0;
  z=0;
  
      switch (Serial.read()) {

    
              case '1' : {digitalWrite(11,HIGH);
                         //Serial.write("LIGADA  ");
                         i = 1;
                         break;}

              
              case '2' : {digitalWrite(11,HIGH);
                         i = 1;
                         while(!Serial.available()&& j <= 1200){
                         delay(250);
                         j = j + 1; Serial.println(j);}
                         if (j >=1200){
                         digitalWrite(11,LOW);
                         i = 0;
                         break;}
                         break;}         
             
             
             case '3' : {digitalWrite(11,HIGH);
                         i = 1;
                         //serialclose();
                         while (!Serial.available()){}
                         tempo = Serial.parseInt();
                         while(!Serial.available()&& z <= tempo){
                         delay(250);
                         z = z + 1; Serial.println(z);}
                         if (z >=tempo){
                         digitalWrite(11,LOW);
                         i = 0;
                         break;}
                         break;}         

              case '0' : {digitalWrite(11,LOW);
                         //Serial.write("DESLIGADA  "); 
                         i = 0;
                         break;}

              case '5' : {Serial.println(i); 
                          break;}

              default :  {break;} 

                  
                }


  }

}




