#include "Color.h"


const Color Color::WHITH_COLOR = { 1.0f, 1.0f, 1.0f };
const Color Color::BLACK_COLOR = { 0.0f, 0.0f, 0.0f };
const Color Color::RED_COLOR = { 1.0f, 0.0f, 0.0f };
const Color Color::GREEN_COLOR = { 0.0f, 1.0f, 0.0f };
const Color Color::BLUE_COLOR = { 0.0f, 0.0f, 1.0f };

Color Color::operator+(const Color &other) const
{
	return Color(
		color.x + other.GetColor().x,
		color.y + other.GetColor().y,
		color.z + other.GetColor().z);
}

Color Color::operator-(const Color &other) const
{
	return Color(
		color.x - other.GetColor().x,
		color.y - other.GetColor().y,
		color.z - other.GetColor().z);
}

Color Color::operator*(float k) const
{
	return Color(
		color.x * k,
		color.y * k,
		color.z * k);
}

Color Color::operator*(const Color &other) const
{
	return Color(color.x * other.GetColor().x,
		color.y * other.GetColor().y,
		color.z * other.GetColor().z);
}

Color Color::operator/(float k) const
{
	float oneOver = 1.0f / (k+FLT_MIN);
	return Color(
		color.x * oneOver,
		color.y * oneOver,
		color.z * oneOver);
}

void Color::SetColor(float r, float g, float b,float a)
{
	color.x = CLAMP(r, 0.0f, 1.0f);
	color.y = CLAMP(g, 0.0f, 1.0f);
	color.z = CLAMP(b, 0.0f, 1.0f);
	color.w = CLAMP(a, 0.0f, 1.0f);
}

void Color::SetColor(const Vector3& v, float a)
{
	color.x = CLAMP(v.x, 0.0f, 1.0f);
	color.y = CLAMP(v.y, 0.0f, 1.0f);
	color.z = CLAMP(v.z, 0.0f, 1.0f);
	color.w = CLAMP(a, 0.0f, 1.0f);
}

void Color::SetColor(const Vector4& v)
{
	color.x = CLAMP(v.x, 0.0f, 1.0f);
	color.y = CLAMP(v.y, 0.0f, 1.0f);
	color.z = CLAMP(v.z, 0.0f, 1.0f);
	color.w = CLAMP(v.w, 0.0f, 1.0f);
}
