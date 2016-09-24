#define DATA 6
#define ST_CP 5
#define SH_CP 7

int tab[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};
void setup()
{
  pinMode(DATA, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);

}

void loop() {
for(int i=0;i<16;i++){
    digitalWrite(ST_CP, LOW);
    shiftOut(DATA, SH_CP, LSBFIRST, tab[i]);
    digitalWrite(ST_CP, HIGH);
    delay(500);
}
}
