#include <string.h>
#include "string_sample.h"

void MyString::Set(const char* c_string) {
    if(c_string == NULL) return;
    
    const size_t length = strlen(c_string);
    const char* const temp = new char[length + 1];
    memcpy((void*)temp, (const void*)c_string, length + 1);
    delete[] c_string_;
    c_string_ = temp;
}