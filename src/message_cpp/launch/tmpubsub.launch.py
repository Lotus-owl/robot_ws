#tmpubsub.launch.py
import os
from ament_index_python import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    param_dir=LaunchConfiguration('param_dir', default=os.path.join(
        get_package_share_directory('message_cpp'), 'param', 'turtlesim.yaml'
    )),
    return LaunchDescription([
        Node(package='message_cpp',
             executable='mpub',
             output='screen', ),

        Node(package='message_cpp',
             executable='tpub',
             output='screen', ),
        
        Node(package='message_cpp',
             executable='msub',
             output='screen', ),
        
        Node(package='message_cpp',
             executable='msub2',
             output='screen', ),
        
        Node(package='message_cpp',
             executable='mtsub',
             output='screen', ),
        
        Node(package='turtlesim',
             executable='turtlesim_node',
             output='screen',
             parameters=[param_dir])
    ])
