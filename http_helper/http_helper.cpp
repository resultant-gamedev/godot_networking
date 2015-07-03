#include "http_helper.h"

void HTTPHelper::_bind_methods() {
    ObjectTypeDB::bind_method(_MD("get", "url_path"), &HTTPHelper::get);
    ObjectTypeDB::bind_method(_MD("get_response"), &HTTPHelper::get_response);
}

Error HTTPHelper::get(const String& url) {
    return Ok;
}

HTTPHelper::HTTPHelper() {
}