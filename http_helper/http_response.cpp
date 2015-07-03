#include "http_response.h"

void HTTPResponse::_bind_methods() {
}

HTTPResponse::HTTPResponse() {
    print_line("Constructor of HTTPResponse");
}

HTTPResponse::~HTTPResponse() {
    print_line("Destructor of HTTPResponse");
}