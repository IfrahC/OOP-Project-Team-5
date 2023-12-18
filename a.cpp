/*#include<vector>
#include<iostream>

class Cell
{
public:
    Cell() { std::cout << "Cell()\n"; }
    ~Cell() { std::cout << "~Cell()\n"; }
};

class A
{
public: 
    std::vector<Cell> vec;

public:
    A() { std::cout << "A()\n"; }
    ~A() { std::cout << "~A()\n"; }
};

int main()
{
    A* ptrA{ new A };
    
    Cell c1;
    Cell c2;
    Cell c3;

    ptrA->vec.push_back(c1);
    ptrA->vec.push_back(c2);
    ptrA->vec.push_back(c3);

    delete ptrA;
    ptrA = nullptr;

    return 0;
}*/