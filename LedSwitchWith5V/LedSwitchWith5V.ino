
#define RED 2
#define BLEU 8
#define YELOW 9
#define SwitchR 6
#define SwitchB 5
#define SwitchY 4
#define SwitchALL 3
#define i 50
void setup() {
  
pinMode(RED,OUTPUT);
pinMode(SwitchR, INPUT); 
pinMode(BLEU,OUTPUT);
pinMode(SwitchB, INPUT); 
pinMode(YELOW,OUTPUT);
pinMode(SwitchY, INPUT); 
pinMode(SwitchALL, INPUT); 
   
}

void loop() {
       
        if ( digitalRead(SwitchR) == HIGH ) 
        {                   
            digitalWrite(RED,HIGH);
             digitalWrite(YELOW,LOW); 
            digitalWrite(BLEU,LOW);
                         
        } 
        if( digitalRead(SwitchB) == HIGH ) 
        {                   
            digitalWrite(BLEU,HIGH); 
            
              digitalWrite(YELOW,LOW); 
            digitalWrite(RED,LOW);           
        } 
         if( digitalRead(SwitchY) == HIGH ) 
        {                   
           digitalWrite(RED,LOW);
             digitalWrite(YELOW,HIGH); 
            digitalWrite(BLEU,LOW);
         
                        
        } 
        if( digitalRead(SwitchALL) == HIGH ) 
        {                   
            digitalWrite(YELOW,HIGH); 
            digitalWrite(RED,HIGH);  
            digitalWrite(BLEU,HIGH);
     
               
        } 
         else
        {                   
            digitalWrite(YELOW,LOW); 
            digitalWrite(RED,LOW);  
            digitalWrite(BLEU,LOW);
     
               
        } 
}
