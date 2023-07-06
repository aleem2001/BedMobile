int flag;
void main() {

ANSELA= 0;
ANSELB= 0;
ANSELC= 0;
ANSELD= 0;
TRISC= 0;
PORTC= 0;
TRISB= 0;
PORTB= 0;
TRISA= 0;
PORTA= 0;
TRISD= 0;
PORTD= 0;
PWM1_Start();
PWM2_Start();
PWM3_Init(50000);
PWM3_Start();
PWM4_Start();


UART1_init(9600);
flag = 0;


while(1){

UART1_Data_Ready() == 1;

   if(UART1_Read()== '8'||UART1_Read()== '7'||UART1_Read()== '6'||UART1_Read()== '9') // MAX SPEED
     {
       flag = 1;
     }
     else if(UART1_Read()== '3' || UART1_Read()== '2'|| UART1_Read()== '1'|| UART1_Read()== '4') // SLOW SPEED
     {
      flag = -1;
     }



   if(UART1_Read()== 'F') // forward
   {
       if (flag == 1)
     {
       PWM1_Set_Duty(255);
       PWM2_Set_Duty(255);
     }
     else if(flag == -1)
     {
       PWM1_Set_Duty(155);
       PWM2_Set_Duty(155);
     }
       else
     {
       PWM1_Set_Duty(0);
       PWM2_Set_Duty(0);
     }
       PORTC.b0= 0;          // LEFT NEGATIVE IN3
       PORTC.b1= 1;          // LEFT POSITIVE IN4
       PORTC.b2= 1;          // RIGHT NEGATIVE IN1
       PORTC.b3= 0;          // RIGHT POSITIVE IN2
       PORTD.b1= 1;          // LEFT FORWARD LED
       PORTD.b2= 1;          // RIGHT FORWARD LED
   }

   else if(UART1_Read()== 'B') // BACKWARD
   {
       PWM1_Set_Duty(0);
       PWM2_Set_Duty(0);
       PORTC.b0= 1;
       PORTC.b1= 0;
       PORTC.b2= 0;
       PORTC.b3= 1;
       PORTD.b3= 1;          // LEFT BACKWARD LED
       PORTD.b4= 1;          // RIGHT BACKWARD LED
   }
   else if(UART1_Read()== 'L') // LEFT
   {
       PWM1_Set_Duty(255);
       PWM2_Set_Duty(0);
       PORTC.b0= 1;
       PORTC.b1= 0;
       PORTC.b2= 1;
       PORTC.b3= 0;
   }
   else if(UART1_Read()== 'R') // RIGHT
   {
       PWM1_Set_Duty(0);
       PWM2_Set_Duty(255);
       PORTC.b0= 0;
       PORTC.b1= 1;
       PORTC.b2= 0;
       PORTC.b3= 1;
   }
   else if(UART1_Read()== 'I') // FORWARD RIGHT
   {
        if (flag == 1)
     {
       PWM1_Set_Duty(0);            //right tyre pwm1
       PWM2_Set_Duty(255);
     }
     else if(flag == -1)
     {
       PWM1_Set_Duty(0);
       PWM2_Set_Duty(155);
     }
       else
     {
       PWM1_Set_Duty(0);
       PWM2_Set_Duty(0);
     }
       PORTC.b0= 0;
       PORTC.b1= 1;
       PORTC.b2= 0;
       PORTC.b3= 0;
       PORTD.b1= 1;          // LEFT FORWARD LED
       PORTD.b2= 1;          // RIGHT FORWARD LED
   }
   else if(UART1_Read()== 'G') // FORWARD LEFT
   {
    if (flag == 1)
     {
       PWM1_Set_Duty(255);            //right tyre pwm1
       PWM2_Set_Duty(0);
     }
     else if(flag == -1)
     {
       PWM1_Set_Duty(155);
       PWM2_Set_Duty(0);
     }
       else
     {
       PWM1_Set_Duty(0);
       PWM2_Set_Duty(0);
     }
       PORTC.b0= 0;
       PORTC.b1= 0;
       PORTC.b2= 1;
       PORTC.b3= 0;
       PORTD.b1= 1;          // LEFT FORWARD LED
       PORTD.b2= 1;          // RIGHT FORWARD LED
   }
    else if(UART1_Read()== 'J') // BACKWARD RIGHT
   {
       PWM1_Set_Duty(0);
       PWM2_Set_Duty(0);

       PORTC.b0= 1;
       PORTC.b1= 0;
       PORTC.b2= 0;
       PORTC.b3= 0;
       PORTD.b3= 1;          // LEFT BACKWARD LED
       PORTD.b4= 1;          // RIGHT BACKWARD LED
   }
   else if(UART1_Read()== 'H') // BACKWARD LEFT
   {
       PWM1_Set_Duty(0);
       PWM2_Set_Duty(0);

       PORTC.b0= 0;
       PORTC.b1= 0;
       PORTC.b2= 0;
       PORTC.b3= 1;
       PORTD.b3= 1;          // LEFT BACKWARD LED
       PORTD.b4= 1;          // RIGHT BACKWARD LED
   }
   else if(UART1_Read()== 'W') // HEAD UP START
   {
       PWM4_Set_Duty(1);
       PORTB.b0= 1;
       PORTB.b1= 0;
       PORTB.b2= 0;
       PORTB.b3= 0;
   }
   else if(UART1_Read()== 'w') // HEAD UP STOP
   {
       PWM4_Set_Duty(0);
       PORTB.b0= 0;
       PORTB.b1= 0;
       PORTB.b2= 0;
       PORTB.b3= 0;
   }
   
   else if(UART1_Read()== 'U') // HEAD DOWN START
   {
       PWM4_Set_Duty(1);
       PORTB.b0= 0;
       PORTB.b1= 1;
       PORTB.b2= 0;
       PORTB.b3= 0;
   }
   else if(UART1_Read()== 'u') // HEAD DOWN STOP
   {
       PWM4_Set_Duty(0);
       PORTB.b0= 0;
       PORTB.b1= 0;
       PORTB.b2= 0;
       PORTB.b3= 0;
   }
   
   else if(UART1_Read()== 'V') // FOOT UP START
   {
       PWM3_Set_Duty(1);
       PORTB.b0= 0;
       PORTB.b1= 0;
       PORTB.b2= 0;
       PORTB.b3= 1;
   }
   else if(UART1_Read()== 'v') // FOOT UP STOP
   {
       PWM3_Set_Duty(0);
       PORTB.b0= 0;
       PORTB.b1= 0;
       PORTB.b2= 0;
       PORTB.b3= 0;
   }
   
   else if(UART1_Read()== 'X') // FOOT DOWN START
   {
       PWM3_Set_Duty(1);
       PORTB.b0= 0;
       PORTB.b1= 0;
       PORTB.b2= 1;
       PORTB.b3= 0;
   }
   else if(UART1_Read()== 'x') // FOOT DOWN STOP
   {
       PWM3_Set_Duty(0);
       PORTB.b0= 0;
       PORTB.b1= 0;
       PORTB.b2= 0;
       PORTB.b3= 0;
   }
   
   else// if(UART1_Read()== 'D') // stop all
   {
       PWM1_set_Duty(0);
       PWM2_Set_Duty(0);
       PWM3_Set_Duty(0);
       PWM4_Set_Duty(0);
       LATC= 0b00000000;
       LATD= 0b00000000;
   }
}

}