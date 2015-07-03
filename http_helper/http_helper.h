#ifndef HTTP_HELPER_H
#define HTTP_HELPER_H

#include "reference.h"
#include "io/http_client.h"
#include "http_response.h"
#include "thread.h"

class HTTPHelper : public HTTPClient {
    OBJ_TYPE(HTTPHelper, Reference);

private:

    // Cache the latest response in case the user uses a yield to wait for
    // the response.
    Ref<HTTPResponse> response;

    // Host the server is running. Don't need to strip "http://" or
    // "https://" prefix becuase HTTPClient already deals with it.
    String host;

    // Port the HTTP server is listening to (default = 80)
    int port = 80;

    // Path of the request including the querystring (default = "/")
    String path = "/";

    // Establishes the TCP connection to the host.
    // Called by _perform_request
    void _connect_to_host();

    // Makes the request to the
    void _perform_request(HTTPClient::Method method, const String& raw_data);

    // Called by HTTPCache to prepare the connection to be used in a different
    // request. This method should:
    // * unref the response variable
    void _reset();

protected:
    static void _bind_methods();

public:

    Ref<HTTPResponse> get_response() const;

    // Performs a GET request to the specified path
    Error get(const String& path);

    // Performs a POST request to the specified path with the data encoded
    // as JSON
    Error post(const String& path, Variant data);

    // Performs a PUT request to the specified path with the data encoded
    // as JSON
    Error put(const String& path, Variant data);

    // Performs a DELETE request to the specified path
    Error delete(const String& path);

    explicit HTTPHelper();
};

#endif