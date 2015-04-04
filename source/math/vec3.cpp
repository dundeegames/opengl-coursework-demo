#include <math/vec3.h>
#include <system/macros.h>
 
Vec3::Vec3(float x, float y, float z){
    this->elements[0] = x;
    this->elements[1] = y;
    this->elements[2] = z;
    
}


Vec3::~Vec3(){
    
}
 

Vec3 Vec3::copy(){
        Vec3 copy(
                this->elements[0],
                this->elements[1],     
                this->elements[2]
                );
        return copy;           
}

// -----------------------------------------------------------------------------

bool Vec3::equals(const Vec3& v2, float epsilon){
        return ((std::abs(this->elements[0] - v2[0]) < epsilon) &&
                    (std::abs(this->elements[1] - v2[1]) < epsilon) &&
                        (std::abs(this->elements[2] - v2[2]) < epsilon));      
}
 
// -----------------------------------------------------------------------------

float Vec3::length(){
        return std::sqrt(this->lengthSquared());
}
 
// -----------------------------------------------------------------------------

float Vec3::lengthSquared(){
        return (
                this->elements[0]*this->elements[0] +
                this->elements[1]*this->elements[1] +
                this->elements[2]*this->elements[2]
                );
}
 
// -----------------------------------------------------------------------------

Vec3& Vec3::normalize(){
        float mag = this->length();
        if(mag){
                float multiplier = 1.0f/mag;
                this->elements[0] *= multiplier;
                this->elements[1] *= multiplier;
                this->elements[2] *= multiplier;
        }
        return *this;
}
 
// -----------------------------------------------------------------------------

Vec3 Vec3::cross(const Vec3& v2){
        Vec3 cross(
                (this->elements[1] * v2[2] - this->elements[2] * v2[1]),
                (this->elements[2] * v2[0] - this->elements[0] * v2[2]),
                (this->elements[0] * v2[1] - this->elements[1] * v2[0])
        );
        return cross;
}
 
// -----------------------------------------------------------------------------

Vec3 Vec3::subtract(const Vec3& v1, float scale){
        Vec3 sub(
                (this->elements[0] - v1[0]*scale),
                (this->elements[1] - v1[1]*scale),
                (this->elements[2] - v1[2]*scale)
                );
        return sub;
}

// -----------------------------------------------------------------------------

Vec3& Vec3::set(float x, float y, float z){
        this->elements[0] = x;
        this->elements[1] = y;
        this->elements[2] = z;
        return *this;
}

// -----------------------------------------------------------------------------

// Question: Why to return Vec3& when setting parameters? How to use such feature??
Vec3& Vec3::setX(float x){
        this->elements[0] = x;
        return *this;
}
 
// -----------------------------------------------------------------------------

Vec3& Vec3::setY(float y){
        this->elements[1] = y;
        return *this;
}
 
// -----------------------------------------------------------------------------

Vec3& Vec3::setZ(float z){
        this->elements[2] = z;
        return *this;
}

// -----------------------------------------------------------------------------

float Vec3::getX(){
       return this->elements[0];
}
 
// -----------------------------------------------------------------------------

float Vec3::getY(){
       return this->elements[1];
}
 
// -----------------------------------------------------------------------------

float Vec3::getZ(){
      return this->elements[2];
}
 
// -----------------------------------------------------------------------------

float Vec3::dot(const Vec3& v2){
        return (this->elements[0]*v2[0] +
                this->elements[1]*v2[1] +
                this->elements[2]*v2[2]
                );
}
 
// -----------------------------------------------------------------------------

Vec3 Vec3::scale(float scale){
        Vec3 scaled(
                (this->elements[0]*scale),
                (this->elements[1]*scale),
                (this->elements[2]*scale)
                );
        return scaled;
}

// -----------------------------------------------------------------------------

// Question: How is possible to access private elements[] of v1, passed to func as Vec3& ??
Vec3 Vec3::add(const Vec3& v1, float scale){
        Vec3 sum(
                (this->elements[0] + v1[0]*scale),
                (this->elements[1] + v1[1]*scale),
                (this->elements[2] + v1[2]*scale)
                );
        return sum;
}
 
 // -----------------------------------------------------------------------------

float Vec3::operator[](int pos) const{
    return elements[pos];
}
 
// -----------------------------------------------------------------------------

Vec3 Vec3::operator+(const Vec3& v2) {
    return this->add(v2);
}
 
// -----------------------------------------------------------------------------

Vec3 Vec3::operator-(const Vec3& v2) {
    return this->subtract(v2);
}
 
// -----------------------------------------------------------------------------

Vec3& Vec3::operator+=(const Vec3& v2) {
                this->elements[0] += v2[0];
                this->elements[1] += v2[1];
                this->elements[2] += v2[2];
        return *this;
}
 
// -----------------------------------------------------------------------------

Vec3& Vec3::operator-=(const Vec3& v2) {
                this->elements[0] -= v2[0];
                this->elements[1] -= v2[1];
                this->elements[2] -= v2[2];
        return *this;
}

// -----------------------------------------------------------------------------

Vec3 Vec3::rotateInX(float angleX, float scale)
{
  float sinX = sinf(RADIANS(angleX*scale));
  float cosX = cosf(RADIANS(angleX*scale));

  Vec3 rotX(
           ((this->elements[2] * sinX) + (this->elements[0] * cosX)),
           (this->elements[1]),
           ((this->elements[2] * cosX) - (this->elements[0] * sinX))
           );
  return rotX;


}

// -----------------------------------------------------------------------------

Vec3 Vec3::rotateInY(float angleY, float scale)
{
  float sinY = sinf(RADIANS(angleY*scale));
  float cosY = cosf(RADIANS(angleY*scale));

  Vec3 rotY(
           (this->elements[0]),
           ((this->elements[1] * cosY) - (this->elements[2] * sinY)),
           ((this->elements[1] * sinY) + (this->elements[2] * cosY))
           );
  return rotY;

}

// -----------------------------------------------------------------------------

Vec3 Vec3::rotateInZ(float angleZ, float scale)
{
  float sinZ = sinf(RADIANS(angleZ*scale));
  float cosZ = cosf(RADIANS(angleZ*scale));

  Vec3 rotX(
           ((this->elements[0] * cosZ) - (this->elements[1] * sinZ)),
           ((this->elements[0] * sinZ) + (this->elements[1] * cosZ)),
           (this->elements[2])
           );
  return rotX;
}

// -----------------------------------------------------------------------------

//Vec3& Vec3::rotateXY(float angleX, float angleY, float scale)
//{
//  float sinX = sinf(RADIANS(angleX*scale));
//  float cosX = cosf(RADIANS(angleX*scale));
//  float sinY = sinf(RADIANS(angleY*scale));
//  float cosY = cosf(RADIANS(angleY*scale));
//
//  Vec3 rotY(
//           ((this->elements[0]*cosY) + (this->elements[1]*sinX*sinY) + (this->elements[2]*cosX*sinY)),
//           ((this->elements[1]*cosX) + (this->elements[2]*sinX)),
//           ((this->elements[1]*sinX*cosY) + (this->elements[2]*cosX*cosY) - (this->elements[0]*sinY))
//           );
//  return rotY;
//}

// -----------------------------------------------------------------------------

















// 80 //////////////////////////////////////////////////////////////////////////