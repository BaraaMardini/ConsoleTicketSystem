#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
#include "ClsDate.h"
using namespace std;
class clsQueueLine

{

private:
	short TotalTickets;
	short AverageServeTime;
	string Prefix;




	class clsTicket {
	private:
		short   Number;
		string   Prefix;

		string   TicketTime;

		short WaitngClients = 0;
		short AverageServeTime;
		short ExpectedServeTime;




	public:

		clsTicket(short Number, string Prefix, string TicketTime, short WaitingClients, short AverageServeTime, short ExpectedServeTime) {
			this->Number = Number;
			this->Prefix = Prefix;
			this->TicketTime = TicketTime;
			this->WaitngClients = WaitingClients;
			this->AverageServeTime = AverageServeTime;
			this->ExpectedServeTime = ExpectedServeTime;

		}
		int  NumberOfTicket() {
			return (this->Number);
		}

		void PrintInfo() {
			cout << "\t\t\t\t\t" << "------------------------------------" << endl;


			cout << "\t\t\t\t\t\t" << "      " << Prefix << this->Number << endl;
			cout << "\t\t\t\t\t\t" << this->TicketTime << endl;
			cout << "\t\t\t\t\t\t" << "Wating Clients " << this->WaitngClients << endl;
			cout << "\t\t\t\t\t\t    " << "Serve Time In" << endl;
			cout << "\t\t\t\t\t\t  " << "   " << this->ExpectedServeTime << endl;
			cout << "\t\t\t\t\t" << "------------------------------------" << endl;
		}



		string FullNumber()
		{
			return this->Prefix + to_string(this->Number);
		}

		void EditTime(short Time) {
			this->ExpectedServeTime -= Time;
		}
	};







public:

	clsQueueLine(short TotalTickets, short AverageServeTime, string Prefix) {
		this->TotalTickets = TotalTickets;
		this->AverageServeTime = AverageServeTime;
		this->Prefix = Prefix;
	}
	queue<clsTicket> QueueLine;





	string WhoIsNext() {

		return this->Prefix + to_string(QueueLine.size() + 2);
	}
	short ServedClients() {
		return this->TotalTickets - QueueLine.size();
	}
	void IssueTicket() {

		short NumberOfTicket = QueueLine.size() + 1;
		string TimeNow;
		ClsDate date;
		TimeNow = date.GetSystemDateTimeString();
		short  waitingClients2 = QueueLine.size();
		short AverageServeTime = this->AverageServeTime;
		short ExpectedServeTime = QueueLine.size() * this->AverageServeTime;

		clsTicket NewTicket(NumberOfTicket, this->Prefix, TimeNow, waitingClients2, AverageServeTime, ExpectedServeTime);


		QueueLine.push(NewTicket);









	}
	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;

		queue<clsTicket> Temp;

		while (!QueueLine.empty())
		{
			clsTicket t = QueueLine.front();
			QueueLine.pop();

			t.EditTime(this->AverageServeTime);
			Temp.push(t);
		}

		QueueLine = Temp;

		QueueLine.pop();

		return true;
	}
	void PrintQueueInfo() {
		cout << "Pay Bills queue Info :" << endl << endl;
		cout << "\t\t\t\t\t" << "--------------------------------" << endl;
		cout << "\t\t\t\t\t" << "          Queue Info       " << endl;
		cout << "\t\t\t\t\t" << "--------------------------------" << endl;
		cout << "\t\t\t\t\t" << "      " << "Prifix   =" << this->Prefix << endl;
		cout << "\t\t\t\t\t" << "      " << "Total Tickets   = " << this->TotalTickets << endl;

		cout << "\t\t\t\t\t" << "      " << "Server Tickets   = " << this->TotalTickets - QueueLine.size() << endl;
		cout << "\t\t\t\t\t" << "      " << "Wating Clients   = " << QueueLine.size() << endl;

		cout << "\t\t\t\t\t" << "--------------------------------" << endl;

	}


	void PrintTicketsLineRTL2() {
		if (QueueLine.empty()) {
			cout << "\n\t\tTickets: No Tickets.";
		}
		else {
			cout << "\n\t\t\t\t\tTickets:";
			queue<clsTicket> NewQueueLine = QueueLine;
			while (!NewQueueLine.empty()) {

				cout << " " << NewQueueLine.front().FullNumber() << " <-- ";
				NewQueueLine.pop();
			}










		}


	}






	void PrintTicketsLineRTL()
	{

		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\t\t\t\tTickets:";


		queue <clsTicket> TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			clsTicket Ticket = TempQueueLine.front();

			cout << " " << Ticket.FullNumber() << " <-- ";

			TempQueueLine.pop();
		}

		cout << "\n";

	}













	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\t\t\t\n\t\t\t\t\tTickets:";


		queue <clsTicket> TempQueueLine = QueueLine;
		stack <clsTicket> TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStackLine.empty())
		{
			clsTicket Ticket = TempStackLine.top();

			cout << " " << Ticket.FullNumber() << " --> ";

			TempStackLine.pop();
		}
		cout << "\n";
	}


	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t                        ---Tickets---" << endl;;

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().PrintInfo();
			TempQueueLine.pop();
		}

	}

};