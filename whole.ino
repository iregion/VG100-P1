#define v1 5
#define v2 6
#define s 7   // 1 for black
#define h1 9
#define h2 10
int n = 0;
bool start = false;
bool finish = false;
void setup() {
  pinMode(s,INPUT);  
}  
  
void loop() {
  int startsensor = digitalRead(s);
  if (start == false && startsensor == 0)
  {
    start = true;
    lift();
    go();
   }
  if (start == true && finish == false)
  {
    if (go() > 10)
    {
    down();
    finish = true;
    }
    }
}
void lift()
{
  analogWrite(v1,0);
  analogWrite(v2,255);
  delay(3200);
  analogWrite(v1,0);
  analogWrite(v2,0);
  }
int go()
{
  int gosensor = digitalRead(s);
  if (gosensor == 1)
  {
   analogWrite(h1,0);
   analogWrite(h2,0);
   delay(10);
   n++;
    }
  else
  {
   analogWrite(h1,0);
   analogWrite(h2,255);
   n = 0;
    }
    return n;
  }
void down()
{
  analogWrite(v1,255);
  analogWrite(v2,0);
  delay(3000);
  analogWrite(v1,0);
  analogWrite(v2,0);
  }
void acceler()
{
  int a;
  for (a = 150; a <= 255; a += 5)
   analogWrite(h1,0);
   analogWrite(h2,a);
   delay(40);
  }
