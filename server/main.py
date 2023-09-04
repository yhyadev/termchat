import tornado.ioloop
import tornado.web
import tornado.websocket

class Connection (tornado.websocket.WebSocketHandler):
    def open(self):
        print("New user connected") 

    def on_close(self):
        print("We lost a user")


applcation = tornado.web.Application([
    (r"/", Connection)
])

applcation.listen(8080)
tornado.ioloop.IOLoop.instance().start()
