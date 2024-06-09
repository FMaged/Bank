#pragma once 
#include "ClsScreen.hh"
#include "ClsCurrency.hh"
#include "ClsValidate.hh"


class ClsFindCurrencyScreen :protected ClsScreen {
private:
    static void _printCurrency(ClsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.getCountry();
        cout << "\nCode       : " << Currency.getCurrencyCode();
        cout << "\nName       : " << Currency.getCurrencyName();
        cout << "\nRate(1$) = : " << Currency.getRate();

        cout << "\n_____________________________\n";

    }

    static void _showResults(ClsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _printCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found, do you want To try again [Y - N]:-(\n";
            char answer = ClsValidate::readY_OR_N();
            if (answer == 'Y') {
                showFindCurrencyScreen();
            }
            else {
                return;
            }
            
            
        }
    }





public:
	static void showFindCurrencyScreen() {
		_drawScreenHeader("\t     Find Currency Screen");
        cout << "\nEnter Currency Code OR Country Name to search? ";
        string answer=ClsValidate::readString();
        ClsCurrency Currency = ClsCurrency::find(answer);
        _showResults(Currency);



	}




};