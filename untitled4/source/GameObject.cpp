//
// Created by oleg on 01.11.2021.
//

#include "../headers/GameObject.h"


int GameObject::GetHealth(){
    return health;
}

void GameObject::SetHealth(int new_health) {
    health = new_health;
}

int GameObject::GetDamage() {
    return damage;
}

void GameObject::SetDamage(int new_damage) {
    damage = new_damage;
}

AnimationSprite & GameObject::GetSprite() {
    return aSprite;
}


std::ostream& operator<<(std::ostream &os, const GameObject & object) {
    object.GetInfo(os);
    return os;
}