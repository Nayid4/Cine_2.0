#ifndef SALESMANAGER_H
#define SALESMANAGER_H

#include "SaleController.h"

class SalesManager {
public:
    void addSale();
    void listSales() const;
    void updateSale();
    void deleteSale();
    void manageSales();

private:
    int getSaleIndex() const;
    void getSaleInput(Sale& sale) const;
};

#endif // SALESMANAGER_H
