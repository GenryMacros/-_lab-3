#ifndef HUMAN_FACTORY_H
#define HUMAN_FACTORY_H
#include <memory>
#include "factory.h"
#include "tawern_brawler.h"

class human_factory : public factory
{
public:
    human_factory() = default;
    std::unique_ptr<warrior> create_simple() const override;
    std::unique_ptr<warrior> create_hard() const override;
};

#endif // HUMAN_FACTORY_H
