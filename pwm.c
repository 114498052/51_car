# include "pwm.h"
#include "lcd1602.h"
#define Left_moto_go{IN1=1,IN2=0,EN1=1;} 
#define Left_moto_back{IN1=0,IN2=1,EN1=0;}
#define Left_moto_Stop{EN1=0;}
#define Right_moto_go{IN3=1,IN4=0,EN2=1;}
#define Right_moto_back{IN3=0,IN4=1,EN2=0;} 
#define Right_moto_Stop{EN2=0;}

bit Right_moto_stop=1;
bit Left_moto_stop =1;

uchar pwm_val_left=0;   //�������
uchar push_val_left=0;  //����ռ�ձ�ΪN/20
uchar pwm_val_right=0;
uchar push_val_right=0; //�ҵ��ռ�ձ�ΪN/20

uint time=0;

void run(void)
{ 
		push_val_left=15;   
		push_val_right=15;  
		Left_moto_go; 
		Right_moto_go; 
}
void run1(void)
{ 
		push_val_left=10; 
		push_val_right=10; 
	  Left_moto_go; 
		Right_moto_go; 
}


void leftrun(void)
{
		push_val_left=5; 
		push_val_right=15; 
		Left_moto_back; 
		Right_moto_go;
}
void leftrun1(void)
{
		push_val_left=3; 
		push_val_right=8; 
		Left_moto_back; 
		Right_moto_go;
}
void rightrun(void)
{
		push_val_left=15; 
		push_val_right=5;
		Left_moto_go; 
		Right_moto_back;
}
void rightrun1(void)
{
		push_val_left=8; 
		push_val_right=3;
		Left_moto_go; 
		Right_moto_back;
}
void stoprun(void)
{
		push_val_left=0; 
		push_val_right=0; 
		Left_moto_Stop; 
		Right_moto_Stop;
	
}
void backrun(void)
{
		push_val_left=10; 
		push_val_right=10; 
		Left_moto_back;
		Right_moto_back; 
}
void pwm_out_left_moto(void)  //��������ת��  �������PWM
{ 
			if(Left_moto_stop)    //�������ֹͣ
			  {
					 if(pwm_val_left<=push_val_left)  
						 {
						   Left_moto_pwm=1;   
						 }
					 else 
						{
							 Left_moto_pwm=0; 
						}
					 if(pwm_val_left>=20)
						pwm_val_left=0;
			  }
			else 
			{
			    Left_moto_pwm=0; 
			}
}
void pwm_out_right_moto(void)
{ 
		if(Right_moto_stop)
		{ 
		  if(pwm_val_right<=push_val_right)
		   {
		     Right_moto_pwm=1; 
		   }
		  else 
		   {
		     Right_moto_pwm=0; 
		   }
		  if(pwm_val_right>=20)
		     pwm_val_right=0;
		}
		else 
		{
		   Right_moto_pwm=0; 
		}
}
/*TIMER0�жϷ���������PWM�ź�*/
void timer0 ()interrupt 1
{
		TH0=0XEC;     //5ms��ʱ    
		TL0=0X78;  
		time++;
		pwm_val_left++;
		pwm_val_right++;
		pwm_out_left_moto();
		pwm_out_right_moto();
}

