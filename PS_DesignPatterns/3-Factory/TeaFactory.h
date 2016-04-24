﻿#pragma once
#include "HotDrink.h"
#include "HotDrinkFactory.h"

struct TeaFactory : HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() override {
        return std::make_unique<Tea>();
    }
};