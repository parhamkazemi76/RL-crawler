float string_to_double(String S){
//  Serial.print(S);
//  Serial.print("  ");
  int dot = -1 ;
  int e = -1;
  double num = 0;
  for (int i = 0; i < S.length(); i++){
        if (S[i] == '.'){
          dot = i;
        }
        if (S[i] == 'e'){
          e = i;
        }
      }
      
   if (dot > 0){
    for (int i = 0; i < dot; i++){
      long power = 1 ;
      for (int j = i; j < dot -1 ; j++){
         power = power * 10;
      }
      num = num + (int(S[i])-48) * power;
      
    }
    if (e > 0){
      for (int i = dot + 1; i < e; i++){
        float power = 1 ;
        for (int j = 0; j < i - dot; j++){
          power = power / 10 ;
        }
        num = num + (int(S[i])-48) * power;
      }
      if (S[e+1] == '-'){
        long power = 1 ;
        int e_power = 0;
        for (int i = e + 2; i < S.length(); i++){
          for (int j = i; j < S.length()-1 ; j++){
            power = power * 10;
          }
          e_power = e_power + (int(S[i])-48) * power ;
//          Serial.print(e_power);
//          Serial.print("  ");
        }
        num = num * pow(10,-e_power);
      }
      if (S[e+1] == '+'){
        long power = 1 ;
        int e_power = 0;
        for (int i = e + 2; i < S.length(); i++){
          for (int j = i; j < S.length()-1 ; j++){
            power = power * 10;
          }
          e_power = e_power + (int(S[i])-48) * power ;
//          Serial.print(e_power);
//          Serial.print("  ");
          
        }
        num = num * pow(10,e_power);
      }
    }
    if (e < 0) {
      for (int i = dot + 1; i < S.length(); i++){
        float power = 1 ;
        for (int j = 0; j < i - dot; j++ ){
          power = power / 10 ;
        }
        num = num + (int(S[i])-48) * power;
      }
   }  
  }
  if(dot < 0){
    for (int i = 0; i < S.length(); i++){
      long power = 1;
      for (int j = i; j < S.length()-1; j++){
        power = power * 10;
      }
      num = num + (int(S[i])-48) * power;
    }
  }
//  Serial.println(num);
  return(num); 
}

