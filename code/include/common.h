#ifndef _COMMON_H_
#define _COMMON_H_
#include <iostream>
#include "export_macro.h"
#include <vector>

const float MAXIMUM = std::numeric_limits<float>::infinity();

template <typename T1, typename T2>
struct Array
{
    T1* data;
    T2 size;
};

template<typename T>
I2A_API void coutArray(Array<T, int> input, std::string msg)
{
    std::cout << "\n>>> " << msg << ":" << std::endl;
    for(int i = 0; i < input.size; i++)
    {
        std::cout << "  " << input.data[i];
    }
    std::cout << std::endl;
}

template<typename T>
I2A_API inline void swap(T* a, T* b)
{
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

I2A_API void abortMesage(std::string msg);


// template <typename T>
// class Node
// {
// public:
//     T data;
//     Node *next;
// // private:
//     Node(){}
//     ~Node(){}
// };    

// struct node
// {
//     int data;
//     node *next;
// };
// template <class T>
// class LNode
// {
// private:
//     /* data */
//     // Node<T>** phead;
//     node** phead;
// public:
//     // Node<T>* head();
//     // node* head();
//     // void push_back(T);
//     LNode(/* args */){}
//     ~LNode();
// };

typedef struct point2f_
{
    float x;
    float y;
    point2f_ operator+(point2f_ ob)
    {
        point2f_ p;
        p.x = this->x + ob.x;
        p.y = this->y + ob.y;
        return p;
    };
    point2f_ operator-(point2f_ ob)
    {
        point2f_ p;

        p.x = this->x - ob.x;
        p.y = this->y - ob.y;
        return p;
    };
    point2f_ operator*(float multi)
    {
        point2f_ p;

        p.x = this->x * multi;
        p.y = this->y * multi;
        return p;
    };
    point2f_(float x, float y)
    {
        // std::cout << x << std::endl;
        this->x = x;
        this->y = y;
        // return * this;
    };
    point2f_() { this->x = 0.0, this->y = 0.0; };
    ~point2f_() {};
}point2f;







#endif