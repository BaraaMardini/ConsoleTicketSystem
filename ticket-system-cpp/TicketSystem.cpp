#include <iostream>
#include "clsQueueLine.h"
using namespace std;


int main() {
    clsQueueLine PayBillsQueue(5, 10, "A0");
    clsQueueLine SubscriptionsQueue(3, 5, "B0");

    for (int i = 0; i < 5; i++) {
        PayBillsQueue.IssueTicket();
    }


    PayBillsQueue.PrintQueueInfo();
    PayBillsQueue.PrintTicketsLineRTL2();
    PayBillsQueue.PrintTicketsLineLTR();
    PayBillsQueue.PrintAllTickets();

    cout << endl << endl << endl;

    for (int i = 0; i < 3; i++) {
        SubscriptionsQueue.IssueTicket();
    }


    SubscriptionsQueue.PrintQueueInfo();
    SubscriptionsQueue.PrintTicketsLineRTL2();
    SubscriptionsQueue.PrintTicketsLineLTR();
    SubscriptionsQueue.PrintAllTickets();


    cout << endl << endl << endl;

    SubscriptionsQueue.ServeNextClient();


    cout << "\nSubscriptions Queue After Serving One client\n";
    SubscriptionsQueue.PrintQueueInfo();



}