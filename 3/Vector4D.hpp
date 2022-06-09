#pragma once
#include <iostream>
class Vector4D {

public:

    Vector4D(double, double, double, double);
    Vector4D();
    Vector4D(const Vector4D& from);
    void print() const;
    
    void copy_vector(const Vector4D& from);
    
    Vector4D& operator=(const Vector4D& from);
    
    double& operator[](const int index);
    bool operator<(const Vector4D& to) const;
    bool operator>(const Vector4D& to) const;
    bool operator<=(const Vector4D& to) const;
    bool operator>=(const Vector4D& to) const;
    bool operator==(const Vector4D& to) const;
    bool operator!=(const Vector4D& to) const;
    bool operator !()const;
    Vector4D operator+(const Vector4D& other) const;
    Vector4D& operator+=(const Vector4D& other) ;
    Vector4D operator-(const Vector4D& other) const;
    Vector4D& operator-=(const Vector4D& other) ;
    Vector4D operator*(const Vector4D& other) const;
    Vector4D& operator*=(const Vector4D& other) ;
    Vector4D operator/(const Vector4D& other) const;
    Vector4D& operator/=(const Vector4D& other) ;
    Vector4D operator*(const double& x) const;
    Vector4D& operator*=(const double& x) ;
    Vector4D operator/(const double& x) const;
    Vector4D operator-()const;
    
   
   
   
    

private:
    double Myvector[4];

};