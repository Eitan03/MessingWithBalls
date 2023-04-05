#pragma once
#include <iostream>

template<typename T>
class Point {
public:
    T x;
    T y;

    Point() : x{}, y{} {}            // default
    Point(T x, T y) : x{ x }, y{ y } {}  // conversion
    Point(const Point& p) { x = p.x; y = p.y; } //copy

    Point<T>& operator=(const Point<T>& rhs) {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }

    Point<T>& operator+=(const Point<T>& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Point<T>& operator-=(const Point<T>& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }


    Point<T>& operator*=(const Point<T>& rhs) {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }


    Point<T>& operator/=(const Point<T>& rhs) {
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    
    }
    // for printing a point:
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
        return os << '(' << p.x << ',' << p.y << ')';
    }


    template<typename R>
    // for conversion:
    explicit operator Point<R>() {
        return Point<R>(static_cast<R>(x), static_cast<R>(y));
    }

};

template<typename T>
auto operator+(const Point<T>& lhs, const Point<T>& rhs) {
    Point<T> rv = lhs;
    rv += rhs;
    return rv;
}

template<typename T>
auto operator-(const Point<T>& lhs, const Point<T>& rhs) {
    Point<T> rv = lhs;
    rv -= rhs;
    return rv;
}

template<typename T>
auto operator*(const Point<T>& lhs, const Point<T>& rhs) {
    Point<T> rv = lhs;
    rv *= rhs;
    return rv;
}

template<typename T>
auto operator/(const Point<T>& lhs, const Point<T>& rhs) {
    Point<T> rv = lhs;
    rv /= rhs;
    return rv;
}

//add something that isnt a point
template<typename T>
auto operator+(const Point<T>& lhs, T rhs) {
    Point<T> rv = lhs;
    rv.x += rhs;
    rv.y += rhs;
    return rv;
}

template<typename T>
auto operator-(const Point<T>& lhs, T rhs) {
    Point<T> rv = lhs;
    rv.x -= rhs;
    rv.y -= rhs;
    return rv;
}

template<typename T>
auto operator*(const Point<T>& lhs, T rhs) {
    Point<T> rv = lhs;
    rv.x *= rhs;
    rv.y *= rhs;
    return rv;
}

template<typename T>
auto operator/(const Point<T>& lhs, T rhs) {
    Point<T> rv = lhs;
    rv.x /= rhs;
    rv.y /= rhs;
    return rv;
}
//comapre
template<typename T>
auto operator==(const Point<T>& lhs, const Point<T>& rhs) {
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}

template<typename T>
auto operator<(const Point<T>& lhs, const Point<T>& rhs) {
    return lhs.x < rhs.x || (rhs.x == lhs.x && rhs.y < lhs.y);
}

//math functions
template<typename T>
Point<T> floor(const Point<T>& lhs) {
    return Point<T>(floor(lhs.x), floor(lhs.y));
}

template<typename T>
Point<T> round(const Point<T>& lhs) {
    return Point<T>(round(lhs.x), round(lhs.y));
}

template<typename T>
Point<T> abs(const Point<T>& lhs) {
    return Point<T>(abs(lhs.x), abs(lhs.y));
}

//vector functions
template<typename T>
int magnitude(const Point<T>& lhs) {
    return sqrt(lhs.x * lhs.x + lhs.y * lhs.y);
}

template<typename T>
int sqrMagnitude(const Point<T>& lhs) { //cheaper then magnitude
    return lhs.x * lhs.x + lhs.y * lhs.y;
}

