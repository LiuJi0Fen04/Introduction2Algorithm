#include "export_macro.h"
#include <variant>
#include <typeinfo>



class Base {};
class Derived : public Base {};

void test_reflex()
{

    //1. ��Ͷ���Ķ�̬����
    std::variant<int, double, std::string> data;

    data = "test";
    std::cout << "string: " << std::get<std::string>(data) << std::endl;
    data = 42;
    std::cout << "int: " << std::get<int>(data) << std::endl;


    // 2. ����ʱ������ʶ��
    Base* obj = new Derived();
    std::cout << "Type: " << typeid(*obj).name() << std::endl;
    delete obj;

    // 3. ���ϵͳ�붯̬����

    // 4. 

    // 5. 
}

