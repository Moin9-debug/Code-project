#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    string ticketID;
    string source;
    string destination;
    float distance;

public:
    void setTicketInfo() {
        cout << "Enter Ticket ID: ";
        cin >> ticketID;
        cout << "Enter Source: ";
        cin >> source;
        cout << "Enter Destination: ";
        cin >> destination;
        cout << "Enter Distance (km): ";
        cin >> distance;
    }

    void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "From: " << source << endl;
        cout << "To: " << destination << endl;
        cout << "Distance: " << distance << " km" << endl;
    }

    virtual float calculateFare() {
        return distance * 1.0;
    }
};

class TrainTicket : private Ticket {
private:
    string coachType;

public:
    void setTrainTicket() {
        setTicketInfo();
        cout << "Enter Coach Type (AC/Sleeper/General): ";
        cin >> coachType;
    }

    float calculateFare() override {
        float fare = distance * 1.0;

        if (coachType == "AC")
            fare += 200;
        else if (coachType == "Sleeper")
            fare += 100;

        return fare;
    }

    void displayTrainTicket() {
        cout << "\n---- Train Ticket Details ----\n";
        displayTicketInfo();
        cout << "Coach Type: " << coachType << endl;
        cout << "Total Fare: " << calculateFare() << " tk\n";
    }
};

class FlightTicket : protected Ticket {
private:
    string seatClass;
    float luggageWeight;
public:
    void setFlightTicket() {
        setTicketInfo();
        cout << "Enter Seat Class (Economy/Business): ";
        cin >> seatClass;
        cout << "Enter Luggage Weight (kg): ";
        cin >> luggageWeight;
    }

    float calculateFare() override {
        float fare = distance * 25.0; // base

        if (seatClass == "Business")
            fare += 20000;

        if (luggageWeight > 20)
            fare += (luggageWeight - 20) * 5000;

        return fare;
    }

    void displayFlightTicket() {
        cout << "\n---- Flight Ticket Details ----\n";
        displayTicketInfo();
        cout << "Seat Class: " << seatClass << endl;
        cout << "Luggage Weight: " << luggageWeight << " kg\n";
        cout << "Total Fare: " << calculateFare() << " tk\n";
    }
};


int main() {
    TrainTicket t1;
    FlightTicket f1;

    cout << "\n--- Enter Train Ticket Info ---\n";
    t1.setTrainTicket();

    cout << "\n--- Enter Flight Ticket Info ---\n";
    f1.setFlightTicket();

    t1.displayTrainTicket();
    f1.displayFlightTicket();

    return 0;
}
