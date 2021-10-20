#include "human_factory.h"
using namespace std;

unique_ptr<warrior> human_factory::create_simple() const
{
    return make_unique<tawern_brawler>(10, 1, 6);
};

unique_ptr<warrior> human_factory::create_hard() const
{
     return make_unique<tawern_brawler>(30, 8, 7);
};
