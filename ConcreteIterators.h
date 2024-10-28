#ifndef CONCRETE_ITERATORS_H
#define CONCRETE_ITERATORS_H

#include "LinearIterator.h"
#include "RadialIterator.h"
class Utility;
class Building;

using UtilityIterator = LinearIterator<Utility>;
using BuildingIterator = LinearIterator<Building>;
using RadialBuildingIterator = RadialIterator<Building>;
using RadialUtilityIterator = RadialIterator<Utility>;

#endif // CONCRETE_ITERATORS_H
