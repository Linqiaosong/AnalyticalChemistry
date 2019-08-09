#ifndef ANALYSIS_H_INCLUDED
#define ANALYSIS_H_INCLUDED

//analysis.h 分析化学数据处理库

//-------------------数据处理----------------------
//平均值函数
double average(double a[], int n);//a[n]为数据数组，n为数组长度

//平均偏差函数
double AVDV(double a[], int n);//a[n]为数据数组，n为数组长度

//相对平均偏差函数
double RAD(double a[], int n);//a[n]为数据数组，n为数组长度

//标准偏差函数
double STDV(double a[], int n);//a[n]为数据数组，n为数组长度

//相对标准偏差函数
double RSD(double a[], int n);//a[n]为数据数组，n为数组长度

//全距（极差）函数
double range(double a[], int n);//a[n]为数据数组，n为数组长度

//-------------------可疑值检验----------------------

//Q检验法，结果保留小数点后2位
void Q(double a[], int n);//a[n]为数据数组，n为数组长度

//Grubbs法，结果保留小数点后2位
void Grubbs(double a[], int n);//a[n]为数据数组，n为数组长度

//-------------------显著性检验----------------------

//单边t检验法：平均值与标准值的比较，保留小数点后2位
void t1(double a[], int n, double true_val);//a[n]为数据数组，n为数组长度，true_val为真值

//双边t检验法：两组平均值的比较，保留小数点后2位
void t2(double a[], int n, double b[], int m);//a[n],b[m]为数据数组，n,m为数组长度

//F检验法，保留小数点后2位
void F(double a[], int n, double b[], int m);//a[n],b[m]为数据数组，n,m为数组长度

//--------------------回归分析-----------------------

//一元线性回归分析
void RE(double a[], int n, double b[], int m);//a[n],b[m]为数据数组，n,m为数组长度

#endif // ANALYSIS_H_INCLUDED
