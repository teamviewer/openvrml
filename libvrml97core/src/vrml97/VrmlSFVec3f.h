//
//  Vrml 97 library
//  Copyright (C) 1998 Chris Morley
//  See the file COPYING for license details.
//
#ifndef  _VRMLSFVEC3F_
#define  _VRMLSFVEC3F_

#include "VrmlField.h"


class VrmlSFVec3f : public VrmlSField {
public:

  VrmlSFVec3f(float x = 0.0, float y = 0.0, float z = 0.0);
  VrmlSFVec3f(const VrmlSFVec3f& rhs);

  virtual ostream& print(ostream& os) const;

  virtual VrmlField *clone() const;

  virtual VrmlFieldType fieldType() const;
  virtual const VrmlSFVec3f* toSFVec3f() const;
  virtual VrmlSFVec3f* toSFVec3f();

  float x() const		{ return d_x[0]; }
  float y() const		{ return d_x[1]; }
  float z() const		{ return d_x[2]; }

  float *get()			{ return &d_x[0]; }

  void set(float x, float y, float z)
    { d_x[0] = x; d_x[1] = y; d_x[2] = z; }

  // return result
  double dot( VrmlSFVec3f * );
  double length();

  // modifiers
  void normalize();

  void add( VrmlSFVec3f * );
  void cross( VrmlSFVec3f * );
  void divide( float );
  void multiply( float );
  void subtract( VrmlSFVec3f * );

private:
  float d_x[3];

};

#endif _VRMLSFVEC3F_
