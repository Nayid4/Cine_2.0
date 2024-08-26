#include "SalesManager.h"
#include <iostream>
#include <stdexcept>

void SalesManager::addSale() {
    Sale sale(0, "", ""); // Inicializa con valores predeterminados
    getSaleInput(sale);

    // Procesar el pago
    if (sale.processPayment()) {
        SaleController::getInstance().addSale(sale);
        std::cout << "Venta agregada exitosamente.\n";
    }
    else {
        std::cout << "Error en el procesamiento del pago.\n";
    }
}

void SalesManager::listSales() const {
    SaleController& controller = SaleController::getInstance();
    size_t count = controller.getSaleCount();

    if (count == 0) {
        std::cout << "No hay ventas disponibles.\n";
        return;
    }

    std::cout << "\n===== Lista de Ventas =====\n";
    for (size_t i = 0; i < count; ++i) {
        Sale sale = controller.getSale(i);
        std::cout << i + 1 << ". Numero de Reserva: " << sale.getBookingNumber()
            << ", ID Cliente: " << sale.getCustomerID()
            << ", Tarjeta Cliente: " << sale.getCustomerCard() << '\n';
    }
}

void SalesManager::updateSale() {
    int index = getSaleIndex();
    if (index < 0) return;

    Sale updatedSale(0, "", ""); // Inicializa con valores predeterminados
    getSaleInput(updatedSale);

    // Procesar el pago
    if (updatedSale.processPayment()) {
        SaleController::getInstance().updateSale(index, updatedSale);
        std::cout << "Venta actualizada exitosamente.\n";
    }
    else {
        std::cout << "Error en el procesamiento del pago.\n";
    }
}

void SalesManager::deleteSale() {
    int index = getSaleIndex();
    if (index < 0) return;

    SaleController::getInstance().deleteSale(index);
    std::cout << "Venta eliminada exitosamente.\n";
}

void SalesManager::manageSales() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "\n===== Gestion de Ventas =====\n";
        std::cout << "1. Agregar Venta\n";
        std::cout << "2. Listar Ventas\n";
        std::cout << "3. Actualizar Venta\n";
        std::cout << "4. Eliminar Venta\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> choice;

        switch (choice) {
        case 1: addSale(); break;
        case 2: listSales(); break;
        case 3: updateSale(); break;
        case 4: deleteSale(); break;
        case 5: std::cout << "Volviendo al menu principal...\n"; break;
        default: std::cout << "Opción invalida. Intente de nuevo.\n";
        }
    }
}

int SalesManager::getSaleIndex() const {
    listSales();
    SaleController& controller = SaleController::getInstance();
    size_t count = controller.getSaleCount();

    int index;
    std::cout << "Ingrese el numero de la venta a modificar/eliminar: ";
    std::cin >> index;
    if (index < 1 || index > static_cast<int>(count)) {
        std::cout << "Indice no valido.\n";
        return -1;
    }

    return index - 1;
}

void SalesManager::getSaleInput(Sale& sale) const {
    int bookingNumber;
    std::string customerID, customerCard;

    std::cout << "Ingrese el numero de reserva: ";
    std::cin >> bookingNumber;
    sale.setBookingNumber(bookingNumber);

    std::cout << "Ingrese el ID del cliente: ";
    std::cin.ignore(); // Limpiar el buffer
    std::getline(std::cin, customerID);
    sale.setCustomerID(customerID);

    std::cout << "Ingrese el numero de tarjeta del cliente: ";
    std::getline(std::cin, customerCard);
    sale.setCustomerCard(customerCard);
}
