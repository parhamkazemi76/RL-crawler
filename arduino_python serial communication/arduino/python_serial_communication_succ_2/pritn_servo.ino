void print_servo(double Servo_1, double Servo_2) {
  //    Serial.print(Servo_1);
  //    Serial.print("  ");
  //    Serial.println(Servo_2);
  //the function which you want to maximize

    while(1){
    if (ultrasonic() == 0){
    degreePos_1(Servo_1);
    degreePos_2(Servo_2);
    degreePos_1(0);
    degreePos_2(0);
    Serial.println(100*count);
    break;
      }
    }
}

    
    

  
  

 // double out = 1 + (Servo_1 * Servo_1) + (Servo_2 * Servo_2);
  //Serial.println(out , 7);

