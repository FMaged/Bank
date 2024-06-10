#pragma once 
#include "ClsScreen.hh"
#include "ClsValidate.hh"
#include "ClsCurrency.hh"

class ClsUpdateRateScreen :protected ClsScreen {
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

	static float _readRate() {
		cout << "\nEnter New Rate: ";
		float newRate = ClsValidate::readFloatNumber();
		return newRate;
	}




public:
	static void showUpdateRateScreen() {
		_drawScreenHeader("\t     Update Rate Screen");
		cout << "\nPlease Enter Currency Code: ";
		string CurrencyCode = ClsValidate::readString();
		while (!ClsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency not found,choose another one OR Enter X to Exit: ";
			CurrencyCode = ClsValidate::readString();
		}
		ClsCurrency Currency = ClsCurrency::findByCode(CurrencyCode);
		_printCurrency(Currency);
		cout << "\nAre you sure you want to update the Rate of this Currency [Y - N]? ";
		char answer = ClsValidate::readY_OR_N();
		if (answer == 'Y') {
			cout << "\n\nUpdate Currency Rate:";
			cout<< "\n_____________________________\n";
			Currency.updateRate(_readRate());
			cout << "\nCurrency Rate Updated Successfully :-)";
			_printCurrency(Currency);
		}

	}


};