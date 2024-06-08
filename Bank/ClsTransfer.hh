#pragma once 
#include "ClsScreen.hh"
#include "ClsClient.hh"
#include "ClsValidate.hh"

class ClsTransferScreen :protected ClsScreen {
private:

	static string _readAccountNumber() {
		cout << "\nPlease Enter Account Number to Transfer From : ";
		string accountNumber = ClsValidate::readString();
		while (!ClsClient::isClientExist(accountNumber)){
			cout<<"\nAccount number is not found, choose another one : ";
			accountNumber = ClsValidate::readString();
		}
		return accountNumber;
	}

	static float _readAmount(ClsClient SourceCllient) {
		cout<< "\nEnter Transfer Amount? ";
		float amount = ClsValidate::readFloatNumber();
		while (amount > SourceCllient.getBalance()) {
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			amount = ClsValidate::readFloatNumber();
		}
		return amount;
	}

	static void _printClient(ClsClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.getFullName();
		cout << "\nAcc. Number : " << Client.getAccountNumber();
		cout << "\nBalance     : " << Client.getBalance();
		cout << "\n___________________\n";

	}











	



public:
	static void showTransferScreen() {
		_drawScreenHeader("\t     Transfer Screen");
		ClsClient SourceClient = ClsClient::find(_readAccountNumber());
		_printClient(SourceClient);
		ClsClient destinationClient = ClsClient::find(_readAccountNumber());
		_printClient(destinationClient);
		float Amount = _readAmount(SourceClient);
		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char answer = ClsValidate::readY_OR_N();
		if (answer == 'Y') {
			if (SourceClient.transfer(Amount, destinationClient,CurrentUser.getUserName())) {
				cout << "\nTransfer done successfully\n";
			}
			else {
				cout << "\nTransfer Faild \n";
			}
		}
		_printClient(SourceClient);
		_printClient(destinationClient);

	}














};