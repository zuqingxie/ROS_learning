std_msgs/Header header
#lap counter
float32 lap_time     
uint16 lap

comm_pkg/Cone[] map_l_cones
comm_pkg/Cone[] map_r_cones

float32[] delaunay_tpx
float32[] delaunay_tpy
float32 delaunay_phi
float32 delaunay_r_l
float32[] delaunay_p_y
float32 delaunay_horizon
float32 delaunay_rows
float32[] delaunay_path_x
float32[] delaunay_path_y

geometry_msgs/Pose2D path_ref
float32[] memory_points_x
float32[] memory_points_y
float32[] memory_points_wau
float32[] path_parameters
float32 safety_state

float32 e_front 
float32 e_cog
float32 v_des
float32 indic_dir
float32 psi
float32 eta
float32 errorcode
float32[] v_future  #downsampled
float32[] horizonpath_x #downsampled
float32[] horizonpath_y #downsampled
float32[] k_horizon #downsampled
float32 i_horizon
float32[] v_internx0
float32[] v_internforeward
float32[] v_internbackward


float32 drive_mode
int16 internal_case
float32 v_soll_stanley
float32[] int_states_stanley
float32 tln_state 

float32 u_plant_des_throttle    
float32 u_plant_des_steering   # wheel?

comm_pkg/VehicleState vehicle_state

# param log
float32 relax_v
float32 throttlegain
float32 k_stan_p_gas
float32 k_stan_lenk
float32 k_stan_vor
float32 look_a_head_in_spline
float32 rate_limit_steering
float32 rate_limit_throttle_lower
float32 rate_limit_throttle_upper
float32 v_max
string map_name
string control_setup

