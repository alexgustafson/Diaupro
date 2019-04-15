# DIAUPRO 
## Distributed Audio Processing

A collection of JUCE modules that can be used to distribute audio processing tasks over a network.

The code was originally part of this project : https://github.com/alexgustafson/DiauproProject


### Modules:

#### Socket Monitor 

The Monitor class was created to handle sockets efficiently. Client classes can implement the FileDescriptorListener class can be extended by clients that wish to be notified when data is available to read from on a specific socket.
The Monitor class has a thread that blocks on a system select() call. The select is given an array of sockets as file descriptors. When one of the sockets is ready to read from the select call unblocks. The thread loops through the array to find the socket that is ready, and notifies the corresponding listener.
One of the sockets passed to the select() call is the Monitor’s own control listener socket. The Monitor class can send a signal to this socket when ever it need to wake the blocked thread from the select() call and update it’s state. The Monitor class does this whenever a new client registers or removes itself, and when the Monitor class needs to shut down.

#### ZeroConf Manager

Zeroconf (short for Zero Configuration Network and also know as Bonjour on OSX ) is a specification that allows services to broadcast their availability and location on a network. Printer and Multimedia devices use Zeroconf in order to allow networked computers to easily find and use their services.
Bonjour on OSX and the compatibile features implemented by Avahi on Linux define a callback based API that interfaces to a bonjour or avahi daemon running on the OS. The Bonjour API is in C. The ZeroConfManager class encapsulates communica- tion to the bonjour or avahi deamon in an object oriented manner. Clients that want to interface with this class must extend and override the ZeroConfListener class, they register themselves with the ZeroConfManager.

When new services are registered on the network, or removed from the network, the corresponding listeners are notified with a list of all active services. If they are currently connected with a service that is no longer available, it is the clienst responsibility to disconnect from that service.
In order to resolve a service to a specific IP address and port number several asynchronous calls must be made to the Bonjour daemon, saving and updating the state of each result between calls. The ZeroConfManager hides this complexity from it’s clients and only notifies them when all the information is complete.
