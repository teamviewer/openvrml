//
//  Vrml 97 library
//  Copyright (C) 1998 Chris Morley
//  See the file COPYING for license details.
//
#ifndef SCRIPTOBJECT_H
#define SCRIPTOBJECT_H
//
//  Abstract Script Object class
//

class VrmlField;
class VrmlMFString;
class VrmlNodeScript;

class ScriptObject {

protected:  
  ScriptObject();		// Use create()

public:

  virtual ~ScriptObject() = 0;

  // Script object factory.
  static ScriptObject *create( VrmlNodeScript *, VrmlMFString &url );

  // Invoke a named function
  virtual void activate( double timeStamp,
			 const char *fname,
			 int argc,
			 const VrmlField *argv[] ) = 0;

};

#endif // SCRIPTOBJECT_H
