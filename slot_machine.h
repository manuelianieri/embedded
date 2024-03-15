#ifndef SLOT_MACHINE_H
#define SLOT_MACHINE_H
#include <vector>


class SlotMachine{
private:
    std::vector<char> symbols;//contiene simboli della slot
    bool hasPair;//coppia di simboli uguali
    bool hasTriple;//tris di simboli
    int coins;//numero monete inserite

public:
    SlotMachine();
    //metodo per girare rotelle
    void spin();

    // Metodo per gestire il gioco
    void play();

    //Metodo benvenuto
    int welcome();
};


#endif // SLOT_MACHINE_H
