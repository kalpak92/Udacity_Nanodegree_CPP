![Screen Shot 2020-05-19 at 11.50.06 PM](/Users/kalpak/Dev_Kalpak/C++/Nanodegree_CPP/4. OpenStreetMap Route Planner/instructions/Screen Shot 2020-05-19 at 11.50.06 PM.png)



The `main.cpp` controls the flow of the program, accomplishing four primary tasks:

- The OSM data is read into the program. 
- A `RouteModel` object is created to store the OSM data in usable data structures.
- A `RoutePlanner` object is created using the `RouteModel`. This planner will eventually carry out the A* search on the model data and store the search results in the `RouteModel`.
- The `RouteModel` data is rendered using the IO2D library.



The `route_planner.h` and `route_planner.cpp`  files define the `RoutePlanner` class and methods for the A* search .



The `model.h` and `model.cpp` files come from the IO2D example code. These files are used to define the data structures and methods that read in and store OSM data. OSM data is stored in a `Model` class which contains nested structs for Nodes, Ways, Roads, and other OSM objects.

The `route_model.h` and `route_model.cpp` files contain classes which are used to extend the `Model` and `Node` data structures from `model.h` and `model.cpp` using class inheritance. 

Remember that inheritance in this case will allow you to use all of the *public* methods and attributes of the `Model` class and `Node` struct in the derived `RouteModel` and `RouteModel::Node` classes.

The reason for extending the existing `Model` class and `Node` struct is to include additional methods and variables which are useful for A* search. In particular, the new `RouteModel::Node` class now allows nodes to store the following:

- the h-value,
- the g-value,
- a "visited" flag,
- a vector of pointers to neighboring nodes.

In addition, there are now methods for

- finding neighboring Node objects of a Node,
- getting the distance to other nodes,
- finding the closest node to a given (x, y) coordinate pair.



The `render.h` and `render.cpp` files come from the IO2D example code. These take map data that is stored in a `Model` object and render that data as a map. We have modified these files slightly to include three extra methods which render the start point, end point, and path from the A* search. 