# include "xunji.h"
# include "lcd1602.h"
# include "pwm.h"
# include "lanya.h"
uchar zhi_old = 0;//����Ѱ����־λ
void xunji()
{

	if((out1==1)&&(out2==0))   //1 Ϊ�� �к���
	     zhi_old=1;//������࣬������
	else if((out1==0)&&(out2==1))    
	     zhi_old=2;  //�����Ҳ࣬������   
	else if((out1==1)&&(out2==1))    //�������� 
	      zhi_old=0;             //�߲��ڷ�Χ�ڣ�����
	else if((out1==0)&&(out2==0))     //0 Ϊ��  û�к���
	      zhi_old=0;//�����ϣ�ֱ��
	
	if(zhi_old==0)
  {
	  if((out1==1)&&(out2==1)) run();	 //11
	  else if((out1==1)&&(out2==0)) leftrun();//10
	  else if((out1==0)&&(out2==1)) rightrun();//01
	  else if((out1==0)&&(out2==0)) stoprun();//00
	 // else  stoprun();
  }
  else if(zhi_old==1)  leftrun();
  else if(zhi_old==2)  rightrun();
	
}
//TCRT5000 �������ĺ��ⷢ������ܲ��Ϸ�������ߣ���������ĺ�����û�б���������򱻷��������ǿ�Ȳ�����ʱ������������һֱ���ڹض�״̬��
//��ʱģ��������Ϊ�ߵ�ƽ��ָʾ������һֱ����Ϩ��״̬��
//�������������ڼ�ⷶΧ��ʱ�������߱����������ǿ���㹻�󣬹��������ܱ��ͣ�
//��ʱģ��������Ϊ�͵�ƽ��ָʾ�����ܱ�������