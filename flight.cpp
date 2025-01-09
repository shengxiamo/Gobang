#include "flight.h"

// 构造函数
Flight::Flight(const QString& flight_number, const QString& departure_city,
               const QString& arrival_city, const QString& departure_time,
               const QString& arrival_time, double price, double discount, int total_seats)
    : flight_number(flight_number), departure_city(departure_city),
    arrival_city(arrival_city), departure_time(departure_time),
    arrival_time(arrival_time), price(price), discount(discount),
    total_seats(total_seats), booked_seats(0) {}

// Getters
QString Flight::getFlightNumber() const {
    return flight_number;
}

QString Flight::getDepartureCity() const {
    return departure_city;
}

QString Flight::getArrivalCity() const {
    return arrival_city;
}

QString Flight::getDepartureTime() const {
    return departure_time;
}

QString Flight::getArrivalTime() const {
    return arrival_time;
}

double Flight::getPrice() const {
    return price;
}

double Flight::getDiscount() const {
    return discount;
}

int Flight::getTotalSeats() const {
    return total_seats;
}

int Flight::getBookedSeats() const {
    return booked_seats;
}

// Setters
void Flight::setFlightNumber(const QString& new_flight_number) {
    flight_number = new_flight_number;
}

void Flight::setDepartureCity(const QString& new_departure_city) {
    departure_city = new_departure_city;
}

void Flight::setArrivalCity(const QString& new_arrival_city) {
    arrival_city = new_arrival_city;
}

void Flight::setDepartureTime(const QString& new_departure_time) {
    departure_time = new_departure_time;
}

void Flight::setArrivalTime(const QString& new_arrival_time) {
    arrival_time = new_arrival_time;
}

void Flight::setPrice(double new_price) {
    price = new_price;
}

void Flight::setDiscount(double new_discount) {
    discount = new_discount;
}

void Flight::setTotalSeats(int new_total_seats) {
    total_seats = new_total_seats;
}

void Flight::setBookedSeats(int new_booked_seats) {
    booked_seats = new_booked_seats;
}

// Business logic
bool Flight::isFull() const {
    return booked_seats >= total_seats;
}

double Flight::getDiscountedPrice() const {
    return price * discount;
}

QString Flight::toString() const {
    return flight_number + "," +
           departure_city + "," +
           arrival_city + "," +
           departure_time + "," +
           arrival_time + "," +
           QString::number(price, 'f', 2) + "," +
           QString::number(discount, 'f', 2) + "," +
           QString::number(total_seats) + "," +
           QString::number(booked_seats);
}
