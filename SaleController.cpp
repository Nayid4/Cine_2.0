#include "SaleController.h"
#include <stdexcept>

SaleController& SaleController::getInstance() {
    static SaleController instance;
    return instance;
}

SaleController::SaleController() {}

void SaleController::addSale(const Sale& sale) {
    sales.push_back(sale);
}

Sale SaleController::getSale(int index) const {
    if (index >= 0 && index < sales.size()) {
        return sales[index];
    }
    throw std::out_of_range("Index out of range");
}

void SaleController::updateSale(int index, const Sale& sale) {
    if (index >= 0 && index < sales.size()) {
        sales[index] = sale;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

void SaleController::deleteSale(int index) {
    if (index >= 0 && index < sales.size()) {
        sales.erase(sales.begin() + index);
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

size_t SaleController::getSaleCount() const {
    return sales.size();
}
