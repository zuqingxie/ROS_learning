FROM ros:foxy

SHELL ["/bin/bash", "-c"]

WORKDIR /workspace
RUN mkdir src
COPY . ./src/comm_pkg

RUN source /opt/ros/foxy/setup.bash && colcon build --merge-install