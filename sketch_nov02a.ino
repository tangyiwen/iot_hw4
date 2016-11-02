#define led_pin 11
#define fsr_pin A0

int greenPin = 10;
int redPin = 11;
int bluePin = 9;

int counter = 0;//狀態切換

void setup()
{
Serial.begin(9600);
pinMode(fsr_pin, INPUT);
pinMode(greenPin,OUTPUT);
pinMode(redPin,OUTPUT);
pinMode(bluePin,OUTPUT);
}
void loop()
{
int fsr_value = analogRead(fsr_pin); // 讀取FSR
int led_value = map(fsr_value, 0, 1000, 0, 255); // 從0~1023映射到0~255
Serial.println(fsr_value);
counter++;
if(counter == 1){//紅綠同時點亮，產生黃色
analogWrite(greenPin,led_value);
analogWrite(redPin,led_value);
analogWrite(bluePin,0);
}
else if(counter == 2){//藍紅同時點亮，產生紫色
analogWrite(greenPin,0);
analogWrite(redPin,led_value);
analogWrite(bluePin,led_value);
}
else if(counter == 3){//藍綠同時點亮，產生青色
analogWrite(greenPin,led_value);
analogWrite(redPin,0);
analogWrite(bluePin,led_value);
counter = 0;
}
delay(1000);
}
