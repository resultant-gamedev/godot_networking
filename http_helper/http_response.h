#ifndef HTTP_HELPER_RESPONSE_H
#define HTTP_HELPER_RESPONSE_H

#include "reference.h"

class HTTPResponse : public Reference {
    OBJ_TYPE(HTTPResponse, Reference);

protected:
    static void _bind_methods();

public:
    virtual ~HTTPResponse();
    explicit HTTPResponse();
};

#endif