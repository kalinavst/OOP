#include "Vector4D.hpp"

Vector4D::Vector4D(double a, double b, double c, double d)
{
	Myvector[0] = a;
	Myvector[1] = b;
	Myvector[2] = c;
	Myvector[3] = d;
	
}

Vector4D::Vector4D()
{
	
	Myvector[0] = 0;
	Myvector[1] = 0;
	Myvector[2] = 0;
	Myvector[3] = 0;
}

Vector4D::Vector4D(const Vector4D& from)
{
	

	for (int i = 0; i < 4; i++) {
		Myvector[i] = from.Myvector[i];
	}
}

void Vector4D::print() const
{
	for (int i = 0; i < 4; i++) {
		std::cout << Myvector[i] << " ";
	}

}

//void Vector4D::Set(const double arr[4])
//{
//	for (int i = 0; i < 4; i++) {
//		Myvector[i] = arr[i];
//
//	}
//}

void Vector4D::copy_vector(const Vector4D& from)
{
	for (int i = 0; i < 4; i++) {
		this->Myvector[i] = from.Myvector[i];
}
}



Vector4D& Vector4D::operator=(const Vector4D& from)
{
	this->copy_vector(from);
	return *this;
}


double& Vector4D::operator[](const int index)
{
if(index>=0&&index<4)

	return *(Myvector+index);

}

bool Vector4D::operator<(const Vector4D& to) const
{
	for (int i = 0; i < 4; i++) {
		if (Myvector[i] != to.Myvector[i]) {
			if (Myvector[i] < to.Myvector[i])return 1;
			else return 0;
		}
	}return 0;
}

bool Vector4D::operator>(const Vector4D& to) const
{
	for (int i = 0; i < 4; i++) {
		if (Myvector[i] != to.Myvector[i]) {
			if (Myvector[i] > to.Myvector[i])return 1;
			else return 0;
		}
	}


	return false;
}

bool Vector4D::operator<=(const Vector4D& to) const
{
	if (*this == to)return 1;
	else 

		for (int i = 0; i < 4; i++) {
			if (Myvector[i] != to.Myvector[i]) {
				if (Myvector[i] <= to.Myvector[i])return 1;
				else return 0;
			}
		}


	return false;
}

bool Vector4D::operator>=(const Vector4D& to) const
{
	for (int i = 0; i < 4; i++) {
		if (Myvector[i] != to.Myvector[i]) {
			if (Myvector[i] >= to.Myvector[i])return 1;
			else return 0;
		}
	}


	
	return true;
}




bool Vector4D::operator==(const Vector4D& to) const
{
	for (int i = 0; i < 4; i++) {
		if (this->Myvector[i] != to.Myvector[i])return 0;
	}
	return 1;
}

bool Vector4D::operator!=(const Vector4D& to) const
{
	for (int i = 0; i < 4; i++) {
		if (this->Myvector[i] != to.Myvector[i])return 1;
	}
	return 0;
}

bool Vector4D::operator!() const
{
	Vector4D v1(0, 0, 0, 0);
	if (*this == v1)return 1;
	return false;
}

Vector4D Vector4D::operator+(const Vector4D& other) const
{
	Vector4D v1;
	for (int i = 0; i < 4; i++) {
		v1.Myvector[i] = (this->Myvector[i] + other.Myvector[i]);


	}return v1;
}



Vector4D Vector4D::operator-(const Vector4D& other) const
{
	Vector4D v1;

	for (int i = 0; i < 4; i++) {
		v1.Myvector[i] = (this->Myvector[i] - other.Myvector[i]);


	}return v1;

	
}

Vector4D& Vector4D::operator-=(const Vector4D& other)
{
	for (int i = 0; i < 4; i++) {
		Myvector[i] -= other.Myvector[i];

	}
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& other) const
{

	Vector4D v1;
	for (int i = 0; i < 4; i++) {
		v1.Myvector[i] = (this->Myvector[i] * other.Myvector[i]);
		
		
	}return v1;
}

Vector4D& Vector4D::operator*=(const Vector4D& other)
{
	for (int i = 0; i < 4; i++) {
		Myvector[i] *= other.Myvector[i];

	}
	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& other) const
{
	Vector4D v1;
	for (int i = 0; i < 4; i++) {
		v1.Myvector[i] = (this->Myvector[i] / other.Myvector[i]);


	}return v1;
}

Vector4D& Vector4D::operator/=(const Vector4D& other)
{
	for (int i = 0; i < 4; i++) {
		Myvector[i] /= other.Myvector[i];

	}
	return *this;
}

Vector4D& Vector4D::operator+=(const Vector4D& other) 
{
	for (int i = 0; i < 4; i++) {
		Myvector[i] += other.Myvector[i];

	}
	return *this;
}

Vector4D Vector4D::operator*(const double& x) const
{
	Vector4D v1;
	for (int i = 0; i < 4; i++) {
		v1.Myvector[i] = (this->Myvector[i] * x);


	}return v1;
}

Vector4D& Vector4D::operator*=(const double& x)
{
	for (int i = 0; i < 4; i++) {
		Myvector[i] *= x;

	}
	return *this;
}

Vector4D Vector4D::operator/(const double& x) const
{
	Vector4D v1;
	for (int i = 0; i < 4; i++) {
		v1.Myvector[i] = (this->Myvector[i] / x);


	}return v1;
}

Vector4D Vector4D::operator-() const
{
	Vector4D v1;
	for (int i = 0; i < 4; i++) {
		v1.Myvector[i] = (this->Myvector[i] * -1);


	}return v1;
}
