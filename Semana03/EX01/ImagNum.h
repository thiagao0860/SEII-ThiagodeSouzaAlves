
namespace ImagComp{

struct BaseData{
    double a;
    double b;
};

class ImagNum
{
private:
    struct BaseData Data;
public:
    ImagNum(double a, double b);
    ~ImagNum();
    struct BaseData GetValueCart();
    struct BaseData GetValuePolar();
};

}