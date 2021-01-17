#ifndef VECTOR_2D
#define VECTOR_2D

class Vector2D
{
public:
	// Constructors / Destructors
	Vector2D(float a_x, float a_y);
	Vector2D();
	~Vector2D() {};

	// Operators
	const float operator[](const int a_i) const;

	const Vector2D operator*(const float a_other) const;
	void operator*=(const float a_other);

	const Vector2D operator*(const Vector2D& a_other) const;
	void operator*=(const Vector2D& a_other);

	const Vector2D operator/(const Vector2D& a_other) const;
	void operator/=(const Vector2D& a_other);

	const Vector2D operator/(const float a_other) const;
	void operator/=(const float a_other);

	const Vector2D operator+(const Vector2D& a_other) const;
	void operator+=(const Vector2D& a_other);

	const Vector2D operator-(const Vector2D& a_other) const;
	void operator-=(const Vector2D& a_other);

	// Functions
	const float magnitude() const;
	const float magnitudeSq() const;

	const float distance(const Vector2D& a_other) const;
	const float distanceSq(const Vector2D& a_other) const;

	const Vector2D crossProduct() const;
	const float dotProduct(const Vector2D& a_other) const;

	void normalise();
	const Vector2D normalised() const;

	// Getters / Setters
	const float GetX() const { return m_coordinates[0]; }
	const float GetY() const { return m_coordinates[1]; }
	void SetX(const float a_x) { m_coordinates[0] = a_x; }
	void SetY(const float a_y) { m_coordinates[1] = a_y; }

private:
	// Variables
	float m_coordinates[2];
};

#endif //!VECTOR_2D
