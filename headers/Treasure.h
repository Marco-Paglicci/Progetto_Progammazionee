

#ifndef PROGETTO_PROGRAMMAZIONE_TREASURE_H
#define PROGETTO_PROGRAMMAZIONE_TREASURE_H

#include <string>

using namespace std;


class Treasure {
public:

    Treasure(const string& name);

    virtual ~Treasure() = default;

    string getName() const;


private:

    string name;
    float dropRate;
};

#endif // TREASURE_H
