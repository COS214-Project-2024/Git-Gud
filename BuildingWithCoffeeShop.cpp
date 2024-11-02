#include "BuildingWithCoffeeshop.h"

BuildingWithCoffeeShop::BuildingWithCoffeeShop(Building* b){
    this->building=b;
    this->building->setState(std::make_unique<UnderConstruction>());
    this->capacity=1;
}

void BuildingWithCoffeeShop::provideService(){
    this->building->provideService();
    std::cout << " and serves coffee" << std::endl;
}

float BuildingWithCoffeeShop::getCost(){
    return 5000+this->building->getCost();
}

void BuildingWithCoffeeShop::setState(std::unique_ptr<BuildingState> s){
    this->building->setState(std::move(s));
}

void BuildingWithCoffeeShop::repairBuilding(){
    this->building->repairBuilding();
}

std::string BuildingWithCoffeeShop::currentState(){
    return this->building->currentState();
}

void BuildingWithCoffeeShop::simulateConstruction(){
    this->building->simulateConstruction();
}

int BuildingWithCoffeeShop::getNumStories(){
    return this->building->getNumStories();
}

BusinessType BuildingWithCoffeeShop::getBusinessType(){
    return this->building->getBusinessType();
}

void BuildingWithCoffeeShop::addEmployees(){
    this->building->addEmployees();
}

int BuildingWithCoffeeShop::getSize(){
    return this->building->getSize();
}

float BuildingWithCoffeeShop::getPollutionLevel(){
    return this->building->getPollutionLevel();
}

void BuildingWithCoffeeShop::addCitizens(){
    this->building->addCitizens();
}

std::list<Citizen*> BuildingWithCoffeeShop::getTenants(){
    this->building->getTenants();
}

void BuildingWithCoffeeShop::addWorker(){
    if(allCitizens.empty()){

        std::cout << "No citizens to attach." << std::endl;
        return;

    }

    int EmployeesAdded = 0;

    for(Citizen* citizen: allCitizens){

        if(EmployeesAdded >= capacity){

            break;

        }

        if(citizen->getHasJob() == false){

            this->building->attach(citizen);
            citizen->setJobStatus(true);
            EmployeesAdded++;

        }

    }

    ChangeData changeData = {"BuildingConstructed", 2.0f};

    notify(changeData);

}

BuildingWithCoffeeShop* BuildingWithCoffeeShop::clone(){
    BuildingWithCoffeeShop* b=new BuildingWithCoffeeShop();
    std::cout << "coff" << std::endl;
    Building* temp=this->building->clone();
    b->building=temp;
    return b;
}