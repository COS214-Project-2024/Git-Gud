#include "Player.h"

void Player::changeTaxRate(float tax){
    taxMan->updateTotalTaxRate(tax);
}

void Player::taxResidentialBuildings(){
    taxMan->chooseTaxMethod(new TaxResidents);
    Balance = taxMan->calculateTax();
}

void Player::taxIndustrialBuildings(){
    taxMan->chooseTaxMethod(new TaxFactories);
    Balance = taxMan->calculateTax();
}

void Player::taxCommercialBuildings(){
    taxMan->chooseTaxMethod(new TaxCommercial);
    Balance = taxMan->calculateTax();
}

void Player::addResidentialBuilding(ResidentialBuilding* residentialBuilding){
    taxMan->addResidential(residentialBuilding);
}   

void Player::addIndustrialBuilding(IndustrialBuilding* industrialBuilding){
    taxMan->addIndustrial(industrialBuilding);
}

void Player::addCommercialBuilding(CommercialBuilding* commercialBuilding){
    taxMan->addCommercial(commercialBuilding);
}

float Player::getBalance(){
    return Balance;
}