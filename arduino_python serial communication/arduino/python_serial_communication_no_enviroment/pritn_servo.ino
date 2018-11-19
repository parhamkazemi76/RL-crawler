void print_servo(double Servo_1, double Servo_2){
//    Serial.print(Servo_1);
//    Serial.print("  ");
//    Serial.println(Servo_2);
  //the function which you want to maximize
  
  double out = -10 + (Servo_1*Servo_1) + (Servo_2*Servo_2);
  Serial.println(out , 7);
}
