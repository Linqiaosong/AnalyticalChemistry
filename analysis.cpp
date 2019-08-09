#include"analysis.h"
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

//analysis.cpp 分析化学数据处理库

//-------------------数据处理----------------------

//平均值函数
double average(double a[], int n)
{
    double sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    return sum/n;
}

//平均偏差函数
double AVDV(double a[], int n)
{
    double sum=0;
    for(int i=0;i<n;i++)
        sum+=fabs(a[i]-average(a,n));
    return sum/n;
}

//相对平均偏差函数
double RAD(double a[], int n){return AVDV(a,n)/average(a,n);}

//标准偏差函数
double STDV(double a[], int n)
{
    double sum=0;
    for(int i=0;i<n;i++)
        sum+=pow(a[i]-average(a,n),2);
    return sqrt(sum/(n-1));
}

//相对标准偏差函数
double RSD(double a[], int n){return STDV(a,n)/average(a,n);}

//全距函数
double range(double a[], int n)
{
    sort(a,a+n);
    return a[n-1]-a[0];
}

//-------------------可疑值检验----------------------

//Q检验法
void Q(double a[], int n)
{
    double q;
    sort(a,a+n);
    printf("n\tx(n)\tQ\n");
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            q=(a[1]-a[0])/range(a,n);
            printf("%d\t%g\t%.2lf\n",i+1,a[0],q);
        }
        else
        {
            q=(a[i]-a[i-1])/range(a,n);
            printf("%d\t%g\t%.2lf\n",i+1,a[i],q);
        }
    }
}

//Grubbs法
void Grubbs(double a[], int n)
{
    double G;
    sort(a,a+n);
    printf("n\tx(n)\tG\n");
    for(int i=0;i<n;i++)
    {
        G=fabs(a[i]-average(a,n))/STDV(a,n);
        printf("%d\t%g\t%.2lf\n",i+1,a[i],G);
    }
}

//-------------------显著性检验----------------------

//t检验法：平均值与标准值的比较
void t1(double a[], int n, double true_val)
{
    double result=fabs(average(a,n)-true_val)*sqrt(n)/STDV(a,n);
    printf("t=%.2lf\nf=%d",result,n-1);
}

//t检验法：两组平均值的比较
void t2(double a[], int n, double b[], int m)
{
    double ssum=sqrt((STDV(a,n)*STDV(a,n)*(n-1)+STDV(b,m)*STDV(b,m)*(m-1))/(n-1+m-1));
    double result=fabs(average(a,n)-average(b,m))*sqrt(n*m/(n+m))/ssum;
    printf("t=%.2lf\nf=%d",result,n+m-2);
}

//F检验法
void F(double a[], int n, double b[], int m)
{
    double f;
    double s1=STDV(a,n);
    double s2=STDV(b,n);
    if(s1>s2){
        f=(s1*s1)/(s2*s2);
        printf("F=%.2lf\nflarge=%d\nfsmall=%d\n",f,n-1,m-1);}
    else{
        f=(s2*s2)/(s1*s1);
        printf("F=%.2lf\nflarge=%d\nfsmall=%d\n",f,m-1,n-1);}
}

//--------------------回归分析-----------------------

//一元线性回归分析
void RE(double x[], int n, double y[], int m)
{
    double k,h,r,up=0,downx=0,downy=0;
    for(int i=0;i<n;i++)
    {
        up+=(x[i]-average(x,n))*(y[i]-average(y,m));
        downx+=pow((x[i]-average(x,n)),2);
        downy+=pow((y[i]-average(y,n)),2);
    }
    k=up/downx;
    r=k*sqrt(downx/downy);
    h=average(y,m)-k*average(x,n);
    printf("y=%gx+%g\nr=%g\n",k,h,r);
}
