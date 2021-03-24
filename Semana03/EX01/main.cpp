#include <iostream>
#include "ImagNum.h"

using namespace std;
using namespace ImagComp;

int main(){
    ImagNum x(1,1) ;
    cout<< x.GetValuePolar().a << endl;
    return 0;
}