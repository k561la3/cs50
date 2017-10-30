// 3.15 25 36 37 43 45
// ряды из дейтела 3.47
//logax =  a^logax = x
//root(logax)x = a




#include <stdio.h>
//#include <tgmath.h>
#include <math.h>
#include <stdlib.h>

//#include <unistd.h>
#define e 2.718281828459045235360287471352662497757247
#define pi 3.14159265358979323846264338327950288419716


double abt(double a){return (a>=0.0000000)?a:-a;}
double add(double a,double b){return a+b;}
double sub(double a,double b){return a-b;}
double mul(double a,double b){return a*b;}
double division(double a,double b){return a/b;}
int fac(int a){
	int f=1;
	for (int i = 1; i <= a; ++i){f*=i;}
	return f;}
double power(double a,double b){
	return pow(a,b);
}
double loge(double x){
	if(x==e)return 1.0f;
	if(x<0){return 0;}
	double y = 1;
	double temp = 0.5;
	double d1,d2;
	double coef;
	if(x>e){coef=1;}else{coef=-1;}
	while(1){
			d1 = pow(e,y);
			d2 = pow(e,y+coef);
			if(x>e){
				if((x/d1>=1) && (x/d2<=1)){coef/=10;continue;}
			}else{
				if((x/d1<=1) && (x/d2>=1)){coef/=10;continue;}
			}
			y+=coef;
			if(temp==y){break;}
			temp = y;
		}
	return y;
}
double inv(double x){
	return 1.0/x;
}
double clen(double R){
	return R*pi;
}
double carea(double R){
	return pi*power(R,2);
}


int main(int argc, char const *argv[])
{
	double a;
	double b;
	char op;
	if(argc>=3){a = atof(argv[1]);op = argv[2][0];b=e;}
	if(argc>=4){b = atof(argv[3]);op = argv[2][0];}
	
	switch(op){
		case '+':printf("%f\n", add(a,b));break;
		case '-':printf("%f\n", sub(a,b));break;
		case '*':printf("%f\n", mul(a,b));break;
		case '/':printf("%f\n", division(a,b));break;
		case '^':printf("%f\n", power(a,b));break;
		case 'l':printf("%f\n", loge(a)/loge(b));break;
		case 'c':printf("%f\n", clen(a));break;
		case 's':printf("%f\n", carea(a));break;
		case 'i':printf("%f\n", inv(a));break;
		case 'a':printf("%f\n", abt(a));break;
		default:break;
	}






	return 0;
}









