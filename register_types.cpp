#include "register_types.h"
#include "object_type_db.h"
#include "http_helper/http_helper.h"
#include "http_helper/http_response.h"

void register_networking_types() {
    ObjectTypeDB::register_type<HTTPHelper>();
    ObjectTypeDB::register_type<HTTPResponse>();
}

void unregister_networking_types() {
}