#include <iostream>
#include "ImagNum.h"

using namespace std;
using namespace ImagComp;

int main(){
    ImagNum x(1,1),y(2,2);
    ImagNum* z = x+y;
    cout<< z->GetValueCart().a << endl;
    return 0;
}