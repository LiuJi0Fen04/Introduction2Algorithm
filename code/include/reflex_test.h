#include "export_macro.h"
#include <variant>
#include <typeinfo>



class Base {};
class Derived : public Base {};

void test_reflex()
{

    //1. 类和对象的动态操作
    std::variant<int, double, std::string> data;

    data = "test";
    std::cout << "string: " << std::get<std::string>(data) << std::endl;
    data = 42;
    std::cout << "int: " << std::get<int>(data) << std::endl;


    // 2. 运行时类型是识别
    Base* obj = new Derived();
    std::cout << "Type: " << typeid(*obj).name() << std::endl;
    delete obj;

    // 3. 插件系统与动态加载

    // 4. 

    // 5. 
}

