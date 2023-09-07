import socket
import threading


class ConnectionThread(threading.Thread):
    def __init__(self, connection_socket: socket.socket, connection_address) -> None:
        threading.Thread.__init__(self)

        self.connection_socket = connection_socket
        self.connection_address = connection_address

    def run(self) -> None:
        print("User joined the chat")

        while True:
            data = self.connection_socket.recv(1024)
            self.connection_socket.sendall(data)

            if not data:
                print("We lost a user")
                break


class ConnectionManager:
    def __init__(self, ip_address: str, port: int, connection_socket: socket.socket):
        connection_socket.bind((ip_address, port))

        while True:
            connection_socket.listen(1)

            connection_thread = ConnectionThread(*connection_socket.accept())
            connection_thread.start()


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as connection_socket:
    ConnectionManager("127.0.0.1", 8080, connection_socket)
