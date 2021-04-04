<h1>Just making some notes:</h1>

- I'm using the same engine TCP write in the ServerTCP class and ClientTCP for both questions (use thread for all the problems seems to be a great idea), FileIOHandler is also coupleeed as needed (for both).
- The program was compiled using C++ 17 so you will need to use (-std=c++17 and -pthread) if you want to recompile all exec.
- Chat feature (chat-server and chat-client) are configured to interactive mode (i'm not sure if it's necessary send files) but you can use it to send files too just coupling a FileIOHandler class to the ServerTCP using the standard setter and it will work. 
