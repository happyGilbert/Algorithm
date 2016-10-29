#include<stdio.h>
 
#define ABS(X) ((X)>0? (X):(-1)*(X))

void main()
{
	int length1, length2, destination, lengthTemp, minStep;  //ָ����������length1��length2��ָ���յ�destination��minStepΪ��length1��length2���мӼ�����ɵõ�����С���ȡ� 
	int length1Copy, length2Copy;                            //����length1��length2 
	int mlength1, mlength2;                                  //�ֱ��ʾlength1��length2����length1��length2�����Լ�������ֵ�� 
	int minuendParamLen1, minuendParamLen2, subtrahendParamLen1, subtrahendParamLen2, differenceParamLen1, differenceParamLen2; 
	//���ڼ�¼��������б�������������������length1��length2����ֵ��ϵ�����磺minuend = minuendParamLen1 * length1 + minuendParamLen2 * length2�� 
	printf("Please input length1: ");
	scanf("%d", &length1);
	printf("Please input length2: ");
	scanf("%d", &length2);
	printf("Please input destination: ");
	scanf("%d", &destination);
	if((length1 < 0) || (length2 < 0) || ((length1 == 0) && (length2 == 0)))
	{
		printf("\nError! length must be great than or equal to 0 and cannot be zero at the same time!\n\n");
		system("pause");
		return;
	}
	
	length1Copy = length1;
	length2Copy = length2;
	
	minuendParamLen1 = 1;         //����length1 > length2, ���ʼ������Ϊlength2������Ϊlength2. 
	minuendParamLen2 = 0;
	subtrahendParamLen1 = 0;
	subtrahendParamLen2 = 1;
	
	if(length1 < length2)        //���length1 < length2, �򽻻�length1��length2��ֵ�������³�ʼ������Ϊԭlength2������Ϊԭlength1. 
	{
		lengthTemp = length1;
		length1 = length2;
		length2 = lengthTemp;
		
		minuendParamLen1 = 0;
		minuendParamLen2 = 1;
		subtrahendParamLen1 = 1;
		subtrahendParamLen2 = 0;
		
	}
	
	mlength1 = length1;
	mlength2 = length2;
	while(mlength2 != 0)       //��ȡlength1��length2���Լ��. 
	{
		lengthTemp = mlength1 % mlength2;
		mlength1 = mlength2;
		mlength2 = lengthTemp;
	}
	mlength2 = length2Copy / mlength1;  //��ȡlength1��length2Լȥ���Լ������ֵ. 
	mlength1 = length1Copy / mlength1;
	
	minStep = length1;                  //��ʼ��minStepΪlength1������ߣ�����length1=length2����length2=0������£�minStep����Ϊlength1��������length1��length2�Ĺ�ϵ�뱻����һ�¡� 
	differenceParamLen1 = minuendParamLen1;
	differenceParamLen2 = minuendParamLen2;
	
	while((length1 > length2) && (length2 != 0)) //��length1=length2����length2=0��������������㣬��С����minStep��Ϊlength1. 
	{
		lengthTemp = length1 - length2;          //��length1��length2�Ĳ 
		
		differenceParamLen1 = minuendParamLen1 - subtrahendParamLen1; //���²�����length1��length2����ֵ��ϵ�� 
		differenceParamLen2 = minuendParamLen2 - subtrahendParamLen2;
		
		if(lengthTemp > length2)  //���������ڼ������򽫲�����ֵ���������������±�������length1��length2����ֵ��ϵ��
		{
			length1 = lengthTemp;
			
			minuendParamLen1 = differenceParamLen1;
			minuendParamLen2 = differenceParamLen2;
		}
		else if(length2 > lengthTemp)  //������С�ڼ������򽫼�����ֵ����������������ֵ�������������±�������������length1��length2����ֵ��ϵ�� 
		{
			length1 = length2;
			length2 = lengthTemp; 
			
			minuendParamLen1 = subtrahendParamLen1;
			minuendParamLen2 = subtrahendParamLen2;
			subtrahendParamLen1 = differenceParamLen1;
			subtrahendParamLen2 = differenceParamLen2;
		}
		else                  //�����������ȣ��õ�length1��length2�Ӽ������ɵõ�����С���ȣ�Ϊ�������߼����� 
		{
			minStep = lengthTemp;
			break;
		}
	}
	if((destination % minStep) == 0) //���յ���ֵ�ɱ���С���ȣ����յ����(destination / minStep)����С���ȵ�����õ��� 
	{
		differenceParamLen1 *= (destination / minStep);
		differenceParamLen2 *= (destination / minStep);
		
		//����ϵ��differenceParamLen1��differenceParamLen2. destination = differenceParamLen1 * length1 + differenceParamLen2 * length2.
		// mlength2 * length1 = mlength1 * length2. ʹ��ʽ������С��mlength1��mlength2Ϊlength1��length2Լȥ���Լ�����ֵ. 
		//destination = (differenceParamLen1 +/- mlength2) * length1 + (differenceParamLen2 -/+ mlength1)* length2
		//�����沽����ȡ��differenceParamLen1��differenceParamLen2��Ϊһ��һ�����������㣩��
		//������������ϵ��������С��ֵ��ϵ������ֵ����С�����򻯼򡣼���֤Ŀ���ʽdestination�������ɽ�������С���������� 
		if((differenceParamLen1 > 0) && (differenceParamLen2 < 0))
 		{
			while((ABS(differenceParamLen1) + ABS(differenceParamLen2)) > 
 				  (ABS(differenceParamLen1 - mlength2) + ABS(differenceParamLen2 + mlength1)))
 			{
 				differenceParamLen1 -= mlength2;
 			    differenceParamLen2 += mlength1;
 			}
 		}
 		if((differenceParamLen1 < 0) && (differenceParamLen2 > 0))
 		{
 			while((ABS(differenceParamLen1) + ABS(differenceParamLen2)) > 
 				  (ABS(differenceParamLen1 + mlength2) + ABS(differenceParamLen2 - mlength1)))
 			{
 				differenceParamLen2 -= mlength1;
 			    differenceParamLen1 += mlength2;
 			}
 		}		
		
		
		printf("\nYes!, The destination can be reached!\nDestination: %d.   Length1: %d.   Length2: %d.\n",
		              destination, length1Copy, length2Copy);
		printf("The minimum step is: Destination = (%d) * Length1 + (%d) * Length2!\n\n", differenceParamLen1, differenceParamLen2);
	}
	else
	{
		printf("\nNo!, The destination can't be reached!\n\n");
	}
	system("pause");
 } 
