#server

ssh cjm@104.131.10.102 
ssh cjm@104.131.10.102 "mkdir -p /home/cjm/mwe_networked_fps_game/"

// send over the server
scp ./build/Release/server cjm@104.131.10.102:/home/cjm/mwe_networked_fps_game/server

