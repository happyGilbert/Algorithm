 #include<stdio.h>
 
 #define ABS(X) ((X)>0? (X):(-1)*(X))

 void main()
 {
 	int paramA, paramB, paramC;  //�������A��B��C, �����ɸ�����. ��������в���A��B�Ծ���ֵ|A|��|B|�������㣬����ٵ���ϵ��X��Y����. 
 	int mParamA, mParamB;        //�ֱ��ʾ����|A|��|B|����|A|��|B|�����Լ������ֵ.
 	int paramACopy, paramBCopy, paramTemp, paramMin; //paramACopy, paramBCopy���ݲ���A��B��paramTempΪ����ʹ�õ����м������paramMinΪ����|A|��|B|շת�����ɻ�õ���С����.
 	int minuendCoefficientWithParamA, minuendCoefficientWithParamB;        //��¼�����������|A|��|B|����ֵ�����ϵ. 
 	int subtrahendCoefficientWithParamA, subtrahendCoefficientWithParamB;  //��¼���������|A|��|B|����ֵ�����ϵ. 
 	int differenceCoefficientWithParamA, differenceCoefficientWithParamB;  //��¼���������|A|��|B|����ֵ�����ϵ. 
 	
 	printf("*******************************************************************");
 	printf("\nThis program is used to calculate X and Y with C = A * X + B * Y.\n");
 	printf("Where A, B, C are both input parameters and are integers,\nAnd the solution will make |X| + |Y| is minimal!\n");
 	printf("*******************************************************************");
 	
 	printf("\n\nPlease input parameter A(integer): ");
 	scanf("%d", &paramA);
 	printf("Please input parameter B(integer): ");
 	scanf("%d", &paramB);
 	printf("Please input parameter C(integer): ");
 	scanf("%d", &paramC);
 	if((paramA == 0) && (paramB == 0))         //����A��B��Ϊ0�������жϴ��� 
 	{
 		if(paramC == 0)
 		{
 			printf("\nYes!, the answer is exist!");
 			printf("\nInput parameters:   A: 0,  B: 0,  C: 0.");
 			printf("\nOutput parameters:  X: 0,  Y: 0.");
 			printf("\nThe solution is:  (0) = (0) * (0) + (0) * (0)!\n\n");
 		}
 		else
 		{
 			printf("\nNo! The answer is not exist!\n\n");
 		}
 		system("pause");
 		return;
 	}
 	paramACopy = paramA;                      //���ݲ���A��B 
 	paramBCopy = paramB;

 	if(paramA < 0)  paramA *= -1;             //��ȥ����A��B���ţ�ȡ�����ֵ�� 
 	if(paramB < 0)  paramB *= -1;
 	if(paramA == 0)                           //�������|A|>|B|, �򱻼���ȡΪ|A|������ȡΪ|B|�����±����������������|A|��|B|����ֵ�����ϵ. 
 	{
 		minuendCoefficientWithParamA = 0;
 		minuendCoefficientWithParamB = 0;
 	}
 	else
 	{
 		minuendCoefficientWithParamA = 1;
 		minuendCoefficientWithParamB = 0;
	}
 	
 	if(paramB == 0)
 	{
 		subtrahendCoefficientWithParamA = 0;
 		subtrahendCoefficientWithParamB = 0;
 	}
 	else
 	{
 		subtrahendCoefficientWithParamA = 0;
 		subtrahendCoefficientWithParamB = 1;
	}

 	if(paramA < paramB)                    //������|A|<|B|���򽻻�|A|��|B|����ͬ�����±�������������ԭ����|A|��|B|����ֵ�����ϵ 
 	{
 		paramTemp = paramA;
 		paramA = paramB;
 		paramB = paramTemp;

 		paramTemp = minuendCoefficientWithParamA;
 		minuendCoefficientWithParamA = subtrahendCoefficientWithParamA;
 		subtrahendCoefficientWithParamA = paramTemp;
 		paramTemp = minuendCoefficientWithParamB;
 		minuendCoefficientWithParamB = subtrahendCoefficientWithParamB;
 		subtrahendCoefficientWithParamB = paramTemp;
 	}

 	mParamA = paramA;
 	mParamB = paramB;

 	while(mParamB != 0)                   //��ȡ����|A|��|B|�����Լ��. 
 	{
 		paramTemp = mParamA % mParamB;
 		mParamA = mParamB;
 		mParamB = paramTemp; 
 	}

 	mParamB = ABS(paramBCopy) / mParamA;  //��ȡԭ����|A|��|B|����������С��Լ�������ֵ.
 	mParamA = ABS(paramACopy) / mParamA;

 	paramMin = paramA;     //��ʼ����С����Ϊ|A|�������²�����|A|��|B|����ֵ�����ϵ. ��|A|=|B|����|B|=0ʱ����С������Ϊ|A|����Ӧ��ֵ�����ϵ��Ϊ����������ֵ�����ϵ. 
 	differenceCoefficientWithParamA = minuendCoefficientWithParamA;
 	differenceCoefficientWithParamB = minuendCoefficientWithParamB;
 	
 	while((paramA > paramB) && (paramB != 0)) //��|A|=|B|����|B|=0ʱ����С���ȼ�Ϊ|A|����Ӧ��ֵ�����ϵ��Ϊ����������ֵ�����ϵ, ����������. 
 	{
 		paramTemp = paramA - paramB;          //�����|A|-|B|�������²�����|A|��|B|�����ϵ.

 		differenceCoefficientWithParamA = minuendCoefficientWithParamA - subtrahendCoefficientWithParamA;
 		differenceCoefficientWithParamB = minuendCoefficientWithParamB - subtrahendCoefficientWithParamB;
 		if(paramTemp > paramB)                //���������ڼ������򽫲�����ֵ���������������±�������|A|��|B|�������ϵ. 
 		{
 			paramA = paramTemp;

 			minuendCoefficientWithParamA = differenceCoefficientWithParamA;
 			minuendCoefficientWithParamB = differenceCoefficientWithParamB;
 		}
 		else if(paramTemp < paramB)           //������С�ڼ������򽫼�����ֵ����������������ֵ�������������±�������������|A|��|B|�������ϵ.
 		{
 			paramA = paramB;
 			paramB = paramTemp;

 			minuendCoefficientWithParamA = subtrahendCoefficientWithParamA;
 			minuendCoefficientWithParamB = subtrahendCoefficientWithParamB;
 			subtrahendCoefficientWithParamA = differenceCoefficientWithParamA;
 			subtrahendCoefficientWithParamB = differenceCoefficientWithParamB;
 		}
 		else                                //���������ڼ��������ȡ����С��ֵ(|A|��|B|շת�������ɵõ�����С����).��Ϊ����(���߼���).��С������|A|��|B|�������ϵ��Ϊ�����������ϵ. 
 		{
 			paramMin = paramTemp;
 			break;
 		}
 	}
 	if((paramC % paramMin) == 0)              //��Ŀ�����ɱ���С������������Ŀ��������(paramC / paramMin)����С������|A|��|B|�������ϵ��á� 
 	{
 		differenceCoefficientWithParamA *= (paramC / paramMin);
 		differenceCoefficientWithParamB *= (paramC / paramMin);

        //����ϵ��differenceCoefficientWithParamA��differenceCoefficientWithParamB. C = differenceCoefficientWithParamA * |A| + differenceCoefficientWithParamB * |B|.
		// mParamB * |A| = mParamA * |B|. ʹ��ʽ������С��mParamA��mParamBΪ|A|��|B|Լȥ���Լ�����ֵ. 
		//C = (differenceCoefficientWithParamA +/- mParamB) * |A| + (differenceCoefficientWithParamB -/+ mParamA)* |B|
		//�����沽����ȡ��differenceCoefficientWithParamA��differenceCoefficientWithParamB��Ϊһ��һ�����������㣩��
		//��ϵ����ϵ������ֵ����С�ķ��򻯼򡣼���֤Ŀ���ʽC�������ɽ�������С����������
 		if((differenceCoefficientWithParamA > 0) && (differenceCoefficientWithParamB < 0))
 		{
			while((ABS(differenceCoefficientWithParamA) + ABS(differenceCoefficientWithParamB)) > 
 				  (ABS(differenceCoefficientWithParamA - mParamB) + ABS(differenceCoefficientWithParamB + mParamA)))
 			{
 				differenceCoefficientWithParamA -= mParamB;
 			    differenceCoefficientWithParamB += mParamA;
 			}
 		}
 		if((differenceCoefficientWithParamA < 0) && (differenceCoefficientWithParamB > 0))
 		{
 			while((ABS(differenceCoefficientWithParamA) + ABS(differenceCoefficientWithParamB)) > 
 				  (ABS(differenceCoefficientWithParamA + mParamB) + ABS(differenceCoefficientWithParamB - mParamA)))
 			{
 				differenceCoefficientWithParamB -= mParamA;
 			    differenceCoefficientWithParamA += mParamB;
 			}
 		}

        //����A��B�ķ��ŵ���differenceCoefficientWithParamA��differenceCoefficientWithParamB�ķ��ţ�ʹC��ʽ�Գ���.
		//������|differenceCoefficientWithParamA| + |differenceCoefficientWithParamB|��С. 
 		if(paramACopy < 0) differenceCoefficientWithParamA *= -1;
 		if(paramBCopy < 0) differenceCoefficientWithParamB *= -1;
 		printf("\nYes!, The answer is exist!");
 		printf("\nInput parameters:   A: %d,  B: %d,  C: %d.", paramACopy, paramBCopy, paramC);
 		printf("\nOutput parameters:  X: %d,  Y: %d.", differenceCoefficientWithParamA, differenceCoefficientWithParamB);
 		printf("\nThe solution is:  (%d) = (%d) * (%d) + (%d) * (%d)!\n\n", paramC, differenceCoefficientWithParamA, paramACopy, differenceCoefficientWithParamB, paramBCopy);
 	}
 	else
 	{
 		printf("\nNo! The answer is not exist!\n\n");
 	}
 	system("pause");
  } 
