#ifndef ROOM_H
#define ROOM_H

class Room {
private:
    int number;
    int seatCount;
    float price;

public:
    Room(int number, int seatCount, float price);

    int getNumber() const;
    int getSeatCount() const;
    float getPrice() const;

    void setNumber(int number);
    void setSeatCount(int seatCount);
    void setPrice(float price);
};

#endif // THEATERROOM_H
