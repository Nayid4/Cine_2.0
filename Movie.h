#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    std::string name;
    int year;
    int duration;
    std::string country;
    std::string review;

public:
    Movie(std::string name, int year, int duration, std::string country, std::string review);

    std::string getName() const;
    int getYear() const;
    int getDuration() const;
    std::string getCountry() const;
    std::string getReview() const;

    void setName(const std::string& name);
    void setYear(int year);
    void setDuration(int duration);
    void setCountry(const std::string& country);
    void setReview(const std::string& review);
};

#endif // MOVIE_H
