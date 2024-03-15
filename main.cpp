#include <cstdlib>
#include <ctime>
#include "slot_machine.h"
using namespace std;

int main()
{
    // Imposta la generazione dei numeri casuali
            std::srand(static_cast<unsigned int>(std::time(nullptr)));

    SlotMachine slotMachine;
    slotMachine.play();

    return 0;
}
