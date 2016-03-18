#ifndef _DIVISION_VIOLATED_EXCEP
#define _DIVISION_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

/** @class PrecondViolatedExcep PrecondViolatedExcep.h "PrecondViolatedExcep.h"
 *
 *  Specification for an object thrown on violation of precondition. */
class DivisionExc : public logic_error {
 public:

  explicit DivisionExc(const string& message = "");

  virtual ~DivisionExc() noexcept; //throw();
};

#endif
