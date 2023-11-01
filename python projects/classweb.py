from http.server import HTTPServer,BaseHTTPRequestHandler
hostname = "0.0.0.0"
portnumber = 8080
publish_this = " "


class servername (BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        print (self.path)
        global publish_this
        
        publish_this += "<br>"+self.path
        publish_this + publish_this.replace("favicon.ico"," ")
        publish_this + publish_this.replace("/"," ")
        publish_this + publish_this.replace("%20"," ")
        self.wfile.write(bytes(publish_this ,"utf-8"))

if __name__=="__main__":
    webserver = HTTPServer ((hostname,portnumber),servername)
    print("Yes, you have the webserver running as http://%s:%s" %(hostname,portnumber))

    try: webserver.serve_forever()

    except KeyboardInterrupt:
        pass
webserver.server_close()
print("Hey, looks like you stopped the server from running. Nice try")
