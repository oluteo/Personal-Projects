from http.server import HTTPServer, BaseHTTPRequestHandler
from urllib.parse import urlparse, parse_qs
import pandas as pd
import os
hostname = "localhost"
portnumber = 8090
publish_this = ""
Candidates = ['APC', 'PDP', 'YPP', 'PRP', 'APGA']

class server_name(BaseHTTPRequestHandler):
    def do_GET(self):
        query_string = urlparse(self)
        self.send_response(200)
        self.send_header("content-type", "text/html")
        self.end_headers()
        Main = open('Vote.html', "rb")
        self.wfile.write(Main.read())
        values = parse_qs(urlparse(self.path).query)
        
        try:
            if self.path.endswith('/return_scores'):
                df = pd.read_csv('Voter_Records.csv')
                a = df["Party"].value_counts()
                b = pd.DataFrame(a)
                print(b)
                self.wfile.write(bytes(f"{b}", "utf-8"))
            elif self.path.endswith('/max_score'):
                s = pd.read_csv('Voter_Records.csv')
                a = s["Party"].value_counts()
                b = pd.DataFrame(a)
                self.wfile.write(bytes(f"The Party with the Maximum Votes is {b.head(1)}", "utf-8"))
            else:
                the_name=values['name'][0]
                the_party=values['party'][0]
                df_new = pd.DataFrame(data=[[the_name, self.address_string(), the_party]], columns= ["Names", "Voter_id", "Party"])
                if os.path.exists('Voter_Records.csv'):
                    df = pd.read_csv('Voter_Records.csv')
                    vid_list=list(df["Voter_id"])
                    for i in vid_list:
                        if i == self.address_string():
                            self.send_error(404, message="Cannot Vote twice")
                            break
                        else:
                            df = pd.concat([df,df_new], axis=0)
                            df.to_csv('Voter_Records.csv', index=False)
                else:
                    df_new.to_csv('Voter_Records.csv', index=False)
                
            self.wfile.write(bytes(f"Thank You {the_name} for your vote","utf-8"))
            
        except KeyError:
            pass
        



if __name__=="__main__":
    webserver = HTTPServer((hostname, portnumber),server_name)
    print("Great, you have the webserver running as http://%s:%s"  %(hostname,portnumber))

    try:
        webserver.serve_forever()

    except KeyboardInterrupt:
        pass
webserver.server_close()
print("Hey, looks like you stopped the server from running. Nice try")