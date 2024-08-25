#ifndef THEATERROOM_H
#define THEATERROOM_H

class TheaterRoom {
private:
    int number;
    int seatCount;
    float price;

public:
    TheaterRoom(int number, int seatCount, float price);

    int getNumber() const;
    int getSeatCount() const;
    float getPrice() const;

    void setNumber(int number);
    void setSeatCount(int seatCount);
    void setPrice(float price);
};

#endif // THEATERROOM_H
