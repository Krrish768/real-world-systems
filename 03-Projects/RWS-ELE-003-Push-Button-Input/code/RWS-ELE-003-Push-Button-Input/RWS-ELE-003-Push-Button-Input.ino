void setup()
{
    pinMode(8, INPUT_PULLUP);
  	pinMode(2, OUTPUT);
}
void loop()
{
  if(digitalRead(8) == LOW){
    digitalWrite(2, HIGH);
  }else{
    digitalWrite(2, LOW);
  }
}