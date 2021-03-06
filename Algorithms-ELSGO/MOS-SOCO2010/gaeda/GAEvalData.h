// $Header: /home/cvs/galib/ga/GAEvalData.h,v 1.1.1.1 1999/11/11 18:56:03 mbwall Exp $
/* ----------------------------------------------------------------------------
  eval.h
  mbwall 3dec95
  Copyright (c) 1995 Massachusetts Institute of Technology
                     all rights reserved

 DESCRIPTION:
  This is the basic interface for the object that contains evaluation data.  It
can be used with genomes and/or populations in combination with their 
respective evaluation methods.
---------------------------------------------------------------------------- */

#ifndef GAEVALDATA_H
#define GAEVALDATA_H

class GAEvalData {

   public:

      GAEvalData () {}
      GAEvalData (const GAEvalData&) {}
      virtual ~GAEvalData () {}

      GAEvalData& operator= (const GAEvalData& orig) {

         if (&orig != this)
            copy (orig);

         return *this;

      }

      virtual GAEvalData* clone () const = 0;
      virtual void copy (const GAEvalData&) = 0;

};

#endif
