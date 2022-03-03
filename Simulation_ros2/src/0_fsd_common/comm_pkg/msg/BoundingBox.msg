#IMPORTANT!! DONT NAME A MESSAGE CLASS. THAT DESTROYS EVERYTHING
#ToDo Find out what name is clever here
uint8 cone_class
float64 probability
int64 xmin
int64 ymin
int64 xmax
int64 ymax
geometry_msgs/Point[] keypoints
geometry_msgs/Point estimate

uint8 YELLOW_CONE = 4
uint8 BLUE_CONE = 5
uint8 SMALL_ORANGE_CONE = 6
uint8 LARGE_ORANGE_CONE = 7
uint8 UNKNOWN_CONE = 8
