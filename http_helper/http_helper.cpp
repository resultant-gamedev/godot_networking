#include "http_helper.h"

void HTTPHelper::_bind_methods() {
    ObjectTypeDB::bind_method(_MD("GET", "url_path"), &HTTPHelper::GET);
    ObjectTypeDB::bind_method(_MD("is_requesting"), &HTTPHelper::is_requesting);
}

void HTTPHelper::_split_and_assign_url(const String& url) {
    int first_index = 0;
    if(url.begins_with("http://")) {
        first_index = 7;
    } else if(url.begins_with("https://")) {
        first_index = 8;
    }

    int first_colon_index = url.find(":", first_index);
    int first_slash_index = url.find("/", first_index);

    if(first_colon_index > 0) {
        // The port will be every character from first_colon_index to 
        // first_slash_index. If there is no first_slash_index, the port goes
        // to the end of the url.
        if(first_slash_index > 0) {
            // The second argument for substr is the length and not the end 
            // index.
            this->port = url.substr(first_colon_index, 
                first_slash_index - first_colon_index).to_int();
        } else {
            this->port = url.substr(first_colon_index,
                url.length() - first_colon_index).to_int();
        }
    }

    // The user specified a path
    if(first_slash_index > 0) {
        this->path = url.substr(first_slash_index,
            url.length() - first_slash_index);
    }

    // Identifying the host
    if(first_colon_index > 0) {
        this->host = url.substr(0, url.length() - first_colon_index);
    } else {
        if(first_slash_index > 0) {
            this->host = url.substr(0, url.length() - first_slash_index);
        } else {
            this->host = url;
        }
    }
}

bool HTTPHelper::is_requesting() {
    return false;
}

Error HTTPHelper::GET(const String& url) {
    _split_and_assign_url(url);
    return OK;
}

HTTPHelper::HTTPHelper() {
    host = "localhost";
    port = 80;
    path = "/";
}