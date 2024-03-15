#include <iostream>
#include <slot_machine.h>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

SlotMachine::SlotMachine():hasPair(false),hasTriple(false),coins(0){
    //inizializzazione dei simboli della slot
    for(char c='A';c<='G';c++){
        symbols.push_back(c);
    }
}

void SlotMachine::spin(){
    hasPair=false;
    hasTriple=false;
    char estraction[3];

    // Mostra i simboli estratti
    std::cout << "The symbols are: ";
    for (int i = 0; i < 3; ++i) {

        // Estrae casualmente tre simboli
        std::random_shuffle(symbols.begin(), symbols.end());
        estraction[i]=symbols[0];
        std::cout << estraction[i] << " ";
    }
    std::cout << std::endl;

    // Controlla se c'è una coppia o un tris di simboli uguali
    if (  estraction[0] ==   estraction[1] ||   estraction[1] ==   estraction[2] ||   estraction[0] ==   estraction[2]) {
        hasPair = true;
        if (  estraction[0] ==   estraction[1] &&   estraction[1] ==   estraction[2]) {
            hasTriple = true;
        }
    }
}

void SlotMachine::play(){
    int numberOfCoins,inserted_coin,counter=1,answer;
    numberOfCoins=welcome();

    while(1) {

        std::cout << "Insert a coin for each Spin: ";
        std::cin>>inserted_coin;
        numberOfCoins=numberOfCoins-inserted_coin;
        std::cout<<"Great, you have still "<<numberOfCoins<<" coin!"<<std::endl<<std::endl;

        for(int i=inserted_coin;i>0;i--){

            std::cout<<"Try number: "<<counter<<std::endl;
            counter++;

            spin();
            if (hasTriple) {
                std::cout << "YOU WIN 3 COINS!!!\n\n";
                numberOfCoins=numberOfCoins+3;
            } else if (hasPair) {
                std::cout << "YOU WIN 2 COINS!!!\n\n";
                numberOfCoins=numberOfCoins+2;

            } else {
                std::cout << "YOU LOSE!!!\n\n";
            }

        }
        counter=1;
        cout<<"You want try again? Press '1' to quit or any other number to continue. \n";
        cin>>answer;
        cout<<"\n\n";
        if(answer==1) break;
        system("cls");


    }
    std::cout<< "Hai terminato con " << numberOfCoins << " monete." << std::endl;

}

int SlotMachine::welcome(){
    int numberOfCoins;
    char enter;

    cout<<"Welcome Player!!!\n";
    cout<<"Insert a number of coins: " << std::endl << std::endl << std::endl;
    cin>>numberOfCoins;

    cout<<"Great, you have inserted "<<numberOfCoins<<" coins.\n\n";
    cout<<"Press any key to start: You can win 2 Coins for a Couple, 3 Coins for a Tris!\n\n";
    cin>>enter;

    system("cls");
    return numberOfCoins;
}
