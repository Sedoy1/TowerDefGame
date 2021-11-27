#include "../headers/FriendObject.h"

void FriendObject::Shoot() {
    if(currentAim != nullptr){
        shotState = true;
        int newHealth = currentAim->GetHealth();
        currentAim->SetHealth(newHealth - damage);
    }
}

void FriendObject::Update() {
    CheckAim();
    if(timeStart > shootDelay){
        Shoot();
        timeStart = 0;
    }
    else{
        timeStart += timeStep;
    }
}

void FriendObject::CheckAim() {
    if(currentAim== nullptr || currentAim->GetHealth() < 0){
        FindNewAim();
    }
}

void FriendObject::FindNewAim() {
    auto resultFind = std::find_if(enemyVector->begin(), enemyVector->end(), [](const std::shared_ptr<Enemy>& enemy){
        return enemy->GetHealth() > 0;});
    if(resultFind != enemyVector->end()){
        currentAim = *resultFind;
    }
    else{
        currentAim = nullptr;
    }
}

bool FriendObject::GetShootingState() const {
    return shotState;
}

void FriendObject::SetShootingState(bool newState) {
    shotState = newState;
}

void FriendObject::GetInfo(std::ostream &os) const {
    os <<"Damage - "<<damage <<"\n"
       <<"Shot speed - "<<shootDelay<<"\n"
       <<"Position - "<<" x "<<position.x<<"  y "<<position.y<<"\n";
       if (currentAim != nullptr) {
           os <<"----------AIM DATA----------\n"
           <<*currentAim
           << "----------------------------\n";
       }
}
