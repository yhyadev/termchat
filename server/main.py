import socket

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind(("127.0.0.1", 8080))
    s.listen()

    conn, addr = s.accept()
    
    with conn:
        print(f"User Connected")

        while True:
            data = conn.recv(1024)
            conn.sendall(data)
