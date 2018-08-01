# Need4Stek
Need4Stek Epitech project bonus, including Mario Kart multiplayer

./tek_kart for usage, or -h

This game has been created using CSFML library,
It has been coded by respecting the Epitech's norm.

I implemented a Physical Engine, that allows your kart to skid more of less depending on your speed,
your kart will not accelerate instantly too, acceleration is handled, as well as the inertia of your kart.

Collisions between you and walls is handled, you can exit the game by pressing the exit button, or ESC.
ZQSD or arrows to move your kart.

You are able to see the other players on the dynamic minimap, and directly in the game, don't mind me, but I failed at
only displaying them if they are not behind a wall.

There is a bunch of sounds, such as acceleration, skids, lobby sound and start countdown.

When the host is selecting a map, a "LOADING" screen will appear on clients screens, after the map is selected, the game
will start when all the clients did download the map.

That means that you do not need to have the map on your computer to play it, only the Host will need to have it.

The game works using sockets with TCP protocol, feel free to change the # define PORT if the actual 4697 port is not good for you, but consider that all the clients will need to do the same (yeah I should have add a -p option).

There is a bunch of 'debug' and 'status' informations in the terminal while running the game, and basicly, your local and public ip.

When you leave the game, your "score" which is your time done, is written in a file called "score.dat" in it, you'll have your 
nickname <nickname> and your score "1min05" for example, so you can play "against the clock".
  
All the sources are in the src file, and the libraries that i'm using are:
  -glibC
  -CSFML
  -my own C library

./tek_kart --server <nickname>
./tek_kart --join <ip> <nickname>

took 41 hours to make

video at https://youtu.be/0vzke_rMuPE

Léandre Blanchard
{ Epitech } 2021
Paris
