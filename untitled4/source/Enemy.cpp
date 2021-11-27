#include "../headers/Enemy.h"
void Enemy::GetInfo(std::ostream &os) const {
           os << "Health - " << health<<"\n"
              <<"Damage - "<<damage<<"\n"
              <<"Speed - "<<speed<<"\n"
              <<"Step - "<<currentStep<<"\n";
}
