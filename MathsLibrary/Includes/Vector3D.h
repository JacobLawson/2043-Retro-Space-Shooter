#ifndef VECTOR_3D
#define VECTOR_3D

class Vector2D;
class Matrix3x3;

class Vector3D
{
public:
	// Constructors / Destructors
	Vector3D(float a_x, float a_y, float a_z);
	Vector3D(Vector2D other);
	Vector3D();
	~Vector3D() {};

	// Operators
	const float operator[](const int a_i) const;

	const Vector3D operator*(const float a_other) const;
	void operator*=(const float a_other);

	const Vector3D operator*(const Vector3D &a_other) const;
	void operator*=(const Vector3D &a_other);

	const Vector3D operator/(const Vector3D &a_other) const;
	void operator/=(const Vector3D &a_other);

	const Vector3D operator/(const float a_other) const;
	void operator/=(const float a_other);

	const Vector3D operator*(const Matrix3x3 &a_other) const;

	const Vector3D operator+(const Vector3D &a_other) const;
	void operator+=(const Vector3D &a_other);

	const Vector3D operator-(const Vector3D &a_other) const;
	void operator-=(const Vector3D &a_other);

	// Functions
	const float magnitude() const;
	const float magnitudeSq() const;

	const float distance(const Vector3D &a_other) const;
	const float distanceSq(const Vector3D &a_other) const;

	const float dotProduct(const Vector3D &a_other) const;
	const Vector3D crossProduct(const Vector3D &a_rv3a) const;

	void normalise();
	const Vector3D normalised() const;

	// Getters / Setters
	const float GetX() const { return m_coordinates[0]; }
	const float GetY() const { return m_coordinates[1]; }
	const float GetZ() const { return m_coordinates[2]; }
	void SetX(const float a_x) { m_coordinates[0] = a_x; }
	void SetY(const float a_y) { m_coordinates[1] = a_y; }
	void SetZ(const float a_z) { m_coordinates[2] = a_z; }

private:
	// Variables
	float m_coordinates[3];
};

#endif //!VECTOR_3D
