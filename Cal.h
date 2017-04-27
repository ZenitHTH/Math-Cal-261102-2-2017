#include <math.h>
#include <ctime>
#define PI 3.14159265
#define e  2.718281828

float SIN(char textsave_tri[]){  //trigonometric
	float siin;
	siin = atof(textsave_tri);
    return sin(siin*PI/180);
}

float COS(char textsave_tri[]){
	float coss;
	coss = atof(textsave_tri);
    return cos(coss*PI/180);
}

float TAN(char textsave_tri[]){
	float tann;
	tann = atof(textsave_tri);
    return tan(tann*PI/180);
}

float COSEC(char textsave_tri[]){
	float csc;
	csc = atof(textsave_tri);
    return 1/sin(csc*PI/180);
}

float SEC(char textsave_tri[]){
	float secc;
	secc = atof(textsave_tri);
    return 1/cos(secc*PI/180);
}

float COT(char textsave_tri[]){
	float cott;
	cott = atof(textsave_tri);
    return 1/tan(cott*PI/180);
}

float ASIN(char textsave_tri[]){
	float asiin;
	asiin = atof(textsave_tri);
    return asin(asiin)*180/PI;
}

float ACOS(char textsave_tri[]){
	float acoss;
	acoss = atof(textsave_tri);
    return acos(acoss)*180/PI;
}

float ATAN(char textsave_tri[]){
	float atann;
	atann = atof(textsave_tri);
    return atan(atann)*180/PI;
}

float ACOSEC(char textsave_tri[]){
	float acsc;
	acsc = atof(textsave_tri);
    return asin(1/acsc)*180/PI;
}

float ASEC(char textsave_tri[]){
	float asecc;
	asecc = atof(textsave_tri);
    return acos(1/asecc)*180/PI;
}

float ACOT(char textsave_tri[]){
	float acott;
	acott = atof(textsave_tri);
    return atan(1/acott)*180/PI;
}

float Ln(char textsave_log[]){ //expo & log
	float ln;
	ln = atof(textsave_log);
	return log(ln);
}

float LOG(char textsave_log[]){
	float logg;
	logg = atof(textsave_log);
	return log10(logg);
}

float EXPO(char textsave_log[]){
	float expo;
	expo = atof(textsave_log);
	return exp(expo);
}

float POW(char textsave_pow_1[],char textsave_pow_2[]){ //pow& root
	float pow1,pow2;
	pow1 = atof(textsave_pow_1);
	pow2 = atof(textsave_pow_2);
	return pow(pow1,pow2);
}

float SQRT(char textsave_pow_1[],char textsave_pow_2[]){
	float sqrt1,sqrt2;
	sqrt1 = atof(textsave_pow_1);
	sqrt2 = atof(textsave_pow_2);
	return pow(sqrt1,1/sqrt2);
}
/*coming soon*/
 float SINH(char textsave_tri[]){
 	float sinhh;
 	sinhh = atof(textsave_tri);
 	return (pow(e,sinhh)-pow(e,-sinhh))/2;
 }

float COSH(char textsave_tri[]){
 	float coshh;
 	coshh = atof(textsave_tri);
 	return (pow(e,coshh)+pow(e,-coshh))/2;
 }
 
 float TANH(char textsave_tri[]){
 	float tanhh;
 	tanhh = atof(textsave_tri);
 	return sinh(tanhh)/cosh(tanhh);
 }

float CSCH(char textsave_tri[]){
 	float cschh;
 	cschh = atof(textsave_tri);
 	return 1/sinh(cschh);
 }
 
float SECH(char textsave_tri[]){
 	float sechh;
 	sechh = atof(textsave_tri);
 	return 1/cosh(sechh);
 }
 
 float COTH(char textsave_tri[]){
 	float cothh;
 	cothh = atof(textsave_tri);
 	return 1/tanh(cothh);
 }
 
float Velocity_End(char S[],char U[],char T[],char A[])
{

    float a,u,s,t;

    a = atof(A);
    u = atof(U);
    s = atof(S);
    t = atof(T);

    if( s == 0) // v = u+at
    {
        return u+a*t;
    }else
    if( t == 0) // V^2 = U^2 + 2AS
    {
        return sqrt(pow(u,2) + 2*a*s);
    }else
    if(a == 0)
    {
        return ((2*s)/t) - u;
    }else
    {
        srand(time(0));
        int i = rand()%3;

        if(i == 0) return u+a*t;
        if(i == 1) return sqrt(pow(u,2) + 2*a*s);
        if(i == 2) return ((2*s)/t) - u;
    }

}

float Velocity_Start(char S[],char V[],char T[],char A[])
{

    float a,v,s,t;

    a = atof(A);
    v = atof(V);
    s = atof(S);
    t = atof(T);

    if( s == 0) // u = v-at
    {
        return v-a*t;
    }else
    if( t == 0) // U^2 = V^2 - 2AS
    {
        return sqrt(pow(v,2) - 2*a*s);
    }else
    if(a == 0)
    {
        return ((2*s)/t) - v;
    }else
    {
        srand(time(0));
        int i = rand()%3;

        if(i == 0) return v-a*t;
        if(i == 1) return sqrt(pow(v,2) - 2*a*s);
        if(i == 2) return ((2*s)/t) - v;
    }

}

float Distance(char U[],char V[],char T[],char A[])
{
    float a,v,u,t;

    a = atof(A);
    v = atof(V);
    u = atof(U);
    t = atof(T);

    if(a == 0)
    {
        return ((u+v)/2)*t;
    }else
    if(v == 0)
    {
        return (u*t) - (0.5*a*t*t);
    }else
    if(t == 0)
    {
        return ((v*v)-(u*u))/(2*a);
    }else
    {
        srand(time(0));
        int i = rand()%3;

        if(i == 0) return ((u+v)/2)*t;
        if(i == 1) return (u*t) - (0.5*a*t*t);
        if(i == 2) return ((v*v)-(u*u))/(2*a);
    }
}

float Acceleration(char U[],char V[],char T[],char S[])
{
    float s,v,u,t;

    s = atof(S);
    v = atof(V);
    u = atof(U);
    t = atof(T);

    if(s == 0)
    {
        return (v-u)/t;
    }else
    if(v == 0)
    {
        return ((2*s)/t) - (u/t);
    }else
    if(t == 0)
    {
        return ((v*v)-(u*u))/(2*s);
    }else
    {
        srand(time(0));
        int i = rand()%3;

        if(i == 0) return (v-u)/t;
        if(i == 1) return (2*s)/t - u/t;
        if(i == 2) return ((v*v)-(u*u))/(2*s);
    }

}

float Time(char U[],char V[],char A[],char S[])
{
	float s,v,u,a;

    s = atof(S);
    v = atof(V);
    u = atof(U);
    a = atof(A);

	if(v == 0)
	{
		return (sqrt(pow(u,2)+(2*a*s)) - u)/a;
	}else
	if(a == 0)
	{
		return (2*s)/(u+v);
	}else
	if(s == 0)
	{
		return (v-u)/a;
	}else
    {
        srand(time(0));
        int i = rand()%3;

        if(i == 0) return (sqrt(pow(u,2)+(2*a*s)) - u)/a;
        if(i == 1) return (2*s)/(u+v);
        if(i == 2) return (v-u)/a;
    }
}
