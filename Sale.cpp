#include "Sale.h"

Sale::Sale(int bookingNumber, std::string customerID, std::string customerCard)
    : bookingNumber(bookingNumber), customerID(customerID), customerCard(customerCard) {}

int Sale::getBookingNumber() const {
    return bookingNumber;
}

std::string Sale::getCustomerID() const {
    return customerID;
}

std::string Sale::getCustomerCard() const {
    return customerCard;
}

void Sale::setBookingNumber(int bookingNumber) {
    this->bookingNumber = bookingNumber;
}

void Sale::setCustomerID(const std::string& customerID) {
    this->customerID = customerID;
}

void Sale::setCustomerCard(const std::string& customerCard) {
    this->customerCard = customerCard;
}

bool Sale::processPayment() const {
    // Simulate payment processing logic
    return true; // Assuming the payment is always successful
}
