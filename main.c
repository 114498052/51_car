# include "reg52.h"
# include "pwm.h"
# include "xunji.h"
# include "lcd1602.h"
# include "lanya.h"

uchar flag,i,receive;

uchar code table5[]="GO";
uchar code table6[]="Back";
uchar code table7[]="Left";
uchar code table8[]="Right";
uchar code table9[]="Stop";
uchar code table10[]="Xunji";

void main()
{
    lcd12864inti();
	  Usartinit();      //���ó�ʼ���������г�ʼ��
    display1();
    display2();
    display3();	
    display4();	
	while(1)
	{
      if(flag==1)     //���ϵļ���־λ�Ƿ���1  ����1˵���Ѿ�ִ�����жϷ�����򣬼��Ѿ������ݣ�����һֱ���flag��״̬
	  {  
        switch(receive)
		  { 
					case 1:   
								beep();     
								run();  
								ES=0;  //������Ҫ�������� ��ҪʹES=0�رմ����ж� �����ݷ�������ٴ򿪴����ж�
								for(i=0;i<2;i++)
									{
									SBUF=table5[i];
									while(!TI);   //�ȴ��Ƿ������    ��Ϊ������ɺ�TUI����Ӳ����1
									TI=0;	        //���������ɱ�־λ  �ֶ���0
								}	  	
								ES=1;				 
								flag=0;	  		
								break;
					case 2:   
								beep();    
								backrun(); 
								ES=0;
								for(i=0;i<4;i++)
								{
									SBUF=table6[i];
									while(!TI);
									TI=0;	
								}	   	
								ES=1;
								flag=0;	  	
								break;
					case 3:  
								beep(); 
								leftrun();	
								ES=0;
								for(i=0;i<4;i++)
									{
									SBUF=table7[i];
									while(!TI);
									TI=0;	
								}	  	
								ES=1;				 
								flag=0;	  		
								break;
					case 4:  
								beep();  
								rightrun();
								ES=0;
								for(i=0;i<5;i++)
								{
									SBUF=table8[i];
									while(!TI);
									TI=0;	
								}	 	
								ES=1;
								flag=0;	  	
								break;
					case 0:  
								beep();  
								stoprun(); 	
								ES=0;
								for(i=0;i<4;i++)
								{
									SBUF=table9[i];
									while(!TI);
									TI=0;	
								}		
								ES=1;							
								flag=0;
								break;
					case 5:  
						    beep();
						    while(1)
								{
								   xunji();  
								   if(receive==0)
									break;
								}
          }	  	 
       }
	  }
}
void Usart() interrupt 4 //һ�������ݽ��룬���п��жϴ���
{
   receive=SBUF-48;     //��RENΪ1ʱ  ��ʼ�������� �����յ���ֵ����receive   �������ACSII ����Ҫ��ȥ48
   RI=0;                //��RI=0   ���������ݴ���SBUF�Ĵ�����  ��������жϱ�־λ  ���ڲ�Ӳ����1����CPU�����ж����� ���жϷ�������У�����������������㣬 ȡ�����ж����� 
   flag=1;			    //����־λ��1  ����Ƿ������������в�ѯ�ж��Ƿ��Ѿ����յ�����
}




