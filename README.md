# RRT_Algorithm
Implemented Rapidly-exploring Random Tree Algorithm.

The starting and ending point are given as inputs. I have assumed a coordinate plane of say 100 X 100. Then random generate a point (x,y). calculate its distance from the available nodes. if its less than a particular value say epilson, then I have added it as a node and connect an edge to its nearest node else added a nodes at a distance of epilson in the direction of random point and nearest node and discard the random point. Repeat the same process.
After the above process I have applied Depth-First Search to find the path from the ending point to the starting point.

Taking the starting point as the initial node as the loop iterates the network grows and as soon as there is a node close to the ending point I track the path using Depth-First Search.
