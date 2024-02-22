from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    return LaunchDescription(
        [Node(
            package = 'discern',
            executable = 'discern_node',
            name = 'discern_fun'
        )]
    )