//
//  Vrml 97 library
//  Copyright (C) 1998 Chris Morley
//  See the file COPYING for license details.
//
# ifndef SYSTEM_H
#   define SYSTEM_H
//
//  System dependent utilities class
//

#   include <stddef.h>

class System {

public:

  virtual double time();

  virtual void error(const char *, ...);

  virtual void warn(const char *, ...);

  virtual void inform(const char *, ...);

  virtual void debug(const char *, ...);

#ifdef macintosh
  virtual bool loadUrl(char *url, int np, char **parameters );
#else
  virtual bool loadUrl(const char *url, size_t np, char const * const * parameters );
#endif

  virtual int connectSocket( const char *host, int port );

  virtual const char *httpHost(const char *url, int *port);
  virtual const char *httpFetch( const char *url );

  virtual void removeFile( const char *fn );

};

extern System *theSystem;

#endif // SYSTEM_H
