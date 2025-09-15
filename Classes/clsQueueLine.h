#pragma once
#include <string>
#include "clsDate.h"
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;
class clsQueueLine
{
private:
	string _Prefix;
	int    _ServedClients = 0;
	int    _WaitingTime;
	int    _Counter = 0;

	class clsTicket
	{
	public:
		string _Code;
		string _TimeAndDate;
		int _ServeTime;
		int _CountCode;

		friend class clsQueueLine;

		clsTicket(string prefix,int Counter,int WaitingTime)
		{
			this->_CountCode = Counter;
			this->_Code = prefix + to_string(this->_CountCode + 1);
			this->_TimeAndDate = clsDate::GetSystemDateTimeString();
			this->_ServeTime = WaitingTime * (this->_CountCode);
		}

		void PrintTicketDetails()
		{
			cout << setw(30) << left << "" << "____________________________________\n\n";
			clsQueueLine::FormatFun(); cout << setw(8)<<""<< _Code << "\n\n";
			clsQueueLine::FormatFun(); cout << _TimeAndDate << "\n";
			clsQueueLine::FormatFun(); cout << "Waiting Clients : " << _CountCode << "\n";
			clsQueueLine::FormatFun(); cout << "   Serving Time In" << "\n";
			clsQueueLine::FormatFun(); cout <<setw(6)<<left<<""<< _ServeTime <<" Minutes.\n";
			cout << setw(30) << left << "" << "____________________________________\n\n";
		}
	};

	queue <clsTicket> qTicket;

public: 
	clsQueueLine(string Prefix,int WaintingTime)
	{
		this->_Prefix = Prefix;
		this->_WaitingTime = WaintingTime;
	}

	void IssueTicket()
	{
		clsTicket tick = clsTicket(_Prefix,_Counter,_WaitingTime);
		_Counter++;
		qTicket.push(tick);
	}


	static void FormatFun()
	{
		cout << setw(35) << left << "";
	}

	void PrintInfo()
	{
		cout << setw(30) << left << "" << "____________________________________\n\n";
		cout << setw(30) << left << "" << "\t\tQueue Info\n";
		cout << setw(30) << left << "" << "____________________________________\n\n";
		cout << setw(30) << left << "" << setw(3) << left << "" << "Prefix : " << _Prefix<<"\n";
		cout << setw(30) << left << "" << setw(3) << left << "" << "Total Tickets : " << _Counter << "\n";
		cout << setw(30) << left << "" << setw(3) << left << "" << "Served Clients : " << _ServedClients << "\n";
		cout << setw(30) << left << "" << setw(3) << left << "" << "Waiting Clients : " << WaitingClients() << "\n";
		cout << setw(30) << left << "" << "____________________________________\n\n";
	}

	void PrintTicketsLineRTL()
	{
		cout << endl;
		queue <clsTicket> qtemp;
		qtemp = qTicket;
		cout << setw(15) << left << "" << "Tickets :  ";
		while (!qtemp.empty())
		{
			clsTicket CodeOfTicket = qtemp.front();
			cout << " " << CodeOfTicket._Code << " <--";
			qtemp.pop();
		}
		cout << endl;
	}

	void PrintTicketsLineLTR()
	{
		cout << endl;
		stack <clsTicket> stemp;
		queue <clsTicket> qtemp;
		qtemp = qTicket;
		while (!qtemp.empty())
		{
			stemp.push(qtemp.front());
			qtemp.pop();
		}
		cout << setw(15) << left << "" << "Tickets :  ";
		while (!stemp.empty())
		{
			clsTicket CodeOfTicket = stemp.top();
			cout << " " << CodeOfTicket._Code << " -->";
			stemp.pop();
		}
		cout << endl;
	}

	void PrintAllTickets()
	{
		queue <clsTicket> qtemp;
		qtemp = qTicket;
		cout << "\n\n";  FormatFun(); cout << "   ---Tickets---" << "\n\n";
		while (!qtemp.empty())
		{
			qtemp.front().PrintTicketDetails();
			qtemp.pop();
		}
	}

	int WaitingClients()
	{
		return qTicket.size();
	}


	void ServeNextClient()
	{
		qTicket.pop();
	}

};

