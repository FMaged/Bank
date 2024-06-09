#pragma once 
#include "ClsScreen.hh"
#include "ClsUser.hh"
#include "ClsDate.hh"

#include <iomanip>

class ClsLoginRegisterScreen :protected ClsScreen {
private:



	static void _printLoginRecordLine(ClsUser::stLoginRegisterRecord LoginRegisterRecord) {
		cout << "\t| " << setw(40) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Permission;
	}















public:
	static void showLoginRegisterScreen() {
		if (!checkAccessRight(ClsUser::enPermission::pListUser)) {
			return;
		}
		vector<ClsUser::stLoginRegisterRecord> vLoginRegisterRecord = ClsUser::getLoginRegisterList();
		string title = "\t  Login Register Screen";
		string supTitle= "\t    (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";
		_drawScreenHeader(title,supTitle);
		
		cout << setw(8) << left << "\n\t____________________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t| " << left << setw(40) << "Time";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(20) << "Permission";
		cout << setw(8) << left << "\n\t____________________________________________________________";
		cout << "_________________________________________\n" << endl;
		
		for (ClsUser::stLoginRegisterRecord Record : vLoginRegisterRecord) {
			_printLoginRecordLine(Record);
			cout << endl;
		}
		cout << setw(8) << left << "\n\t____________________________________________________________";
		cout << "_________________________________________\n" << endl;




	}	






};