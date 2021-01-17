#include <cmath>
#include "Matrix3x3.h"
#include "Vector3D.h"

Matrix3x3::Matrix3x3()
{
	m_matrixValues[0] = 0.0f;
	m_matrixValues[1] = 0.0f;
	m_matrixValues[2] = 0.0f;

	m_matrixValues[3] = 0.0f;
	m_matrixValues[4] = 0.0f;
	m_matrixValues[5] = 0.0f;

	m_matrixValues[6] = 0.0f;
	m_matrixValues[7] = 0.0f;
	m_matrixValues[8] = 0.0f;
}

Matrix3x3::Matrix3x3(const float a_fm11, const float a_fm12, const float a_fm13, const float a_fm21, const float a_fm22, const float a_fm23, const float a_fm31, const float a_fm32, const float a_fm33)
{
	m_matrixValues[0] = a_fm11;
	m_matrixValues[1] = a_fm12;
	m_matrixValues[2] = a_fm13;

	m_matrixValues[3] = a_fm21;
	m_matrixValues[4] = a_fm22;
	m_matrixValues[5] = a_fm23;

	m_matrixValues[6] = a_fm31;
	m_matrixValues[7] = a_fm32;
	m_matrixValues[8] = a_fm33;
}

Matrix3x3::Matrix3x3(const float* a_fpm33Values)
{
	m_matrixValues[0] = *a_fpm33Values;
	m_matrixValues[1] = *a_fpm33Values;
	m_matrixValues[2] = *a_fpm33Values;

	m_matrixValues[3] = *a_fpm33Values;
	m_matrixValues[4] = *a_fpm33Values;
	m_matrixValues[5] = *a_fpm33Values;

	m_matrixValues[6] = *a_fpm33Values;
	m_matrixValues[7] = *a_fpm33Values;
	m_matrixValues[8] = *a_fpm33Values;
}

const Matrix3x3 Matrix3x3::Identity()
{
	Matrix3x3 newMatrix3x3;
	newMatrix3x3.m_matrixValues[0] = 1.0f;
	newMatrix3x3.m_matrixValues[1] = 0.0f;
	newMatrix3x3.m_matrixValues[2] = 0.0f;

	newMatrix3x3.m_matrixValues[3] = 0.0f;
	newMatrix3x3.m_matrixValues[4] = 1.0f;
	newMatrix3x3.m_matrixValues[5] = 0.0f;

	newMatrix3x3.m_matrixValues[6] = 0.0f;
	newMatrix3x3.m_matrixValues[7] = 0.0f;
	newMatrix3x3.m_matrixValues[8] = 1.0f;
	return newMatrix3x3;
}

const Vector3D Matrix3x3::GetRow(const int a_irowNumber) const
{
	Vector3D newVector;
	if (a_irowNumber == 0)
	{
		newVector = { m_matrixValues[0], m_matrixValues[1], m_matrixValues[2] };
	}
	else if (a_irowNumber == 1)
	{
		newVector = { m_matrixValues[3], m_matrixValues[4], m_matrixValues[5] };
	}
	else if (a_irowNumber == 2)
	{
		newVector = { m_matrixValues[6], m_matrixValues[7], m_matrixValues[8] };
	}
	else
	{
		newVector = { 0.0f, 0.0f, 0.0f};
	}
	return newVector;
}

void Matrix3x3::SetRow(const int a_irowNumber, const Vector3D& a_rowValues)
{
	if (a_irowNumber == 0)
	{
		m_matrixValues[0] = a_rowValues.GetX();
		m_matrixValues[1] = a_rowValues.GetY();
		m_matrixValues[2] = a_rowValues.GetZ();
	}
	else if (a_irowNumber == 1)
	{
		m_matrixValues[3] = a_rowValues.GetX();
		m_matrixValues[4] = a_rowValues.GetY();
		m_matrixValues[5] = a_rowValues.GetZ();
	}
	else if (a_irowNumber == 2)
	{
		m_matrixValues[6] = a_rowValues.GetX();
		m_matrixValues[7] = a_rowValues.GetY();
		m_matrixValues[8] = a_rowValues.GetZ();
	}
}

const Matrix3x3 Matrix3x3::RotateX(const float a_ftheta) const
{
	const float co = cos(a_ftheta);
	const float si = sin(a_ftheta);

	return *this * Matrix3x3(
		1.0f, 0.0f, 0.0f,
		0.0f, co, -si,
		0.0f, si, co
	);
}

const Matrix3x3 Matrix3x3::RotateY(const float a_ftheta) const
{
	const float co = cos(a_ftheta);
	const float si = sin(a_ftheta);

	return *this * Matrix3x3(
		co, 0.0f, si,
		0.0f, 1.0f, 0.0f,
		-si, 0.0f, co
	);
}

const Matrix3x3 Matrix3x3::RotateZ(const float a_ftheta) const
{
	const float co = cos(a_ftheta);
	const float si = sin(a_ftheta);

	return *this * Matrix3x3(
		co, -si, 0.0f,
		si, co, 0.0f,
		0.0f, 0.0f, 1.0f
	);
}

const Matrix3x3 Matrix3x3::operator+(const Matrix3x3& a_other) const
{
	Matrix3x3 newMatrix3x3;

	newMatrix3x3.m_matrixValues[0] = m_matrixValues[0] - a_other.m_matrixValues[0];
	newMatrix3x3.m_matrixValues[1] = m_matrixValues[1] - a_other.m_matrixValues[1];
	newMatrix3x3.m_matrixValues[2] = m_matrixValues[2] - a_other.m_matrixValues[2];

	newMatrix3x3.m_matrixValues[3] = m_matrixValues[3] - a_other.m_matrixValues[3];
	newMatrix3x3.m_matrixValues[4] = m_matrixValues[4] - a_other.m_matrixValues[4];
	newMatrix3x3.m_matrixValues[5] = m_matrixValues[5] - a_other.m_matrixValues[5];

	newMatrix3x3.m_matrixValues[6] = m_matrixValues[6] - a_other.m_matrixValues[6];
	newMatrix3x3.m_matrixValues[7] = m_matrixValues[7] - a_other.m_matrixValues[7];
	newMatrix3x3.m_matrixValues[8] = m_matrixValues[8] - a_other.m_matrixValues[8];

	return newMatrix3x3;
}

void Matrix3x3::operator+=(const Matrix3x3& a_other)
{
	m_matrixValues[0] += a_other.m_matrixValues[0];
	m_matrixValues[1] += a_other.m_matrixValues[1];
	m_matrixValues[2] += a_other.m_matrixValues[2];

	m_matrixValues[3] += a_other.m_matrixValues[3];
	m_matrixValues[4] += a_other.m_matrixValues[4];
	m_matrixValues[5] += a_other.m_matrixValues[5];

	m_matrixValues[6] += a_other.m_matrixValues[6];
	m_matrixValues[7] += a_other.m_matrixValues[7];
	m_matrixValues[8] += a_other.m_matrixValues[8];
}

const Matrix3x3 Matrix3x3::operator-(const Matrix3x3& a_other) const
{
	Matrix3x3 newMatrix3x3;

	newMatrix3x3.m_matrixValues[0] = m_matrixValues[0] - a_other[0];
	newMatrix3x3.m_matrixValues[1] = m_matrixValues[1] - a_other[1];
	newMatrix3x3.m_matrixValues[2] = m_matrixValues[2] - a_other[2];

	newMatrix3x3.m_matrixValues[3] = m_matrixValues[3] - a_other[3];
	newMatrix3x3.m_matrixValues[4] = m_matrixValues[4] - a_other[4];
	newMatrix3x3.m_matrixValues[5] = m_matrixValues[5] - a_other[5];

	newMatrix3x3.m_matrixValues[6] = m_matrixValues[6] - a_other[6];
	newMatrix3x3.m_matrixValues[7] = m_matrixValues[7] - a_other[7];
	newMatrix3x3.m_matrixValues[8] = m_matrixValues[8] - a_other[8];

	return newMatrix3x3;
}

void Matrix3x3::operator-=(const Matrix3x3& a_other)
{
	m_matrixValues[0] -= a_other.m_matrixValues[0];
	m_matrixValues[1] -= a_other.m_matrixValues[1];
	m_matrixValues[2] -= a_other.m_matrixValues[2];

	m_matrixValues[3] -= a_other.m_matrixValues[3];
	m_matrixValues[4] -= a_other.m_matrixValues[4];
	m_matrixValues[5] -= a_other.m_matrixValues[5];

	m_matrixValues[6] -= a_other.m_matrixValues[6];
	m_matrixValues[7] -= a_other.m_matrixValues[7];
	m_matrixValues[8] -= a_other.m_matrixValues[8];
}

const Matrix3x3 Matrix3x3::operator*(const Matrix3x3& a_other) const
{
	Matrix3x3 newMatrix3x3;

	newMatrix3x3.m_matrixValues[0] = ((m_matrixValues[0] * a_other.m_matrixValues[0]) + (m_matrixValues[1] * a_other.m_matrixValues[3]) + (m_matrixValues[2] * a_other.m_matrixValues[6]));
	newMatrix3x3.m_matrixValues[1] = ((m_matrixValues[0] * a_other.m_matrixValues[1]) + (m_matrixValues[1] * a_other.m_matrixValues[4]) + (m_matrixValues[2] * a_other.m_matrixValues[7]));
	newMatrix3x3.m_matrixValues[2] = ((m_matrixValues[0] * a_other.m_matrixValues[2]) + (m_matrixValues[1] * a_other.m_matrixValues[5]) + (m_matrixValues[2] * a_other.m_matrixValues[8]));

	newMatrix3x3.m_matrixValues[3] = ((m_matrixValues[3] * a_other.m_matrixValues[0]) + (m_matrixValues[4] * a_other.m_matrixValues[3]) + (m_matrixValues[5] * a_other.m_matrixValues[6]));
	newMatrix3x3.m_matrixValues[4] = ((m_matrixValues[3] * a_other.m_matrixValues[1]) + (m_matrixValues[4] * a_other.m_matrixValues[4]) + (m_matrixValues[5] * a_other.m_matrixValues[7]));
	newMatrix3x3.m_matrixValues[5] = ((m_matrixValues[3] * a_other.m_matrixValues[2]) + (m_matrixValues[4] * a_other.m_matrixValues[5]) + (m_matrixValues[5] * a_other.m_matrixValues[8]));

	newMatrix3x3.m_matrixValues[6] = ((m_matrixValues[6] * a_other.m_matrixValues[0]) + (m_matrixValues[7] * a_other.m_matrixValues[3]) + (m_matrixValues[8] * a_other.m_matrixValues[6]));
	newMatrix3x3.m_matrixValues[7] = ((m_matrixValues[6] * a_other.m_matrixValues[1]) + (m_matrixValues[7] * a_other.m_matrixValues[4]) + (m_matrixValues[8] * a_other.m_matrixValues[7]));
	newMatrix3x3.m_matrixValues[8] = ((m_matrixValues[6] * a_other.m_matrixValues[2]) + (m_matrixValues[7] * a_other.m_matrixValues[5]) + (m_matrixValues[8] * a_other.m_matrixValues[8]));

	return newMatrix3x3;
}

void Matrix3x3::operator*=(const Matrix3x3& a_other)
{
	(m_matrixValues[0] *= a_other.m_matrixValues[0]) += (m_matrixValues[1] *= a_other.m_matrixValues[3]) += (m_matrixValues[2] *= a_other.m_matrixValues[6]);
	(m_matrixValues[0] *= a_other.m_matrixValues[1]) += (m_matrixValues[1] *= a_other.m_matrixValues[4]) += (m_matrixValues[2] *= a_other.m_matrixValues[7]);
	(m_matrixValues[0] *= a_other.m_matrixValues[2]) += (m_matrixValues[1] *= a_other.m_matrixValues[5]) += (m_matrixValues[2] *= a_other.m_matrixValues[8]);

	(m_matrixValues[3] *= a_other.m_matrixValues[0]) += (m_matrixValues[4] *= a_other.m_matrixValues[3]) += (m_matrixValues[5] *= a_other.m_matrixValues[6]);
	(m_matrixValues[3] *= a_other.m_matrixValues[1]) += (m_matrixValues[4] *= a_other.m_matrixValues[4]) += (m_matrixValues[5] *= a_other.m_matrixValues[7]);
	(m_matrixValues[3] *= a_other.m_matrixValues[2]) += (m_matrixValues[4] *= a_other.m_matrixValues[5]) += (m_matrixValues[5] *= a_other.m_matrixValues[8]);

	(m_matrixValues[6] *= a_other.m_matrixValues[0]) += (m_matrixValues[7] *= a_other.m_matrixValues[3]) += (m_matrixValues[8] *= a_other.m_matrixValues[6]);
	(m_matrixValues[6] *= a_other.m_matrixValues[1]) += (m_matrixValues[7] *= a_other.m_matrixValues[4]) += (m_matrixValues[8] *= a_other.m_matrixValues[7]);
	(m_matrixValues[6] *= a_other.m_matrixValues[2]) += (m_matrixValues[7] *= a_other.m_matrixValues[5]) += (m_matrixValues[8] *= a_other.m_matrixValues[8]);
}

const Matrix3x3 Matrix3x3::operator*(const float& a_other) const
{
	Matrix3x3 newMatrix3x3;
	newMatrix3x3.m_matrixValues[0] = m_matrixValues[0] * a_other;
	newMatrix3x3.m_matrixValues[1] = m_matrixValues[1] * a_other;
	newMatrix3x3.m_matrixValues[2] = m_matrixValues[2] * a_other;

	newMatrix3x3.m_matrixValues[3] = m_matrixValues[3] * a_other;
	newMatrix3x3.m_matrixValues[4] = m_matrixValues[4] * a_other;
	newMatrix3x3.m_matrixValues[5] = m_matrixValues[5] * a_other;

	newMatrix3x3.m_matrixValues[6] = m_matrixValues[6] * a_other;
	newMatrix3x3.m_matrixValues[7] = m_matrixValues[7] * a_other;
	newMatrix3x3.m_matrixValues[8] = m_matrixValues[8] * a_other;
	return newMatrix3x3;
}

void Matrix3x3::operator*=(const float& a_other)
{
	m_matrixValues[0] *= a_other;
	m_matrixValues[1] *= a_other;
	m_matrixValues[2] *= a_other;

	m_matrixValues[3] *= a_other;
	m_matrixValues[4] *= a_other;
	m_matrixValues[5] *= a_other;

	m_matrixValues[6] *= a_other;
	m_matrixValues[7] *= a_other;
	m_matrixValues[8] *= a_other;
}

const bool Matrix3x3::operator==(const Matrix3x3& a_other) const
{
	if (m_matrixValues[0] == a_other.m_matrixValues[0] &&
		m_matrixValues[1] == a_other.m_matrixValues[1] &&
		m_matrixValues[2] == a_other.m_matrixValues[2] &&

		m_matrixValues[3] == a_other.m_matrixValues[3] &&
		m_matrixValues[4] == a_other.m_matrixValues[4] &&
		m_matrixValues[5] == a_other.m_matrixValues[5] &&

		m_matrixValues[6] == a_other.m_matrixValues[6] &&
		m_matrixValues[7] == a_other.m_matrixValues[7] &&
		m_matrixValues[8] == a_other.m_matrixValues[8]);
	{
		return true;
	}
}

const bool Matrix3x3::operator!=(const Matrix3x3& a_other) const
{
	if (m_matrixValues[0] != a_other.m_matrixValues[0] ||
		m_matrixValues[1] != a_other.m_matrixValues[1] ||
		m_matrixValues[2] != a_other.m_matrixValues[2] ||

		m_matrixValues[3] != a_other.m_matrixValues[3] ||
		m_matrixValues[4] != a_other.m_matrixValues[4] ||
		m_matrixValues[5] != a_other.m_matrixValues[5] ||

		m_matrixValues[6] != a_other.m_matrixValues[6] ||
		m_matrixValues[7] != a_other.m_matrixValues[7] ||
		m_matrixValues[8] != a_other.m_matrixValues[8]);
	{
		return true;
	}
}

const float Matrix3x3::operator[](const int i) const
{
	return m_matrixValues[i];
}

void Matrix3x3::Inverse()
{
	float detriment = m_matrixValues[0] * (m_matrixValues[4] * m_matrixValues[8] - m_matrixValues[6] * m_matrixValues[5]) -
		m_matrixValues[4] * (m_matrixValues[1] * m_matrixValues[8] - m_matrixValues[7] * m_matrixValues[2]) +
		m_matrixValues[6] * (m_matrixValues[1] * m_matrixValues[5] - m_matrixValues[4] * m_matrixValues[2]);

	double inverseDetriment = 1 / detriment;

	float temp0 = m_matrixValues[0];
	float temp1 = m_matrixValues[1];
	float temp2 = m_matrixValues[2];
	float temp3 = m_matrixValues[3];
	float temp4 = m_matrixValues[4];
	float temp5 = m_matrixValues[5];
	float temp6 = m_matrixValues[6];
	float temp7 = m_matrixValues[7];
	float temp8 = m_matrixValues[8];
	
	m_matrixValues[0] = (temp4 * temp8 - temp5 * temp7) * inverseDetriment;
	m_matrixValues[1] = (temp7 * temp2 - temp1 * temp8) * inverseDetriment;
	m_matrixValues[2] = (temp1 * temp5 - temp2 * temp4) * inverseDetriment;

	m_matrixValues[3] = (temp6 * temp5 - temp3 * temp8) * inverseDetriment;
	m_matrixValues[4] = (temp0 * temp8 - temp6 * temp2) * inverseDetriment;
	m_matrixValues[5] = (temp2 * temp3 - temp0 * temp5) * inverseDetriment;

	m_matrixValues[6] = (temp3 * temp7 - temp6 * temp4) * inverseDetriment;
	m_matrixValues[7] = (temp1 * temp6 - temp0 * temp7) * inverseDetriment;
	m_matrixValues[8] = (temp0 * temp4 - temp1 * temp3) * inverseDetriment;
}

const Matrix3x3 Matrix3x3::Transpose(Matrix3x3 a_other)
{
	Matrix3x3 newMatrix;
	newMatrix.m_matrixValues[0] = a_other.m_matrixValues[0];
	newMatrix.m_matrixValues[1] = a_other.m_matrixValues[3];
	newMatrix.m_matrixValues[2] = a_other.m_matrixValues[6];

	newMatrix.m_matrixValues[3] = a_other.m_matrixValues[2];
	newMatrix.m_matrixValues[4] = a_other.m_matrixValues[4];
	newMatrix.m_matrixValues[5] = a_other.m_matrixValues[7];

	newMatrix.m_matrixValues[6] = a_other.m_matrixValues[2];
	newMatrix.m_matrixValues[7] = a_other.m_matrixValues[5];
	newMatrix.m_matrixValues[8] = a_other.m_matrixValues[8];
	return newMatrix;
}
