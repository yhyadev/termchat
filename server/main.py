import tornado.ioloop
import tornado.escape
import tornado.web
import tornado.websocket

class ConnectionManager (tornado.websocket.WebSocketHandler):
    def open(self):
        print("New user connected") 

    def on_message(self, message):
        data = tornado.escape.json_encode(message)

        self.write_message(data)
    

    def on_close(self):
        print("We lost a user")


applcation = tornado.web.Application([
    (r"/", ConnectionManager)
])

applcation.listen(8080)
tornado.ioloop.IOLoop.instance().start()
