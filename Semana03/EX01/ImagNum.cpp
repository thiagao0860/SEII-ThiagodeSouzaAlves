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
