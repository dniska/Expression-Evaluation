#include "DivisionExc.h"

DivisionExc::DivisionExc(const string& message)
  : logic_error(message.c_str() ) {
}

DivisionExc::~DivisionExc()
  noexcept { //throw() {
}
