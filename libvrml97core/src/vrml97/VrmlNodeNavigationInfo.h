//
//  Vrml 97 library
//  Copyright (C) 1998 Chris Morley
//  See the file COPYING for license details.
//
//  VrmlNodeNavigationInfo.h

#ifndef VRMLNODENAVIGATIONINFO_H
#define VRMLNODENAVIGATIONINFO_H

#include "VrmlNodeChild.h"
#include "VrmlMFFloat.h"
#include "VrmlMFString.h"
#include "VrmlSFBool.h"
#include "VrmlSFFloat.h"

class VrmlNodeNavigationInfo : public VrmlNodeChild {

public:

  // Define the built in VrmlNodeType:: "NavigationInfo"
  static VrmlNodeType *defineType(VrmlNodeType *t = 0);
  virtual VrmlNodeType & nodeType() const;

  VrmlNodeNavigationInfo(VrmlScene *scene);
  virtual ~VrmlNodeNavigationInfo();

  virtual VrmlNode *cloneMe() const;

  virtual VrmlNodeNavigationInfo* toNavigationInfo() const;

  // Bindable nodes must notify the scene of their existence.
  virtual void addToScene( VrmlScene *s, const char *relUrl );

  virtual ostream& printFields(ostream& os, int indent);

  virtual void eventIn(double timeStamp,
		       const char *eventName,
		       const VrmlField *fieldValue);

  // Get a field or eventOut by name.
  virtual const VrmlField *getField(const char *fieldName) const;
  
  virtual void setField(const char *fieldName, const VrmlField &fieldValue);

  float *avatarSize()		{ return d_avatarSize.get(); }
  bool headlightOn()		{ return d_headlight.get(); }
  float speed()			{ return d_speed.get(); }
  float visibilityLimit()	{ return d_visibilityLimit.get(); }

private:

  VrmlMFFloat d_avatarSize;
  VrmlSFBool d_headlight;
  VrmlSFFloat d_speed;
  VrmlMFString d_type;
  VrmlSFFloat d_visibilityLimit;

  VrmlSFBool d_isBound;		// eventOut
};

#endif
