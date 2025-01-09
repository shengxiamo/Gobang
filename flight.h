#ifndef FLIGHT_H
#define FLIGHT_H

// Qt
#include <QString>

class Flight {
private:
    QString flight_number;     // 航班号
    QString departure_city;    // 起飞城市
    QString arrival_city;      // 抵达城市
    QString departure_time;    // 起飞时间
    QString arrival_time;      // 抵达时间
    double price;              // 票价
    double discount;           // 折扣
    int total_seats;           // 座位总数
    int booked_seats;          // 已售座位数

public:
    Flight(const QString& flight_number, const QString& departure_city,
           const QString& arrival_city, const QString& departure_time,
           const QString& arrival_time, double price, double discount, int total_seats);


    // Getters
    QString getFlightNumber() const;
    QString getDepartureCity() const;
    QString getArrivalCity() const;
    QString getDepartureTime() const;
    QString getArrivalTime() const;
    double getPrice() const;
    double getDiscount() const;
    int getTotalSeats() const;
    int getBookedSeats() const;

    // Setters
    void setFlightNumber(const QString& new_flight_number);
    void setDepartureCity(const QString& new_departure_city);
    void setArrivalCity(const QString& new_arrival_city);
    void setDepartureTime(const QString& new_departure_time);
    void setArrivalTime(const QString& new_arrival_time);
    void setPrice(double new_price);
    void setDiscount(double new_discount);
    void setTotalSeats(int new_total_seats);
    void setBookedSeats(int new_booked_seats);

    // Business logic
    bool isFull() const;          // 检查航班是否满仓
    double getDiscountedPrice() const; // 获取折后票价

    QString toString() const;   // 返回整条航班信息
};

#endif // FLIGHT_H
