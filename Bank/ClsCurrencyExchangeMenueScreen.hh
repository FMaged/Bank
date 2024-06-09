#pragma once
#include <iomanip>
#include "ClsScreen.hh"






class ClsCurrencyExchangeScreen :protected ClsScreen {
private:
	enum enCurrencyExchangeOption { eCurrenciesList = 1, eFindCurrency=2, eUpdateRate=3,eCalculator=4,eMainMenue=5};
	static short _readCurrencyExchangeMenueOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = ClsValidate::readIntNumberBetween(1, 5, "Enter Number between 1 to 5?");
		return Choice;
	}

	static void _goBackToCurrencyExchangeScreen() {
		system("pause");
		showCurrencyExchange();
	}
	static void _showCurrencyListScreen() {
		cout << "Currency List Screen will be here!\n";
	}
	static void _showFindCurrencyScreen() {
		cout << "Find Currency Screen will be here!\n";
	}
	static void _showUpdateRateScreen() {
		cout << "Update Currency Rate Screen will be here!\n";
	}
	static void _showCurrencyCalculatorScreen() {
		cout << "Calculator Screen will be here!\n";
	}
	static  void _showMainMenueScreen() {
		//dont need to do anything it will go back to the main menue. 
	}




	static void _prefomCurrencyExchangeScreen(enCurrencyExchangeOption CurrencyExchangeMenueOption) {
		switch (CurrencyExchangeMenueOption)
		{
		case ClsCurrencyExchangeScreen::eCurrenciesList:
			system("cls");
			_showCurrencyListScreen();
			_goBackToCurrencyExchangeScreen();
			break;
		case ClsCurrencyExchangeScreen::eFindCurrency:
			system("cls");
			_showFindCurrencyScreen();
			_goBackToCurrencyExchangeScreen();
			break;
		case ClsCurrencyExchangeScreen::eUpdateRate:
			system("cls");
			_showUpdateRateScreen();
			_goBackToCurrencyExchangeScreen();
			break;
		case ClsCurrencyExchangeScreen::eCalculator:
			system("cls");
			_showCurrencyCalculatorScreen();
			_goBackToCurrencyExchangeScreen();
			break;
		case ClsCurrencyExchangeScreen::eMainMenue:
			system("cls");
			_showMainMenueScreen();
			break;

		}
	}





public:

	static void showCurrencyExchange() {
		if (!checkAccessRight(ClsUser::enPermission::pManageUser)) {
			return;
		}
		system("cls");
		_drawScreenHeader("Currency Exchange Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Currencies List.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_prefomCurrencyExchangeScreen((enCurrencyExchangeOption)_readCurrencyExchangeMenueOption());
	}







};