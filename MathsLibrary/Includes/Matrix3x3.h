#ifndef MATRIX_3X3
#define MATRIX_3X3

class Vector3D;

class Matrix3x3
{
public:
	// Constructors / Destructors
	Matrix3x3();
	Matrix3x3(const float a_fm11, const float a_fm12, const float a_fm13,
		const float a_fm21, const float a_fm22, const float a_fm23,
		const float a_fm31, const float a_fm32, const float a_fm33);
	Matrix3x3(const float* a_fpm33Values);
	~Matrix3x3() {};

	// Static funtions
	static const Matrix3x3 Identity();

	// Getters / Setters
	const Vector3D GetRow(const int a_irowNumber) const;
	void SetRow(const int a_irowNumber, const Vector3D &a_rowValues);

	// Rotations
	const Matrix3x3 RotateX(const float a_ftheta) const;
	const Matrix3x3 RotateY(const float a_ftheta) const;
	const Matrix3x3 RotateZ(const float a_ftheta) const;

	// Overloaded Operators
	const Matrix3x3 operator+(const Matrix3x3 &a_other) const;
	void operator+=(const Matrix3x3 &a_other);

	const Matrix3x3 operator-(const Matrix3x3 &a_other) const;
	void operator-=(const Matrix3x3 &a_other);

	const Matrix3x3 operator*(const Matrix3x3 &a_other) const;
	void operator*=(const Matrix3x3 &a_other);

	const Matrix3x3 operator*(const float &a_other) const;
	void operator*=(const float &a_other);

	const bool operator==(const Matrix3x3 &a_other) const;
	const bool operator!=(const Matrix3x3 &a_other) const;

	const float operator[](const int i) const;

	//Inverse and transpose
	void Inverse();
	const Matrix3x3 Transpose(Matrix3x3 a_other);

private:
	// Variables
	static const int cols = 3;
	static const int rows = 3;
	float m_matrixValues[9];
};

#endif //!MATRIX_3X3
