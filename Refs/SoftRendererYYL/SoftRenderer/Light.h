#pragma once
#include "pch.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "Color.h"
#include "Geometry.h"
#include "Material.h"

class Light
{
public:
	Light() : ambient(0.2f), diffuse(0.8f), specular(1.0f) {}
	Light(const Color& c) : color(c), ambient(0.2f), diffuse(0.8f), specular(1.0f) {}
	virtual ~Light() {};

	virtual void LightColorCalculaiton(const Vector4& camera_pos, 
		const Vector4& world_pos, const Vector4& normal, Color& pixel_color) = 0;

	virtual void LightTextureCalculaiton(const Vector4& camera_pos,
		const Vector4& world_pos, const Vector4& normal, const Vector3& tex,
		std::shared_ptr<Material> materal, Color& pixel_color) = 0;

	virtual Vector4 GetPosition() const = 0;

	void SetColor(const Color& c) { color = c; }
	Color GetColor() const { return color; }

	float GetAmbient() const { return ambient; }
	float GetDiffuse() const { return diffuse; }
	float GetSpecular() const {return specular;}

private:
	Color color;
	float ambient;
	float diffuse;
	float specular;
};

class PointLight final:public Light
{
public:
	PointLight() {}
	PointLight(const Vector4& p)
	{
		position = p;
	}
	PointLight(const Vector4& p, const Color& c)
	{
		position = p;
		SetColor(c);
	}
	virtual ~PointLight() {};

	virtual void LightColorCalculaiton(const Vector4& camera_pos,
		const Vector4& world_pos, const Vector4& normal, Color& pixel_color) override;

	virtual void LightTextureCalculaiton(const Vector4& camera_pos,
		const Vector4& world_pos, const Vector4& normal, const Vector3& tex,
		std::shared_ptr<Material> materal, Color& pixel_color) override;

	//void SetPosition(const Vector4& d) { position = d; }
	virtual Vector4 GetPosition() const override { return position; }

private:
	Vector4 position;
};

class DirectLight final :public Light
{
public:
	DirectLight() {};
	DirectLight(const Vector4& d)
	{
		direction = d;
	}
	DirectLight(const Vector4& d, const Color& c)
	{
		direction = d;
		SetColor(c);
	}
	virtual ~DirectLight() {};

	virtual void LightColorCalculaiton(const Vector4& camera_pos,
		const Vector4& world_pos, const Vector4& normal, Color& pixel_color) override;

	virtual void LightTextureCalculaiton(const Vector4& camera_pos,
		const Vector4& world_pos, const Vector4& normal, const Vector3& tex,
		std::shared_ptr<Material> materal, Color& pixel_color) override;

	//void SetDirection(const Vector4& d) { direction = d; }
	virtual Vector4 GetPosition() const override { return direction; }

private:
	Vector4 direction;
};