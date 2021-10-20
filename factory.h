#ifndef FACTORY_H
#define FACTORY_H
#include <warrior.h>


class factory
{
public:
    virtual std::unique_ptr<warrior> create_simple() const  = 0;
    virtual std::unique_ptr<warrior> create_hard() const = 0;
    virtual ~factory() {};
};

#endif // FACTORY_H
