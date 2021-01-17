#include "Vector2D.h"

#include <cmath>

Vector2D::Vector2D()
{
	m_coordinates[0] = 0.f;
	m_coordinates[1] = 0.f;
}

const float Vector2D::operator[](const int a_i) const
{
	return a_i;
}

const Vector2D Vector2D::operator*(const float a_other) const
{
	Vector2D newVector2D;
	newVector2D.m_coordinates[0] = m_coordinates[0] * a_other;
	newVector2D.m_coordinates[1] = m_coordinates[1] * a_other;
	return newVector2D;
}

void Vector2D::operator*=(const float a_other)
{
	m_coordinates[0] *= a_other;
	m_coordinates[1] *= a_other;
}

const Vector2D Vector2D::operator*(const Vector2D& a_other) const
{
	Vector2D newVector2D;

	newVector2D.m_coordinates[0] = m_coordinates[0] * a_other.m_coordinates[0];
	newVector2D.m_coordinates[1] = m_coordinates[1] * a_other.m_coordinates[1];

	return newVector2D;
}

void Vector2D::operator*=(const Vector2D& a_other)
{
	m_coordinates[0] *= a_other.m_coordinates[0];
	m_coordinates[1] *= a_other.m_coordinates[1];
}

const Vector2D Vector2D::operator/(const Vector2D& a_other) const
{
	Vector2D newVector2D;

	newVector2D.m_coordinates[0] = m_coordinates[0] / a_other.m_coordinates[0];
	newVector2D.m_coordinates[1] = m_coordinates[1] / a_other.m_coordinates[1];

	return newVector2D;
}

void Vector2D::operator/=(const Vector2D& a_other)
{
	m_coordinates[0] /= a_other.m_coordinates[0];
	m_coordinates[1] /= a_other.m_coordinates[1];
}

const Vector2D Vector2D::operator/(const float a_other) const
{
	Vector2D newVector2D;
	newVector2D.m_coordinates[0] = m_coordinates[0] / a_other;
	newVector2D.m_coordinates[1] = m_coordinates[1] / a_other;
	return newVector2D;
}

void Vector2D::operator/=(const float a_other)
{
	m_coordinates[0] /= a_other;
	m_coordinates[1] /= a_other;
}

const Vector2D Vector2D::operator+(const Vector2D& a_other) const
{
	Vector2D newVector2D;

	newVector2D.m_coordinates[0] = m_coordinates[0] + a_other.m_coordinates[0];
	newVector2D.m_coordinates[1] = m_coordinates[1] + a_other.m_coordinates[1];

	return newVector2D;
}

void Vector2D::operator+=(const Vector2D& a_other)
{
	m_coordinates[0] += a_other.m_coordinates[0];
	m_coordinates[1] += a_other.m_coordinates[1];
}

const Vector2D Vector2D::operator-(const Vector2D& a_other) const
{
	Vector2D newVector2D;

	newVector2D.m_coordinates[0] = m_coordinates[0] - a_other.m_coordinates[0];
	newVector2D.m_coordinates[1] = m_coordinates[1] - a_other.m_coordinates[1];

	return newVector2D;
}

void Vector2D::operator-=(const Vector2D& a_other)
{
	m_coordinates[0] -= a_other.m_coordinates[0];
	m_coordinates[1] -= a_other.m_coordinates[1];
}

Vector2D::Vector2D(float a_x, float a_y)
{
	m_coordinates[0] = a_x;
	m_coordinates[1] = a_y;
}



const float Vector2D::magnitude() const
{
	return sqrt(pow(m_coordinates[0], 2) + pow(m_coordinates[1], 2));
}

const float Vector2D::magnitudeSq() const
{
	return pow(m_coordinates[0], 2) + pow(m_coordinates[1], 2);
}

const float Vector2D::distance(const Vector2D& a_other) const
{
	float v2 = a_other.magnitude();
	float v = sqrt(pow(m_coordinates[0], 2) + pow(m_coordinates[1], 2));
	return v2 - v;
}

const float Vector2D::distanceSq(const Vector2D& a_other) const
{
	float v2 = a_other.magnitudeSq();
	float v = pow(m_coordinates[0], 2) + pow(m_coordinates[1], 2);
	return v2 - v;
}

const Vector2D Vector2D::crossProduct() const
{
	return Vector2D();
}

const float Vector2D::dotProduct(const Vector2D& a_other) const
{
	float dotProd = (m_coordinates[0] * a_other.m_coordinates[0]) + (m_coordinates[1] + a_other.m_coordinates[1]);
	return dotProd;
}

void Vector2D::normalise()
{
	m_coordinates[0] = m_coordinates[0] / magnitude();
	m_coordinates[1] = m_coordinates[1] / magnitude();
}
#pragma endregion