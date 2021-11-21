#ifndef UNTITLED4_GAMEOBJECT_H
#define UNTITLED4_GAMEOBJECT_H
#include "Coordinate.h"
#include "SFML/Graphics.hpp"
#include "AnimationSprite.h"

class GameObject {
    protected:
        int health;
        int damage;
        AnimationSprite aSprite;

    public:
        int GetHealth();
        void SetHealth(int new_health);
        int GetDamage();
        void SetDamage(int new_damage);
        AnimationSprite & GetSprite();
};


#endif //UNTITLED4_GAMEOBJECT_H
