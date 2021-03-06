#include "ScavTrap.hpp"

void ScavTrap::challengeNewcomer(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << this->type << this->name << " doesnt have enougth energy." << std::endl;
    return;
  }
  this->energyPoints -= 25;
  std::string attackArray[5] = {
    " Dance",
    " Trip",
    " Fall down",
    " Shoot himself",
    " Cook a cake"
  };
  std::cout << this->type << this->name << " made " << target
            << attackArray[rand() % 5]
            << "!" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "CL4P-TP named " << this->name << " destructed." << std::endl;
  return;
}

ScavTrap::ScavTrap(std::string name) {
  srand(time(NULL));
  this->name = name;
  this->type = "CL4P-TP ";
  this->hitPoints = 100;
  this->maxHitPoints = 100;
  this->energyPoints = 50;
  this->maxEnergyPoints = 50;
  this->level = 1;
  this->meleeAttackDmg = 20;
  this->rangedAttackDmg = 13;
  this->armorDmgReduction = 3;
  std::cout << "CL4P-TP named " << this->name << " created." << std::endl;
  return;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &obj)
{
  this->name = obj.name;
  this->type = obj.type;
  this->hitPoints = obj.hitPoints;
  this->maxHitPoints = obj.maxHitPoints;
  this->energyPoints = obj.energyPoints;
  this->maxEnergyPoints = obj.maxEnergyPoints;
  this->level = obj.level;
  this->meleeAttackDmg = obj.meleeAttackDmg;
  this->rangedAttackDmg = obj.rangedAttackDmg;
  this->armorDmgReduction = obj.armorDmgReduction;
	return (*this);
}
