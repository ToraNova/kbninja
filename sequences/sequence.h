/*
 * Sequence super class definition
 */

#ifndef SEQUENCE
#define SEQUENCE

class Sequence{
   public:
      // pure virtual function
      int (*launch)(void);
      char *title;

      Sequence(int (*f)(void), char *t){
	      launch = f;
	      title = t;
      };
};

#endif
