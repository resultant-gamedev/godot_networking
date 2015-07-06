# Godot networking

The main goals of this project are:

* Better documentation for Godot's networking classes.
* A library with a higher-level API to assist development of games that requires
networking. 

## Why

In order to develop a library with a higher-level API, I'll need to understand
how Godot networking works. Documentation and examples really (!) seems to be
missing, so I'll just document the process and hopefully help others too.

## HTTPHelper

Godot provides an HTTPClient class, but it's somewhat low-level and requires 
manual `poll` calls in order to update the status. The HTTPHelper provides the 
following functionalities:

* Simple methods such as `get(url)`, `post(url, data)`, `put(url, data)` and `delete(url)` to perform requests.
* The URL may be specified as a single string instead of (host, port, path)
* Serialize to JSON the data of POST and PUT requests if it's an array or dictionary.
* Timeout failure when attempting to connect to a bad URL.
* Signals instead of polling(`connected`, `connection_failed`, `after_response`, etc)
* Cache keep-alive connections (requests to the same host will use the same connection)

The HTTPHelper inherits from HTTPClient to ensure compatibility with existing
code.

A simple GET request

```gdscript
var http_helper = HTTPHelper.new()
http_helper.get("www.godotengine.org")
yield(http_helper, "after_response")
print(http_helper.response.body)
```

The response object is also the argument for `after_response` signal

```gdscript
func _after_response(response):
    print(response.status) # 200
    print(response.body) # HTML output
    print(response.headers) # [...] Connection: keep-alive [...]

var http_helper = HTTPHelper.new()
http_helper.get("www.godotengine.org/")
http_helper.connect("after_response", self, "_after_response")
```

