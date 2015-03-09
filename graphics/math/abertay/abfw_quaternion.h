//// /////////////////////////////////////////////////////////////////////////////
///*!                                                                           \n
//*                Quaternion class - WinAPI and OpenGL laboratory              \n
//*                             by Mr. Grant Clark                              \n
//*                                                                             \n
//* Based on Font class from Abertay Framework for PS Vita                      \n
//* Mr. Grant Clark.[2015].Abertay Framework.Console Game Development           \n
//*                                                                             \n
//*/ /////////////////////////////////////////////////////////////////////////////
//
//
//
//#ifndef QUATERNION_H
//#define QUATERNION_H
//
//
//// INCLUDES ////////////////////////////////////////////////////////////////////
//#include <cmath>
//
//
//
//
//
//class Quaternion
//{
//public:
//	Quaternion();
//	Quaternion(float x, float y, float z, float w);
//	void SetFromMatrix(const class Matrix44& matrix);
//	const Quaternion operator * (const Quaternion& quaternion) const;
//	const Quaternion operator -() const;
//	const Quaternion operator *(float scale) const;
//	const Quaternion operator /(float scale) const;
//	const Quaternion operator +(const Quaternion &q) const;
//	float LengthSquared() const;
//	float Length() const;
//	void Normalise();
//	void Identity();
//	void Lerp(const Quaternion& startQ, const Quaternion& endQ, float time);
//	void Slerp(const Quaternion& startQ, const Quaternion& endQ, float time);
//	void Conjugate(const Quaternion& quaternion);
//	
//
//	float x;
//	float y;
//	float z;
//	float w;
//};
//
//#include "abfw_quaternion.inl"
//
//
//#endif // QUATERNION_H
//
//
//
//
//// 80 //////////////////////////////////////////////////////////////////////////