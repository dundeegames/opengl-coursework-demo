#include"st_quaternion.h"


//Quaternion::Quaternion()
//{
//  mData[0] = mData[1] = mData[2] = 0;
//  mData[3] = 1;
//}
//
//// -----------------------------------------------------------------------------
//
//Quaternion::Quaternion( Vec3& v, double w)
//{
//  mData[0] = v.getX();
//  mData[1] = v.getY();
//  mData[2] = v.getZ();
//  mData[3] = w;
//}
//
//// -----------------------------------------------------------------------------
//
//Quaternion::Quaternion(const TVector4& v)
//{
//  mData[0] = v.element(0,0);
//  mData[1] = v.element(1,0);
//  mData[2] = v.element(2,0);
//  mData[3] = v.element(3,0);
//}
//
//// -----------------------------------------------------------------------------
//
//Quaternion::Quaternion(const double* array)
//{
//  if (!array)
//  {
//    UAV_EXCEPTION("Constructing quaternion from 0 array.");
//  }
//
//  for (int i = 0; i < 4; i++)
//  {
//    mData[i] = array[i];
//  }
//
//}
//
//// -----------------------------------------------------------------------------
//
//Quaternion::Quaternion(double x, double y, double z, double w)
//{
//  mData[0] = x;
//  mData[1] = y;
//  mData[2] = z;
//  mData[3] = w;
//}
//
//// -----------------------------------------------------------------------------
//
//Quaternion Quaternion::conjugate(void) const
//{
//  return Quaternion(-complex(), real());
//}
//
//// -----------------------------------------------------------------------------
//
//
///*! 
//* @brief Computes the inverse of this quaternion.
//*
//* @note This is a general inverse.  If you know a priori
//* that you're using a unit quaternion (i.e., norm() == 1),
//* it will be significantly faster to use conjugate() instead.
//* 
//* @return The quaternion q such that q * (*this) == (*this) * q
//* == [ 0 0 0 1 ]<sup>T</sup>.
//*/
//Quaternion Quaternion::inverse(void) const
//{
//  return conjugate() / norm();
//}
//
//// -----------------------------------------------------------------------------
//
///*! 
//* @brief Computes the product of this quaternion with the
//* quaternion 'rhs'.
//*
//* @param rhs The right-hand-side of the product operation.
//*
//* @return The quaternion product (*this) x @p rhs.
//*/
//Quaternion Quaternion::product(const Quaternion& rhs) const
//{
//  return Quaternion(y()*rhs.z() - z()*rhs.y() + x()*rhs.w() + w()*rhs.x(),
//                    z()*rhs.x() - x()*rhs.z() + y()*rhs.w() + w()*rhs.y(),
//                    x()*rhs.y() - y()*rhs.x() + z()*rhs.w() + w()*rhs.z(),
//                    w()*rhs.w() - x()*rhs.x() - y()*rhs.y() - z()*rhs.z());
//}
//
//
//
//
//
//
//
//
//
//
//
//// -----------------------------------------------------------------------------
//
//Quaternion::~Quaternion()
//{
//
//}

// -----------------------------------------------------------------------------








// 80 //////////////////////////////////////////////////////////////////////////