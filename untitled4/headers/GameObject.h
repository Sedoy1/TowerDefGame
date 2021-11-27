#ifndef UNTITLED4_GAMEOBJECT_H
#define UNTITLED4_GAMEOBJECT_H
#include <ostream>
#include "Coordinate.h"
#include "SFML/Graphics.hpp"
#include "AnimationSprite.h"

class GameObject {
    protected:
        int health;
        int damage;
        AnimationSprite aSprite;
        virtual void GetInfo(std:: ostream & os) const = 0;
    public:
        int GetHealth();
        void SetHealth(int new_health);
        int GetDamage();
        void SetDamage(int new_damage);
        AnimationSprite & GetSprite();
    friend std::ostream& operator<<(std::ostream& os, const GameObject & object);
};


#endif //UNTITLED4_GAMEOBJECT_H
