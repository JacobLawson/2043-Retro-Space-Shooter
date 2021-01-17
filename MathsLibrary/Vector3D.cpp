#include "Vector3D.h"
#include "Vector2D.h"
#include "Matrix3x3.h"
#include <cmath>

//Vector3D::Vector3D(float a_x, float a_y, float a_z)
//{
//}

//Vector3D::Vector3D(Vector2D other)
//{
//}

Vector3D::Vector3D()
{
	m_coordinates[0] = 0.f;
	m_coordinates[1] = 0.f;
	m_coordinates[2] = 0.f;
}

const float Vector3D::operator[](const int a_i) const
{
	return a_i;
}

const Vector3D Vector3D::operator*(const float a_other) const
{
	Vector3D newVector3D;
	newVector3D.m_coordinates[0] = m_coordinates[0] * a_other;
	newVector3D.m_coordinates[1] = m_coordinates[1] * a_other;
	newVector3D.m_coordinates[2] = m_coordinates[2] * a_other;
	return newVector3D;
}

void Vector3D::operator*=(const float a_other)
{
	m_coordinates[0] *= a_other;
	m_coordinates[1] *= a_other;
	m_coordinates[2] *= a_other;
}

const Vector3D Vector3D::operator*(const Vector3D& a_other) const
{
	Vector3D newVector3D;

	newVector3D.m_coordinates[0] = m_coordinates[0] * a_other.m_coordinates[0];
	newVector3D.m_coordinates[1] = m_coordinates[1] * a_other.m_coordinates[1];
	newVector3D.m_coordinates[2] = m_coordinates[2] * a_other.m_coordinates[2];

	return newVector3D;
}

void Vector3D::operator*=(const Vector3D& a_other)
{
	m_coordinates[0] *= a_other.m_coordinates[0];
	m_coordinates[1] *= a_other.m_coordinates[1];
	m_coordinates[2] *= a_other.m_coordinates[2];
}

const Vector3D Vector3D::operator/(const Vector3D& a_other) const
{
	Vector3D newVector3D;

	newVector3D.m_coordinates[0] = m_coordinates[0] / a_other.m_coordinates[0];
	newVector3D.m_coordinates[1] = m_coordinates[1] / a_other.m_coordinates[1];
	newVector3D.m_coordinates[2] = m_coordinates[2] / a_other.m_coordinates[2];

	return newVector3D;
}

void Vector3D::operator/=(const Vector3D& a_other)
{
	m_coordinates[0] /= a_other.m_coordinates[0];
	m_coordinates[1] /= a_other.m_coordinates[1];
	m_coordinates[2] /= a_other.m_coordinates[2];
}

const Vector3D Vector3D::operator/(const float a_other) const
{
	Vector3D newVector3D;
	newVector3D.m_coordinates[0] = m_coordinates[0] / a_other;
	newVector3D.m_coordinates[1] = m_coordinates[1] / a_other;
	newVector3D.m_coordinates[2] = m_coordinates[2] / a_other;
	return newVector3D;
}

void Vector3D::operator/=(const float a_other)
{
	m_coordinates[0] /= a_other;
	m_coordinates[1] /= a_other;
	m_coordinates[2] /= a_other;
}

const Vector3D Vector3D::operator*(const Matrix3x3& a_other) const
{
	return Vector3D();
}

const Vector3D Vector3D::operator+(const Vector3D& a_other) const
{
	Vector3D newVector3D;

	newVector3D.m_coordinates[0] = m_coordinates[0] + a_other.m_coordinates[0];
	newVector3D.m_coordinates[1] = m_coordinates[1] + a_other.m_coordinates[1];
	newVector3D.m_coordinates[2] = m_coordinates[2] + a_other.m_coordinates[2];

	return newVector3D;
}

void Vector3D::operator+=(const Vector3D& a_other)
{
	m_coordinates[0] += a_other.m_coordinates[0];
	m_coordinates[1] += a_other.m_coordinates[1];
	m_coordinates[2] += a_other.m_coordinates[2];
}

const Vector3D Vector3D::operator-(const Vector3D& a_other) const
{
	Vector3D newVector3D;

	newVector3D.m_coordinates[0] = m_coordinates[0] - a_other.m_coordinates[0];
	newVector3D.m_coordinates[1] = m_coordinates[1] - a_other.m_coordinates[1];
	newVector3D.m_coordinates[2] = m_coordinates[2] - a_other.m_coordinates[2];

	return newVector3D;
}

void Vector3D::operator-=(const Vector3D& a_other)
{
	m_coordinates[0] -= a_other.m_coordinates[0];
	m_coordinates[1] -= a_other.m_coordinates[1];
	m_coordinates[2] -= a_other.m_coordinates[2];
}
