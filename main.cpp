#include <iostream>
#include <ctime>
#include "headers/Engine.h"


#include <unistd.h> // Per getcwd su sistemi POSIX      // Todo rimuovere testing


int main() {
    srand(time(NULL));

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        cout << "Current directory: " << cwd << endl;
    } else {
        perror("getcwd error");
    }


    Engine engine; //definiamo l'oggetto engine dalla classe (fa il run del costruttore)
    engine.run(); // fa il run della funzione

    return 0;
}
