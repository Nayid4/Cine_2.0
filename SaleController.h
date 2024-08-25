#ifndef SALECONTROLLER_H
#define SALECONTROLLER_H

#include "Sale.h"
#include <vector>

class SaleController {
public:
    static SaleController& getInstance();

    void addSale(const Sale& sale);
    Sale getSale(int index) const;
    void updateSale(int index, const Sale& sale);
    void deleteSale(int index);
    size_t getSaleCount() const;

private:
    SaleController();
    std::vector<Sale> sales;
};

#endif // SALECONTROLLER_H
