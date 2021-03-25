#include "ImagNum.h"
#include <cmath>

using namespace ImagComp;

ImagNum::ImagNum(double a , double b){
    this->Data.a= a;
    this->Data.b= b;
}

ImagNum::~ImagNum(){
    
}

struct BaseData ImagNum::GetValueCart(){
    return this->Data;
}

struct BaseData ImagNum::GetValuePolar(){
    struct BaseData toReturn;
    toReturn.a = sqrt(this->Data.a*this->Data.a + this->Data.b*this->Data.b);
    toReturn.b = atan(this->Data.b/this->Data.b);
    return toReturn;
};

ImagNum* ImagNum::operator+(ImagNum num){
    struct BaseData val = num.GetValueCart();
    return new ImagNum(
        this->Data.a+val.a,
        this->Data.b+val.b);
};

ImagNum* ImagNum::operator-(ImagNum num){
    struct BaseData val = num.GetValueCart();
    return new ImagNum(
        this->Data.a-val.a,
        this->Data.b-val.b);
};

ImagNum* ImagNum::operator*(ImagNum num){
    struct BaseData val = num.GetValueCart();
    return new ImagNum(
        this->Data.a*val.a-this->Data.b*val.b,
        this->Data.a*val.b+this->Data.b*val.a);
};

ImagNum* ImagNum::operator/(ImagNum num){
    struct BaseData val = num.GetValueCart();
    double d = val.a*val.a+val.b*val.b; 
    return new ImagNum(
        (this->Data.a*val.a+this->Data.b*val.b),
        this->Data.b*val.a-this->Data.a+val.b);
};