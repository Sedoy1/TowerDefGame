#include "../headers/Player.h"

void Player::GetInfo(std::ostream &os) const {
    os<<"health- "<<health<<"\n"
    <<"money- "<<money<<"\n";
}