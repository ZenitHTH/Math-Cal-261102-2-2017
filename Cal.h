#include <math.h>
#define PI 3.14159265

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
    return asin(1/acsc);
}

float ASEC(char textsave_tri[]){
	float asecc;
	asecc = atof(textsave_tri);
    return acos(1/asecc);
}

float ACOT(char textsave_tri[]){
	float acott;
	acott = atof(textsave_tri);
    return atan(1/acott);
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
// float SINH(char textsave_log)

