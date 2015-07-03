#ifndef HTTP_CACHE_H
#define HTTP_CACHE_H

// A little explanation about this:
//
// It's defined in the HTTP spec a header called Connection with most common
// values being "Close" and "Keep-alive". If a request is made with
// "Connection: close", it tells the server that the client doesn't support
// persistent connection. If the request is made with
// "Connection: keep-alive" and the server replies with "Connection: keep-alive"
// (it means both client and host support persistent connections), HTTPCache
// will store the connection and subsequent requests for the same host will use
// the same connection.
//
// If you attempt to request the same host twice while the first request
// is still processing, a new connection will be opened and cached.

#endif
