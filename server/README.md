#server

ssh cjm@104.131.10.102 
ssh cjm@104.131.10.102 "mkdir -p /home/cjm/mwe_networked_fps_game/"



// send over the server
scp ./build/Release/server cjm@104.131.10.102:/home/cjm/mwe_networked_fps_game/server

// pull the logs back over
scp cjm@104.131.10.102:/home/cjm/mwe_networked_fps_game/logs/logs.txt ./logs/server_logs.txt


