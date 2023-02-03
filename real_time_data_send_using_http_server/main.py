import http.server
import socketserver

PORT = 80

class MyRequestHandler(http.server.BaseHTTPRequestHandler):
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length).decode()
        distance = post_data.split('=')[1]
        print(distance)
        with open('data.txt', 'a') as file:
            file.write(distance + '\n')
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.wfile.write(bytes('Data received: ' + distance, 'utf-8'))

with socketserver.TCPServer(("", PORT), MyRequestHandler) as httpd:
    print("Serving at port", PORT)
    httpd.serve_forever()
