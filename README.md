# Bus route finder
OOPS ADS SEM-4-Project

A mini project that utilizes Dijkstra's shortest path algorithm to suggest a suitable bus or sequence of buses to the users to travel from source city to destination city.
The inputs including graph and bus details are persisted using files.

Documentation: https://docs.google.com/document/d/1tzm89_7C8mtwawNPZ9WHibV5QA-R13avFg7zlQINmG8/edit?usp=sharing
# Data Structure(s) used:
	
<li>Weighted Undirected Graph</li>
	
<li>Unordered_map</li>
	
<li>File handling (Txt Files)</li>
	
<li>Arrays(1D & 2D)</li>

# User defined Modules:
    a. Bus class:
<li>Void init_citynames()  --Reads from cities(vertices) file and initializes the hash map </li>
<li>Void init_bus_no() --Reads from bus file and initialized bus hash map</li>      
<li>Void show() --Shows the details of a particular bus</li>              
    
    b. Graph class

<li>Void addEdge()     --Adding a new bus(Edge) to file and graph</li>
<li>printGraph()          --Reads file from graph and shows the adjacency matrix</li>
<li>shortestRoute()    --Shows which bus/ buses to take to read from City A to City B.</li>
    
    c. get_and_store_bus.cpp 
<li>void addbus()      --Adds a bus corresponding to given edge to the list of buses </li>
<li>void show()        --Reads all bus objects from file and displays their details</li>
<li>void initGraph()  --Initializes graph object</li>

    d. main.cpp 
<li>void logo()   --Displays logo of the project</li>


# Made by:

<li>Harishankar H</li>

<li>Hritik viknesh</li>

<li>Arvind P</li>

