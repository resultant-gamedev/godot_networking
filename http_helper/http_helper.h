#ifndef HTTP_HELPER_H
#define HTTP_HELPER_H

#include "reference.h"
#include "io/http_client.h"
#include "http_response.h"
#include "scene/main/node.h"

// Function that will run in the thread created for the request.

class HTTPHelper : public Node {
    OBJ_TYPE(HTTPHelper, Node);

private:
    // Host the server is running. Don't need to strip "http://" or
    // "https://" prefix becuase HTTPClient already deals with it.
    String host;

    // Port the HTTP server is listening to (default = 80).
    int port;

    // Path of the request including the querystring (default = "/").
    String path;

    // HTTPClient used to perform the request.
    HTTPClient http_client;

    // Establishes the TCP connection to the host.
    // Called by _perform_request
    void _connect_to_host();

    // Makes the request to the
    void _perform_request(HTTPClient::Method method, const String& raw_data);

    // Splits the specified url into host, port and path, and assign the values
    // to the private variables "host", "port" and "path".
    void _split_and_assign_url(const String& url);

protected:
    static void _bind_methods();

public:
    // Returns true if in the middle of a request, false if not.
    bool is_requesting();

    // Cache the latest response in case the user uses a yield to wait for
    // the response.
    Ref<HTTPResponse> response;

    // Performs a GET request to the specified path
    Error GET(const String& path);

    explicit HTTPHelper();
};

#endif