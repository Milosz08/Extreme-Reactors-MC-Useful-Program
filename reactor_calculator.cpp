#include <iostream>
#include <string>

using namespace std;

/**
 * @author Miłosz Gilga
 * @date 2021
 * @section Description
 * Program wyliczający ilość potrzebnych materiałów do zbudowania reaktora atomowego
 * z moda Big Reactors/Extreme Reactors na podstawie trzech jego parametrów: długości, szerokości i wysokości.
 * 
 * @copyright Program na licencji MIT.
 * (c) 2021 by Miłosz Gilga.
*/

/**
 * @brief Zmienne inicjalizujące 
*/
struct Data {
    int x;
    int y;
    int z;
    int chooseType;
};

/**
 * @brief Zmienne zapisujące
*/
struct BlocksQuantity {
    int reactorCasingBlock;
    int reactorGlassBlock;
    int yelloriumFuelRod;
    int reactorControlRod;
    int reactorAccessPortBlock;
    int reactorPowerTapBlock;
    int reactorCoolantPortBlock;
    int reactorComputerPortBlock;
    int reactorRednetPortBlock;
    int blocksToRemove;
    int bucketsOfLiquid;
    int reactorCoolantBlock;
};

/**
 * @brief Generowanie odpowiednich komunikatów w konsoli cmd
*/
void cmdMess(int choseMess) {
    switch (choseMess) {
    case 1:
        cerr << "Error! The specified number does not exist.";
        break;
    case 2:
        cout << "Reactor size to resources program by Milosz Gilga." << endl;
        cout << "Version: 1.0" << endl;
        cout << "===================================================" << endl;
        cout << endl;
        cout << "Size of Extreme/Big reactor (length, width, height): ";
        break;
    case 3:
        cout << endl;
        cout << "Reactor struct options:" << endl;
        cout << "  1. Type 1 for hollow (all wall with glass)" << endl;
        cout << "  2. Type 2 for only top with glass" << endl;
        cout << "  3. Type 3 for all wall with glass without bottom" << endl;
        cout << "  4. Type 4 for all wall with no glass" << endl;
        cout << endl;
        cout << "Your choose is: ";
        break;
    case 4:
        cout << endl;
        cout << "My reactor will have the following number of components" << endl;
        cout << "  1. Reactor Access Port: ";
        break;
    case 5:
        cout << "  2. Reactor Power Tap: ";
        break;
    case 6:
        cout << "  3. Reactor Coolant Port: ";
        break;
    case 7:
        cout << "  4. Reactor ComputerCraft Port: ";
        break;
    case 8:
        cout << "  5. Reactor RedNet Port: ";
        break;
    case 9:
        cerr << "Error! The quantity of Power Tap Block must be greater than zero." << endl;
        break;
    case 10:
        cerr << "Error! The minimum size of the reactor is 3x3x3 (length x width x height)." << endl;
        break;
    case 11:
        cerr << "Error! The value entered must be a number." << endl;
        break;
    }
}

/**
 * @brief Pobranie danych wpisanych z konsoli przez użytkownika + walidacja wprowadzonych danych
 * pod kątem zakresu liczbowego i tego, czy została wprowadzona liczba, czy litera.
*/
void getData(Data &var, BlocksQuantity& quantity) {
    int cMess = 2, oMess = 3, qMess1 = 4, qMess2 = 5, qMess3 = 6, qMess4 = 7, qMess5 = 8, eMess1 = 9, eMess2 = 10, eMess3 = 11;
    cmdMess(cMess);
    cin >> var.x >> var.y >> var.z;
    if (var.x < 3 || var.y < 3 || var.z < 3) {
        cmdMess(eMess2);
        exit(0);
    }
    cmdMess(oMess);
    cin >> var.chooseType;
    cmdMess(qMess1);
    cin >> quantity.reactorAccessPortBlock;
    cmdMess(qMess2);
    cin >> quantity.reactorPowerTapBlock;
    if (quantity.reactorPowerTapBlock < 1) {
        cmdMess(eMess1);
        exit(0);
    }
    cmdMess(qMess3);
    cin >> quantity.reactorCoolantPortBlock;
    cmdMess(qMess4);
    cin >> quantity.reactorComputerPortBlock;
    cmdMess(qMess5);
    cin >> quantity.reactorRednetPortBlock;
    quantity.blocksToRemove = quantity.reactorAccessPortBlock + quantity.reactorPowerTapBlock +
        + quantity.reactorCoolantPortBlock + quantity.reactorComputerPortBlock + quantity.reactorRednetPortBlock;
}

/**
 * @brief Wyświetlanie końcowego wyniku poszczególnych bloków
 * @param toChange - zmienna ilościowa bloku
 * @param choose - d instrukcji swith case
*/
void showEndingCount(int toChange, int choose) {
    int stackCount = toChange / 64;
    int restOfDivide = toChange % 64;
    int buckToMilibuck = toChange * 1000;
    switch (choose) {
        case 1:
            if (toChange <= 64) {
                cout << " (~ " << stackCount << " stacks)" << endl;
            }
            else {
                cout << " (~ " << stackCount << " stacks and " << restOfDivide << " pieces)" << endl;
            }
            break;
        case 2:
            cout << " (~ " << stackCount << " stacks and ";
            if (toChange <= 64) {
                 cout << buckToMilibuck << " milibuckets)" << endl;
            }
            else {
                cout << restOfDivide << " pieces and " << buckToMilibuck << " milibuckets)" << endl;
            }
            break;
    }
}

/**
 * @brief Funcje poszczególnych bloków reaktora, wyświetlające obliczoną końcową ilość produktów,
 * w tym zaokrągloną do całości liczbę stacków (64 sztuk). Niektóre funkcje nie wyświetlają się, jeśli
 * wartość zmiennej nadrzędnej wynosi 0.
*/
void reactorControllerBlockInfo(Data& var, BlocksQuantity& quantity) {
    cout << "  1x   Reactor Controller,";
    cout << " (~ 0 stacks)" << endl;
}

void reactorCasingBlockInfo(Data& var, BlocksQuantity& quantity) {
    cout << "  " << quantity.reactorCasingBlock << "x   Reactor Casing,";
    int toChange = quantity.reactorCasingBlock;
    int choose = 1;
    showEndingCount(toChange, choose);
}

void reactorGlassBlockInfo(Data& var, BlocksQuantity& quantity) {
    if (quantity.reactorGlassBlock != 0) {
        cout << "  " << quantity.reactorGlassBlock << "x   Reactor Glass,";
        int toChange = quantity.reactorGlassBlock;
        int choose = 1;
        showEndingCount(toChange, choose);
    }
    else {
        cout;
    }
}

void reactorControlRodBlockInfo(Data& var, BlocksQuantity& quantity) {
    cout << "  " << quantity.reactorControlRod << "x   Reactor Control Rod,";
    int toChange = quantity.reactorControlRod;
    int choose = 1;
    showEndingCount(toChange, choose);
}

void yelloriumFuelRodInfo(Data& var, BlocksQuantity& quantity) {
    cout << "  " << quantity.yelloriumFuelRod << "x    Yellorium Fuel Rod,";
    int toChange = quantity.yelloriumFuelRod;
    int choose = 1;
    showEndingCount(toChange, choose);
}

void reactorCoolantBlockInfo(Data& var, BlocksQuantity& quantity) {
    if (quantity.reactorCoolantBlock != 0) {
        cout << "  " << quantity.reactorCoolantBlock << "x    Coolant Metal Block,";
        int toChange = quantity.reactorCoolantBlock;
        int choose = 1;
        showEndingCount(toChange, choose);
    }
    else {
        cout;
    }
}

void bucketsOfLiquidInfo(Data& var, BlocksQuantity& quantity) {
    if (quantity.bucketsOfLiquid != 0) {
        cout << "  " << quantity.bucketsOfLiquid << "b    Coolant Liquid (buckets),";
        int toChange = quantity.bucketsOfLiquid;
        int choose = 2;
        showEndingCount(toChange, choose);
    }
    else {
        cout;
    }
}

void reactorAccessPortBlockInfo(Data& var, BlocksQuantity& quantity) {
    if (quantity.reactorAccessPortBlock != 0) {
        cout << "  " << quantity.reactorAccessPortBlock << "x   Reactor Access Port,";
        int toChange = quantity.reactorAccessPortBlock;
        int choose = 1;
        showEndingCount(toChange, choose);
    }
    else {
        cout;
    }
}

void reactorPowerTapBlock(Data& var, BlocksQuantity& quantity) {
    cout << "  " << quantity.reactorPowerTapBlock << "x   Reactor Power Tap,";
    int toChange = quantity.reactorPowerTapBlock;
    int choose = 1;
    showEndingCount(toChange, choose);
}

void reactorCoolantPortBlockInfo(Data& var, BlocksQuantity& quantity) {
    if (quantity.reactorCoolantPortBlock != 0) {
        cout << "  " << quantity.reactorCoolantPortBlock << "x   Reactor Coolant Port,";
        int toChange = quantity.reactorCoolantPortBlock;
        int choose = 1;
        showEndingCount(toChange, choose);
    }
    else {
        cout;
    }
}

void reactorComputerPortBlock(Data& var, BlocksQuantity& quantity) {
    if (quantity.reactorComputerPortBlock != 0) {
        cout << "  " << quantity.reactorComputerPortBlock << "x   Reactor ComputerCraft Port,";
        int toChange = quantity.reactorComputerPortBlock;
        int choose = 1;
        showEndingCount(toChange, choose);
    }
    else {
        cout;
    }
}

void reactorRednetPortBlock(Data& var, BlocksQuantity& quantity) {
    if (quantity.reactorRednetPortBlock != 0) {
        cout << "  " << quantity.reactorRednetPortBlock << "x   Reactor RedNet Port,";
        int toChange = quantity.reactorRednetPortBlock;
        int choose = 1;
        showEndingCount(toChange, choose);
    }
    else {
        cout;
    }
}

/**
 * @brief Funkcja wywołująca pokazywanie ilości odpowiednich bloków
*/
void informGlobalData(Data& var, BlocksQuantity& quantity) {
    cout << endl;
    cout << "For " << var.chooseType << " type of reactor, you will need:" << endl;
    reactorControllerBlockInfo(var, quantity);
    reactorCasingBlockInfo(var, quantity);
    reactorGlassBlockInfo(var, quantity);
    reactorControlRodBlockInfo(var, quantity);
    yelloriumFuelRodInfo(var, quantity);
    reactorCoolantBlockInfo(var, quantity);
    bucketsOfLiquidInfo(var, quantity);
    reactorAccessPortBlockInfo(var, quantity);
    reactorPowerTapBlock(var, quantity);
    reactorCoolantPortBlockInfo(var, quantity);
    reactorComputerPortBlock(var, quantity);
    reactorRednetPortBlock(var, quantity);
}

/**
 * @brief Trzy podobne funkcje stanowiące uzupełnienie różnicy poprzez metodę sprawdzania, 
 * czy liczba jest parzysta czy nie. 
*/
void divideNum1(Data& var, BlocksQuantity& quantity) {
    if (((var.x - 2) * (var.y - 2) % 2) == 0) {
        quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 4) * (var.y - 4) / 2);
        quantity.reactorControlRod = ((var.x - 4) * (var.y - 4) / 2);
        quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
        quantity.reactorCoolantBlock = quantity.yelloriumFuelRod;
    }
    else {
        quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 4) * (var.y - 4) / 2 + 1);
        quantity.reactorControlRod = ((var.x - 4) * (var.y - 4) / 2) + 1;
        quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
        quantity.reactorCoolantBlock = (quantity.reactorControlRod - 1) * (var.z - 2);
    }
}

void divideNum2(Data& var, BlocksQuantity& quantity) {
    if (((var.x - 2) * (var.y - 2) % 2) == 0) {
        quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 4) * (var.y - 2) / 2);
        quantity.reactorControlRod = ((var.x - 4) * (var.y - 2) / 2);
        quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
        quantity.reactorCoolantBlock = quantity.yelloriumFuelRod;
    }
    else {
        quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 4) * (var.y - 2) / 2 + 1);
        quantity.reactorControlRod = ((var.x - 4) * (var.y - 2) / 2) + 1;
        quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
        quantity.reactorCoolantBlock = quantity.yelloriumFuelRod;
    }
}

void divideNum3(Data& var, BlocksQuantity& quantity) {
    if (((var.x - 2) * (var.y - 2) % 2) == 0) {
        quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 2) * (var.y - 4) / 2);
        quantity.reactorControlRod = ((var.x - 2) * (var.y - 4) / 2);
        quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
        quantity.reactorCoolantBlock = quantity.yelloriumFuelRod;
    }
    else {
        quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 2) * (var.y - 4) / 2 + 1);
        quantity.reactorControlRod = ((var.x - 2) * (var.y - 4) / 2) + 1;
        quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
        quantity.reactorCoolantBlock = quantity.yelloriumFuelRod;
    }
}

/**
 * @brief Funkcja uzupełniająca (sześcian 3x3x3)
*/
void smallCube(Data& var, BlocksQuantity& quantity) {
    quantity.reactorControlRod = 1;
    quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
    quantity.bucketsOfLiquid = 0;
    quantity.reactorCoolantBlock = 0;
}

/**
 * @brief Generacja i obliczanie - pierwszy typ reaktora
*/
void typeFirst(Data& var, BlocksQuantity& quantity) {
    quantity.reactorCasingBlock = (2 * var.x + (var.y - 2) * 2) * 2 + (var.z - 2) * 4;
    quantity.reactorGlassBlock = (((var.x - 2) * (var.y - 2) * 2) + ((var.x - 2) * (var.z - 2)) * 2
        + ((var.y - 2) * (var.z - 2)) * 2) - quantity.blocksToRemove - 1;
    if ((var.x >= 5) && (var.y >= 5)) {
        quantity.bucketsOfLiquid = (((var.x - 2) * 2) * (var.z - 2)) + (((var.y - 4) * 2) * (var.z - 2));
        divideNum1(var, quantity);
    }
    else if ((var.x >= 5) && (var.y < 5)) {
        quantity.bucketsOfLiquid = ((var.y - 2) * (var.z - 2)) * 2;
        divideNum2(var, quantity);
    }
    else if ((var.x < 5) && (var.y >= 5)) {
        quantity.bucketsOfLiquid = ((var.x - 2) * (var.z - 2)) * 2;
        divideNum3(var, quantity);
    }
    else if (((var.x < 5) && (var.y <= 4)) || ((var.x <= 4) && (var.y < 5))) {
        if (var.x == 3 && var.y == 3) {
            quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 2) * (var.y - 2) / 2) - 2;
            smallCube(var, quantity);
        }
        else {
            quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 2) * (var.y - 2) / 2);
            quantity.reactorControlRod = ((var.x - 2) * (var.y - 2) / 2);
            quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
            quantity.bucketsOfLiquid = 0;
            if (var.x == 4 && var.y == 4) {
                quantity.reactorCoolantBlock = 2 * (var.z - 2);
            }
            else {
                quantity.reactorCoolantBlock = var.z - 2;
            }
        }
    } 
}

/**
 * @brief Generacja i obliczanie - drugi typ reaktora
*/
void typeSecond(Data& var, BlocksQuantity& quantity) {
    quantity.reactorCasingBlock = var.x * var.y + (var.x * (var.z - 1)) * 2 + ((var.y - 2) * (var.z - 1)) * 2
        - quantity.blocksToRemove - 1;
    quantity.reactorGlassBlock = (var.x - 2) * (var.y - 2);
    if ((var.x >= 5) && (var.y >= 5)) {
        quantity.bucketsOfLiquid = (((var.x - 2) * 2) * (var.z - 2)) + (((var.y - 4) * 2) * (var.z - 2));
        divideNum1(var, quantity);
    }
    else if ((var.x >= 5) && (var.y < 5)) {
        quantity.bucketsOfLiquid = ((var.y - 2) * (var.z - 2)) * 2;
        divideNum2(var, quantity);
    }
    else if ((var.x < 5) && (var.y >= 5)) {
        quantity.bucketsOfLiquid = ((var.x - 2) * (var.z - 2)) * 2;
        divideNum3(var, quantity);
    }
    else if (((var.x < 5) && (var.y <= 4)) || ((var.x <= 4) && (var.y < 5))) {
        if (var.x == 3 && var.y == 3) {
            quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 2) * (var.y - 2) / 2 - 1);
            smallCube(var, quantity);
        }
        else {
            quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 2) * (var.y - 2) / 2);
            quantity.reactorControlRod = ((var.x - 2) * (var.y - 2) / 2);
            quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
            quantity.bucketsOfLiquid = 0;
            if (var.x == 4 && var.y == 4) {
                quantity.reactorCoolantBlock = 2 * (var.z - 2);
            }
            else {
                quantity.reactorCoolantBlock = var.z - 2;
            }
        }
    }
}

/**
 * @brief Generacja i obliczanie - trzeci typ reaktora
*/
void typeThird(Data& var, BlocksQuantity& quantity) {
    quantity.reactorCasingBlock = (var.x * var.y) + (var.x * 2) + ((var.y - 2) * 2) + (var.z - 2) * 4;
    quantity.reactorGlassBlock = (((var.x - 2) * (var.y - 2)) + ((var.x - 2) * (var.z - 2)) * 2
        + ((var.y - 2) * (var.z - 2)) * 2) - quantity.blocksToRemove - 1;
    if ((var.x >= 5) && (var.y >= 5)) {
        quantity.bucketsOfLiquid = (((var.x - 2) * 2) * (var.z - 2)) + (((var.y - 4) * 2) * (var.z - 2));
        divideNum1(var, quantity);
    }
    else if ((var.x >= 5) && (var.y < 5)) {
        quantity.bucketsOfLiquid = ((var.y - 2) * (var.z - 2)) * 2;
        divideNum2(var, quantity);
    }
    else if ((var.x < 5) && (var.y >= 5)) {
        quantity.bucketsOfLiquid = ((var.x - 2) * (var.z - 2)) * 2;
        divideNum3(var, quantity);
    }
    else if (((var.x < 5) && (var.y <= 4)) || ((var.x <= 4) && (var.y < 5))) {
        if (var.x == 3 && var.y == 3) {
            quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 2) * (var.y - 2) / 2) - 2;
            smallCube(var, quantity);
        }
        else {
            quantity.reactorGlassBlock = quantity.reactorGlassBlock - ((var.x - 2) * (var.y - 2) / 2);
            quantity.reactorControlRod = ((var.x - 2) * (var.y - 2) / 2);
            quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
            quantity.bucketsOfLiquid = 0;
            if (var.x == 4 && var.y == 4) {
                quantity.reactorCoolantBlock = 2 * (var.z - 2);
            }
            else {
                quantity.reactorCoolantBlock = var.z - 2;
            }
        }
    }
}

/**
 * @brief Generacja i obliczanie - czwarty typ reaktora
*/
void typeFourth(Data& var, BlocksQuantity& quantity) {
    quantity.reactorCasingBlock = ((var.x * var.y) * 2 + (var.z - 2) * 4) - quantity.blocksToRemove - 1;
    quantity.reactorGlassBlock = 0;
    if ((var.x >= 5) && (var.y >= 5)) {
        quantity.bucketsOfLiquid = (((var.x - 2) * 2) * (var.z - 2)) + (((var.y - 4) * 2) * (var.z - 2));
        divideNum1(var, quantity);
    }
    else if ((var.x >= 5) && (var.y < 5)) {
        quantity.bucketsOfLiquid = ((var.y - 2) * (var.z - 2)) * 2;
        divideNum2(var, quantity);
    }
    else if ((var.x < 5) && (var.y >= 5)) {
        quantity.bucketsOfLiquid = ((var.x - 2) * (var.z - 2)) * 2;
        divideNum3(var, quantity);
    }
    else if (((var.x < 5) && (var.y <= 4)) || ((var.x <= 4) && (var.y < 5))) {
        if (var.x == 3 && var.y == 3) {
            quantity.reactorCasingBlock = quantity.reactorCasingBlock - ((var.x - 2) * (var.y - 2) / 2) - 1;
            smallCube(var, quantity);
        }
        else {
            quantity.reactorCasingBlock = quantity.reactorCasingBlock - ((var.x - 2) * (var.y - 2) / 2);
            quantity.reactorControlRod = ((var.x - 2) * (var.y - 2) / 2);
            quantity.yelloriumFuelRod = quantity.reactorControlRod * (var.z - 2);
            quantity.bucketsOfLiquid = 0;
            if (var.x == 4 && var.y == 4) {
                quantity.reactorCoolantBlock = 2 * (var.z - 2);
            }
            else {
                quantity.reactorCoolantBlock = var.z - 2;
            }
        }
    }
}

/**
 * @brief Przełącznik typów reaktora
*/
void chooseTypeFunction(Data &var, BlocksQuantity &quantity) {
    if (var.chooseType == 1) {
        typeFirst(var, quantity);
    }
    else if (var.chooseType == 2) {
        typeSecond(var, quantity);
    }
    else if (var.chooseType == 3) {
        typeThird(var, quantity);
    }
    else if (var.chooseType == 4) {
        typeFourth(var, quantity);
    }
    else {
        int choseMess = 1;
        cmdMess(choseMess);
        exit(0);
    }
}

/**
 * @brief Funkcja główna
*/
int main() {
    Data var;
    BlocksQuantity quantity;
    getData(var, quantity);
    chooseTypeFunction(var, quantity);
    informGlobalData(var, quantity);
}
