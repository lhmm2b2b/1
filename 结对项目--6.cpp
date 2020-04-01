#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct count
{
 int num[4]; //运算数
 char sign[3];//运算符
 int amount;//运算符个数
 double answer;//表达式的结果
}count[10000];

double q[10000];

int random(int n)//生成随机数
{
 int a;
 a=rand()%n+1;
 return a;
}

char symbol( )//生成随机符号
{
 char fh[4]={'+','-','x','/'};
 return fh[rand()%4];
}

double solution(int j)//计算表达式结果并判断合法要求
{
 int a=count[j-1].amount;
 int num0=count[j-1].num[0],num1=count[j-1].num[1],num2=count[j-1].num[2],num3=count[j-1].num[3]; 
 char sign0=count[j-1].sign[0],sign1=count[j-1].sign[1],sign2=count[j-1].sign[2]; 
 double x=-1,y =0;

 if(a==1)
 {
  if(sign0=='/'&&num0>=num1)  return -1;//判断

  switch (sign0) 
  {
   case '+' : x=num0+num1;break;
   case '-' : x=num0-num1;break;
   case 'x' : x=num0*num1;break;
   case '/' : x=(double)num0/num1;break;
   default : return -1;
  }
 }
 
 else if(a==2)
{
 if(((sign1=='x')||(sign1=='/'))&&((sign0=='+')||(sign0=='-')))
 {
  if(sign1=='/'&&num1>=num2)  return -1;//判断

  switch (sign1) 
  {
   case 'x' : x=num1*num2;break;
   case '/' : x=(double)num1/num2;break;
   default : return -1;
  }
  switch (sign0) 
  {
   case '+' : x=x+num0;break;
   case '-' : x=num0-x;break;
   default : return -1;
  }
 }
 else 
 {
  if(sign0=='/')//判断
  {
   if((sign1=='+'||sign1=='-')&&num0>=num1)  return -1;
   if(sign1=='x'&&num0*num2>=num1)  return -1;
   if(sign1=='/'&&num0>=num1*num2)  return -1;
  }
  if(sign0=='x'&&sign1=='/'&&num0*num1>=num2)  return -1;
  
  switch (sign0) 
  {
   case '+' : x=num0+num1;break;
   case '-' : x=num0-num1;break;
   case 'x' : x=num0*num1;break;
   case '/' : x=(double)num0/num1;break;
   default : return -1;
  }
  switch (sign1)
  {
   case '+' : x=x+num2;break;
   case '-' : x=x-num2;break;
   case 'x' : x=x*num2;break;
   case '/' : x=(double)x/num2;break;
   default : return -1;
  }
 }
}
 
 else if(a==3)
 {
  if((sign0=='+')||(sign0=='-'))
  {
   if(((sign1=='x')||(sign1=='/'))&&((sign2=='x')||(sign2=='/')))
   {
    if(sign1=='/')//判断
    {
     if(sign2=='x'&&num1*num3>=num2)  return -1;
     if(sign2=='/'&&num1>=num2*num3)  return -1;
    }
    if(sign1=='x'&&sign2=='/'&&num1*num2>=num3)  return -1;

    switch (sign1) 
    {
     case 'x' : x=num1*num2;break;
     case '/' : x=(double)num1/num2;break;
     default : return -1;
    }
    switch (sign2) 
    {
     case 'x' : x=x*num3;break;
     case '/' : x=(double)x/num3;break;
     default : return -1;
    }
    switch (sign0)
    {
     case '+' : x=num0+x;break;
     case '-' : x=num0-x;break;
     default : return -1;
    }
   }
   else if(((sign1=='x')||(sign1=='/'))&&((sign2=='+')||(sign2=='-')))
   {
    if(sign1=='/'&&num1>=num2)  return -1;//判断
    
    switch (sign1) 
    {
     case 'x' : x=num1*num2;break;
     case '/' : x=(double)num1/num2;break;
     default : return -1;
    }
    switch (sign0) 
    {
     case '+' : x=num0+x;break;
     case '-' : x=num0-x;break;
     default : return -1;
    }
    switch (sign2) 
    {
     case '+' : x=x+num3;break;
     case '-' : x=x-num3;break;
     default : return -1;
    }
   }
   else if(((sign1=='+')||(sign1=='-'))&&((sign2=='x')||(sign2=='/')))
   {
    if(sign2=='/'&&num2>=num3)  return -1;//判断
    
    switch (sign2) 
    {
     case 'x' : y=num2*num3;break;
     case '/' : y=(double)num2/num3;break;
     default : return -1;
    }
    switch (sign0)
    {
     case '+' : x=num0+num1;break;
     case '-' : x=num0-num1;break;
     default : return -1;
    }
    switch (sign1) 
    {
     case '+' : x=x+y;break;
     case '-' : x=x-y;break;
     default : return -1;
    }
   }
   else
   {
    switch(sign0)
    {
     case'+' : x=num0+num1;break;
     case'-' : x=num0-num1;break;
    }
    switch(sign1)
    {
     case'+' : x=x+num2;break;
     case'-' : x=x-num2;break;
    }
    switch(sign2)
    {
     case'+' : x=x+num3;break;
     case'-' : x=x-num3;break;
    }
   }
  }
   else 
   {
    if(((sign1=='x')||(sign1=='/'))&&((sign2=='x')||(sign2=='/')))
    {
     if(sign0=='x')//判断
     {
      if(sign1=='/')
      {
       if(sign2=='x'&&num0*num1*num3>=num2)  return -1;
       if(sign2=='/'&&num0*num1>=num2*num3)  return -1;
      }
      if(sign1=='x'&&sign2=='/'&&num0*num1*num2>=num3)  return -1;
     }
     else
     {
      if(sign1=='/')
      {
       if(sign2=='x'&&num0*num3>=num1*num2)  return -1;
       if(sign2=='/'&&num0>=num1*num2*num3)  return -1;
      }
      if(sign1=='x'&&sign2=='/'&&num0*num2>=num1*num3)  return -1;
     }

     switch (sign0) 
     {
      case 'x' : x=num0*num1;break;
      case '/' : x=(double)num0/num1;break;
      default : return -1;
     }
     switch (sign1)
     {
      case 'x' : x=x*num2;break;
      case '/' : x=(double)x/num2;break;
      default : return -1;
     }
     switch (sign2) 
     {
      case 'x' : x=x*num3;break;
      case '/' : x=(double)x/num3;break;
      default : return -1;
     }
    }
    else if(((sign1=='x')||(sign1=='/'))&&((sign2=='+')||(sign2=='-')))
    {
     if(sign0=='/')//判断
     {
      if(sign1=='x'&&num0*num2>=num1)  return -1;
      if(sign1=='/'&&num0>=num1*num2)  return -1;
     }
     if(sign0=='x'&&sign1=='/'&&num0*num1>=num2)  return -1;

     switch (sign0) 
     {
      case 'x' : x=num0*num1;break;
      case '/' : x=(double)num0/num1;break;
      default : return -1;
     }
     switch (sign1)
     {
      case 'x' : x=x*num2;break;
      case '/' : x=(double)x/num2;break;
      default : return -1;
     }
     switch (sign2) 
     {
      case '+' : x=x+num3;break;
      case '-' : x=x-num3;break;
      default : return -1;
     }
    }
    else if(((sign1=='+')||(sign1=='-'))&&((sign2=='x')||(sign2=='/')))
    {
     if(sign0=='/'&&num0>=num1) return -1;//判断
     if(sign2=='/'&&num2>=num3) return -1;
     
     switch (sign2) 
     {
      case 'x' : y=num2*num3;break;
      case '/' : y=(double)num2/num3;break;
      default : return -1;
     }
     switch (sign0) 
     {
      case 'x' : x=num0*num1;break;
      case '/' : x=(double)num0/num1;break;
      default : return -1;
     }
     switch (sign1)
     {
      case '+' : x=x+y;break;
      case '-' : x=x-y;break;
      default : return -1;
     }
    }
    else
    {
     if(sign0=='/'&&num0>=num1) return -1;//判断

     switch(sign0)
     {
      case'x' : x=num0*num1;break;
      case'/' : x=(double)num0/num1;break;
     }
     switch(sign1)
     {
      case'+' : x=x+num2;break;
      case'-' : x=x-num2;break;
     }
     switch(sign2)
     {
      case'+' : x=x+num3;break;
      case'-' : x=x-num3;break;
     }
    }
   }
  }
   return x;
}

void judge(int m,int n)//取运算数和运算符
{
 int i,j,a;
 for(j=1;j<=m;j++)
 {
  a=rand()%3+1;
  count[j-1].amount=a;
  for(i=0;i<a;i++)
  {
   count[j-1].num[i]=random(n);
   count[j-1].sign[i]=symbol( );
  }
  count[j-1].num[i]=random(n);
  if(solution(j)<0) j--;
 }
}

void create(int m,int n)//生成表达式
{
 int i,j;
 judge(m,n);
 FILE *tp=NULL,*hp=NULL;
 if((tp=fopen("Exercises.txt","a"))==NULL)
 return ;
 if((hp=fopen("answer.txt","a"))==NULL)
 return ;
 for(j=1;j<=m;j++)
 {
  fprintf(tp,"%d. ",j);
  fprintf(hp,"%d. ",j);
  for(i=0;i<count[j-1].amount;i++)
  {
   fprintf(tp,"%d ",count[j-1].num[i]);
   fprintf(tp,"%c ",count[j-1].sign[i]);
  }
  fprintf(tp,"%d = \n",count[j-1].num[i]);
  count[j-1].answer=solution(j);
  fprintf(hp,"%f\n",count[j-1].answer);
 }
 fclose(tp);
 fclose(hp);
}

void you_answer(int m)//列出文件中的表达式并输入表达式答案
{
 int i;
 char p[30];
 FILE* tp=NULL;
 if((tp=fopen("Exercises.txt","r"))==NULL) return ;
 //printf("生成的%d条表达式为：\n",m);
 for(i=0;i<m;i++)
 {
  fgets(p,30,(FILE*)tp);
  printf("%s",p);
  //printf("你的答案：");
  getchar();
  scanf("%lf",&q[i]);
 }
 fclose(tp);
}

void result(int m)//判断对错题目数量及序号
{
 int i,j=0;
 int p[100];
 FILE* tp=NULL;
 if((tp=fopen("Grade.txt","a"))==NULL) return ;
 fprintf(tp,"Correct: ");
 for(i=0;i<m;i++)
 {
  if(q[i]==count[i].answer) 
  {
   p[j]=i+1;
   j++;
  }
 }
 if(j==0)
 fprintf(tp,"0( )\n");
 else if(j==1)
 fprintf(tp,"1(%d)",p[0]);
 else
 {
  fprintf(tp,"%d(",j);
  for(i=0;i<j-1;i++)
   fprintf(tp,"%d,",p[i]);
  fprintf(tp,"%d)\n",p[i]);
 }
 j=0;
 fprintf(tp,"Wrong: ");
 for(i=0;i<m;i++)
 {
  if(q[i]!=count[i].answer) 
  {
   p[j]=i+1;
   j++;
  }
 }
 if(j==0)
 fprintf(tp,"0( )\n");
 else if(j==1)
 fprintf(tp,"1(%d)",p[0]);
 else
 {
  fprintf(tp,"%d(",j);
  for(i=0;i<j-1;i++)
   fprintf(tp,"%d,",p[i]);
  fprintf(tp,"%d)",p[i]);
 }
 fclose(tp);
}

int main()//主函数
{
 int m,n;
 //printf("请输入需生成的题目数(n)："");
 scanf("%d",&m);
 printf("\n");
 //printf("请输入运算数的范围(r)："");
 scanf("%d",&n);
 printf("\n");
 create(m,n);
 you_answer(m);
 result(m);
 return 0;
}
