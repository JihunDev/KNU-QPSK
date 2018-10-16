#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void main(){
	FILE *ip1, *op1,*op2,*op3,*op4,*op5,*op6,*op7,*op8,*op9;
	float t,qpsk,fc,Ts,s[51],noise,dummy,
		  mi, mq,mip,mqp,sit,sqt,ss[50],smi,smq;
	int i,j;
	Ts=1./100.;
	fc=5;
	dummy=0;
	ip1=fopen("gn.dat","r");
	op1=fopen("mip.dat","w");
	op2=fopen("mqp.dat","w");
	op3=fopen("sit.dat","w");
	op4=fopen("sqt.dat","w");
	op5=fopen("qpsk.dat","w");
	op6=fopen("smi.dat","w");
	op7=fopen("smq.dat","w");
	op8=fopen("mi.dat","w");
	op9=fopen("mq.dat","w");

	for(j=0;j<=30;j++) s[j]=0.0;
	for(j=0;j<=30;j++) ss[j]=0.0;
	srand((unsigned)time(NULL));
	mi=rand()%2;

	if(mi>=1) mi=1;
	else mi=-1;
	mq=mi;

	for(i=0; i<=1999;i++)
	{
		t= i*Ts;
		if(i%50 !=0) dummy=dummy;
		else
		{	
		mi=rand()%2;
		if(mi>=1)mi=1;
		else mi=-1;

		mq=rand()%2;
		if(mq>=1)mq=1;
		else mq=-1;

	}
	
	s[1]=mi;
	mip=0.;

	for(j=1;j<=20;j++)
	{	
	   mip+=s[j];  
	}
	smi = mip/20.;
	fscanf(ip1,"%f",&noise);
	mip=mip/20.+noise*0.05;
	
	ss[1]=mq;
	mqp=0.;
	
	for(j=1;j<=20;j++)
	{	
	   mqp+=ss[j]; 
	}
	smq=mqp/20.;
	fscanf(ip1,"%f",&noise);

	mqp=mqp/20.+noise*0.05;
	
	
	sit= mip*cos(2*3.14*fc*t);
	sqt= mqp*sin(2*3.14*fc*t);

	qpsk = sit +sqt;
	
	fprintf(op1,"%f\n",mip);
	fprintf(op2,"%f\n",mqp);
	fprintf(op3,"%f\n",sit);
	fprintf(op4,"%f\n",sqt);
	fprintf(op5,"%f\n",qpsk);
	fprintf(op6,"%f\n",smi);
	fprintf(op7,"%f\n",smq);	
	fprintf(op8,"%f\n",mi);
	fprintf(op9,"%f\n",mq);

	for(j=20;j>=2;j--) s[j]=s[j-1];
	for(j=20;j>=2;j--) ss[j]=ss[j-1];
	}
fclose(op1);
fclose(op2);
fclose(op3);
fclose(op4);
fclose(op5);
fclose(op6);
fclose(op7);

fclose(ip1);
return;

}