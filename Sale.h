#ifndef SALE_H
#define SALE_H

#include <string>

class Sale {
private:
    int bookingNumber;
    std::string customerID;
    std::string customerCard;

public:
    Sale(int bookingNumber, std::string customerID, std::string customerCard);

    int getBookingNumber() const;
    std::string getCustomerID() const;
    std::string getCustomerCard() const;

    void setBookingNumber(int bookingNumber);
    void setCustomerID(const std::string& customerID);
    void setCustomerCard(const std::string& customerCard);

    bool processPayment() const;
};

#endif // SALE_H
