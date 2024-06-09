#pragma once 
#include <iomanip>
#include "ClsScreen.hh"
#include "ClsCurrency.hh"


class ClsCurrencyListScrren :protected ClsScreen {
private:
    static void _printCurrencyRecordLine(ClsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.getCountry();
        cout << "| " << setw(8) << left << Currency.getCurrencyCode();
        cout << "| " << setw(45) << left << Currency.getCurrencyName();
        cout << "| " << setw(10) << left << Currency.getRate();

    }










public:
    static void showCurrencyListScreen() {
        vector<ClsCurrency>vCurrencies = ClsCurrency::getCurrenciesList();
        string title = "Currencies List Screen";
        string subTitle= "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _drawScreenHeader(title,subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;
        
        for (ClsCurrency C : vCurrencies) {
            _printCurrencyRecordLine(C);
            cout << endl;
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;
    }







};