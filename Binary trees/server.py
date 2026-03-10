from http.server import HTTPServer, SimpleHTTPRequestHandler

# Replace with your IPv4 address
IP = "your ip address"
PORT = 8000

server = HTTPServer((IP, PORT), SimpleHTTPRequestHandler)

print("WiFi Server Running")
print(f"Open on mobile:")
print(f"http://{IP}:{PORT}")

server.serve_forever()