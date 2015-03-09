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
//#include "abfw_quaternion.h"
//
//
//
//void Quaternion::Identity()
//{
//	x = 0.0f;
//	y = 0.0f;
//	z = 0.0f;
//	w = 1.0f;
//}
//
//
////void Quaternion::SetFromMatrix(const Matrix44& matrix)
////{
////	int i, maxi;
////	float maxdiag, S, trace;
////	trace = matrix.m[0][0] + matrix.m[1][1] + matrix.m[2][2] + 1.0f;
////	// tried comparing trace to 0.0f, but got incorrect result when trace was 5.0 x 10e-5
////	if ( trace > 0.000001f)
////	{
////		x = ( matrix.m[1][2] - matrix.m[2][1] ) / ( 2.0f * std::sqrtf(trace) );
////		y = ( matrix.m[2][0] - matrix.m[0][2] ) / ( 2.0f * std::sqrtf(trace) );
////		z = ( matrix.m[0][1] - matrix.m[1][0] ) / ( 2.0f * std::sqrtf(trace) );
////		w = std::sqrtf(trace) / 2.0f;
////		return;
////	}
////	maxi = 0;
////	maxdiag = matrix.m[0][0];
////	for (i=1; i<3; i++)
////	{
////		if ( matrix.m[i][i] > maxdiag )
////		{
////			maxi = i;
////			maxdiag = matrix.m[i][i];
////		}
////	}
////	switch( maxi )
////	{
////	case 0:
////		S = 2.0f * std::sqrtf(1.0f + matrix.m[0][0] - matrix.m[1][1] - matrix.m[2][2]);
////		x = 0.25f * S;
////		y = ( matrix.m[0][1] + matrix.m[1][0] ) / S;
////		z = ( matrix.m[0][2] + matrix.m[2][0] ) / S;
////		w = ( matrix.m[1][2] - matrix.m[2][1] ) / S;
////		break;
////	case 1:
////		S = 2.0f * std::sqrtf(1.0f + matrix.m[1][1] - matrix.m[0][0] - matrix.m[2][2]);
////		x = ( matrix.m[0][1] + matrix.m[1][0] ) / S;
////		y = 0.25f * S;
////		z = ( matrix.m[1][2] + matrix.m[2][1] ) / S;
////		w = ( matrix.m[2][0] - matrix.m[0][2] ) / S;
////		break;
////	case 2:
////		S = 2.0f * std::sqrtf(1.0f + matrix.m[2][2] - matrix.m[0][0] - matrix.m[1][1]);
////		x = ( matrix.m[0][2] + matrix.m[2][0] ) / S;
////		y = ( matrix.m[1][2] + matrix.m[2][1] ) / S;
////		z = 0.25f * S;
////		w = ( matrix.m[0][1] - matrix.m[1][0] ) / S;
////		break;
////	}
////}
//
//void Quaternion::Lerp(const Quaternion& startQ, const Quaternion& endQ, float time)
//{
//	x = (1.0f - time) * startQ.x + time * endQ.x;
//	y = (1.0f - time) * startQ.y + time * endQ.y;
//	z = (1.0f - time) * startQ.z + time * endQ.z;
//	w = (1.0f - time) * startQ.w + time * endQ.w;
//}
//
//void Quaternion::Slerp(const Quaternion& startQ, const Quaternion& endQ, float time)
//{
//	float dot = startQ.x*endQ.x + startQ.y*endQ.y + startQ.z*endQ.z + startQ.w*endQ.w;
//	if(dot >= 1.0f)
//	{
//		*this = endQ;
//	}
//	else
//	{
//		/*	dot = cos(theta)
//			if (dot < 0), q1 and q2 are more than 90 degrees apart,
//			so we can invert one to reduce spinning	*/
//		Quaternion targetQ;
//		if (dot < 0.0f)
//		{
//			dot = -dot;
//			targetQ = -endQ;
//		}
//		else
//			targetQ = endQ;
//		
//		float angle = std::acosf(dot);
//		*this = (startQ*std::sinf(angle*(1.0f-time)) + targetQ*std::sinf(angle*time))/std::sinf(angle);
//	}
//
//}
//
//// result = this * quaternion;
//// when used to represent rotations
//// the result quaternion represents an initial rotation specified by quaternion rotated by "this"
//
//const Quaternion Quaternion::operator * (const Quaternion& quaternion) const
//{
//	Quaternion result;
//
//	result.x = quaternion.w * x + quaternion.x * w + quaternion.y * z - quaternion.z * y;
//	result.y = quaternion.w * y - quaternion.x * z + quaternion.y * w + quaternion.z * x;
//	result.z = quaternion.w * z + quaternion.x * y - quaternion.y * x + quaternion.z * w;
//	result.w = quaternion.w * w - quaternion.x * x - quaternion.y * y - quaternion.z * z;
//    return result;
//}
//
//void Quaternion::Normalise()
//{
//	float length = Length();
//
//	x /= length;
//	y /= length;
//	z /= length;
//	w /= length;
//}
//
//void Quaternion::Conjugate(const Quaternion& quaternion)
//{
//	x = -quaternion.x;
//	y = -quaternion.y;
//	z = -quaternion.z;
//	w = quaternion.w;
//}