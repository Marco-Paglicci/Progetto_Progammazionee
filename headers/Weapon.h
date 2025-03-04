#ifndef PROGETTO_PROGRAMMAZIONE_WEAPON_H
#define PROGETTO_PROGRAMMAZIONE_WEAPON_H

#include "Treasure.h"

class Weapon : public Treasure {
public:

    Weapon(const std::string& name, int power);

    int getPower() const;

    void setPower(int power) const;

private:
    int power;
};

#endif // WEAPON_H
