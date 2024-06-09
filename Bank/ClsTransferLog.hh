#pragma once
#include "ClsScreen.hh"
#include "ClsClient.hh"
#include "ClsDate.hh"
#include <iomanip>


class ClsTransferLogScreen :protected ClsScreen {
private:
	static void _printTransferLogRecord(ClsClient::stTransferLogRecord TranferLogRecord) {
		cout << "\t| " << left << setw(25) << TranferLogRecord.dateTime;
		cout << "| " << left << setw(10) << TranferLogRecord.sourceAccountNumber;
		cout << "| " << left << setw(10) << TranferLogRecord.destinationAccountNumber;
		cout << "| " << left << setw(10) << TranferLogRecord.amount;
		cout << "| " << left << setw(12) << TranferLogRecord.srcBalanceAfter;
		cout << "| " << left << setw(12) << TranferLogRecord.destBalanceAfter;
		cout << "| " << left << setw(10) << TranferLogRecord.userName;
	}














public:
	static void showTransferLogScreen() {
		vector<ClsClient::stTransferLogRecord>vTransferLogRecord = ClsClient::getTransferLogList();
		string title = "\t  Transfer Log List Screen";
		string subTitle= "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";
		_drawScreenHeader(title, subTitle);
		cout << setw(8) << left << "\n\t____________________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t| " << left << setw(25) << "Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << setw(8) << left << "\n\t____________________________________________________________";
		cout << "_________________________________________\n" << endl;
		for (ClsClient::stTransferLogRecord TransferLogRecord : vTransferLogRecord) {
			_printTransferLogRecord(TransferLogRecord);
			cout << endl;
		}
		cout << setw(8) << left << "\n\t____________________________________________________________";
		cout << "_________________________________________\n" << endl;
	}






};